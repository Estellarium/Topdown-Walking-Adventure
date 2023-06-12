#include "Objects.h"
#include "Constants.h"
#include "Tiles.h"
extern tile* MapC(int, int);

//Core object classes

Object::Object(int iXPos, int iYPos, MapOfObjects* objs) {
	xPos = iXPos, yPos = iYPos;
	objMap = objs;
	tile* next = MapC(xPos, yPos);
	bg.str("");
	fg.str("");
	bg = next->getBackgroundColor();
	fg = next->getInverseBackgroundColor();
	(*objs)[coords{ xPos, yPos }] = this;
}
void Object::die() {
	dead = true;
}


Entity::Entity(int iXPos, int iYPos, MapOfObjects* objMap) : Object(iXPos, iYPos, objMap) {}
void Entity::update(int milisseconds) { timeElapsed += milisseconds; };


Pawn::Pawn(int initX, int initY, MapOfObjects* objMap) : Entity(initX, initY, objMap) {
	symbol = '?';
	hp = maxHP;
}
void Pawn::update(int milisseconds) {
	Entity::update(milisseconds);
	if (invincible) {
		curIFrames -= milisseconds;
		if (curIFrames <= 0) {
			invincible = false;
			curIFrames = iFrames;
			tile* next = MapC(xPos, yPos);
			bg.str("");
			fg.str("");
			bg = next->getBackgroundColor();
			fg = next->getInverseBackgroundColor();
		}
	}
};
void Pawn::damage(int damage) {
	if (!invincible) {
		hp -= damage;
		if (hp <= 0) {
		}
		else {
			invincible = true;
		}
	}
}
void Pawn::colorize(std::stringstream color) {
	fg.str("");
	fg << color.str();
}
std::stringstream Pawn::getRender() {
	if (invincible) {
		std::stringstream temp;
		temp << bg.str();
		bg.str("");
		bg << fg.str();
		fg.str("");
		fg << temp.str();
		return GameObject::getRender();
	}
	else {
		return GameObject::getRender();
	}
}
void Pawn::move(coords to) {
	if (to.x == 0 && to.y == 0) return;
	int nextX = xPos + to.x;
	int nextY = yPos + to.y;
	tile* next = MapC(nextX, nextY);
	if (!dynamic_cast<IBlocking*>(next)->isBlocking()) {
		if (objMap->find(coords{ nextX, nextY }) != objMap->end()) {
			Object* obj = (*objMap)[coords{ nextX, nextY }];
			IBlocking* bObj = dynamic_cast<IBlocking*>(obj);
			bool implementsBlock = bObj != nullptr;
			if (!implementsBlock || !bObj->isBlocking())
			{
				(*objMap)[{ xPos, yPos }] = nullptr;
				xPos = nextX;
				yPos = nextY;
				(*objMap)[{ xPos, yPos }] = this;
				if (obj != nullptr)
				obj->onOverlap(this);
			}
			else {
				if (obj != nullptr)
				obj->onCollision(this);
				whenICollide();
			}
		}
		else {
			(*objMap)[{ xPos, yPos }] = nullptr;
			xPos = nextX;
			yPos = nextY;
			(*objMap)[{ xPos, yPos }] = this;
			bg.str("");
			fg.str("");
			bg = next->getBackgroundColor();
			fg = next->getInverseBackgroundColor();
			next->onOverlap(this);
		}
	}
	else {
		next->onCollision(this);
		whenICollide();
	}
};
void Pawn::whenICollide() {
	//PlaySound(L"Sound/SND_Collision.wav", NULL, SND_ASYNC);
}


coords Wanderer::inputDirection() {
	coords ret;
	ret.x = rand() % 3 - 1;
	ret.y = rand() % 3 - 1;
	if (ret.x * ret.x != 0) ret.y = 0;
	return ret;
}
Wanderer::Wanderer(int initX, int initY, MapOfObjects* objMap) : Pawn(initX, initY, objMap) {
	defaultSymbol = objectSigils::sWANDER;
	symbol = defaultSymbol;
	timeToMove = 250;
};
void Wanderer::update(int milisseconds) {
	Pawn::update(milisseconds);

	while (timeElapsed >= (timeToMove / moveSpeed)) {
		if (hasMoved) {
			desiredDirection = inputDirection();
			if (desiredDirection.x != 0)
				symbol = desiredDirection.x > 0 ? '>' : '<';
			else if (desiredDirection.y != 0)
				symbol = desiredDirection.y > 0 ? 'v' : '^';
			else symbol = defaultSymbol;
			hasMoved = false;
		}
		else {
			move(desiredDirection);
			symbol = defaultSymbol;
			hasMoved = true;
		}
		timeElapsed -= timeToMove / moveSpeed;
	}
};
void Wanderer::onCollision(GameObject* obj)  {
	if (Pawn* pawn = dynamic_cast<Pawn*>(obj)) {
		pawn->damage(5);
	}
}


bool Projectile::checkNext(int x, int y) {
	tile* next = MapC(x, y);
	if (dynamic_cast<IBlocking*>(next)->isBlocking()) {
		die();
		return false;
	}
	if (objMap->find(coords{ x, y }) != objMap->end()) {
		if ((*objMap)[{x, y}] != nullptr)
			(*objMap)[{x, y}]->onCollision(this);
		die();
		return false;
	}
	return true;
}
Projectile::Projectile(int initX, int initY, MapOfObjects* objs, coords dir) : Pawn(initX, initY, objs) {
	symbol = objectSigils::sSHOT;
	direction = dir;
	moveSpeed = 1;
	timeToMove = 125;
}
void Projectile::update(int milisseconds) {
	Pawn::update(milisseconds);

	while (timeElapsed >= (timeToMove / moveSpeed)) {
		if (checkNext(xPos + direction.x, yPos + direction.y)) {
			move(direction);
		}
		timeElapsed -= timeToMove / moveSpeed;
	}
};
void Projectile::whenICollide() {
	die();
}


coords Shooter::inputDirection() {
	coords ret;
	ret.x = rand() % 3 - 1;
	ret.y = rand() % 3 - 1;
	if (ret.x * ret.x != 0) ret.y = 0;
	return ret;
}
Shooter::Shooter(int initX, int initY, MapOfObjects* objMap) : Pawn(initX, initY, objMap) {
	symbol = objectSigils::sSHOOT;
	timeToMove = 250;
};
void Shooter::update(int milisseconds) {
	Pawn::update(milisseconds);

	while (timeElapsed >= (timeToMove / moveSpeed)) {
		if (hasMoved) {
			desiredDirection = inputDirection();
			if (desiredDirection.x != 0)
				symbol = desiredDirection.x > 0 ? '>' : '<';
			else if (desiredDirection.y != 0)
				symbol = desiredDirection.y > 0 ? 'v' : '^';
			else symbol = objectSigils::sSHOOT;
			hasMoved = false;
		}
		else {
			if (rand() % 10 > 7) {
				move(desiredDirection);
				symbol = objectSigils::sSHOOT;
				hasMoved = true;
			}
			else {
			if (desiredDirection.x != 0 || desiredDirection.y != 0) {
				tile* next = MapC(xPos + desiredDirection.x, yPos + desiredDirection.y);
				if (!dynamic_cast<IBlocking*>(next)->isBlocking() &&
					objMap->find(coords{ xPos + desiredDirection.x, 
					yPos + desiredDirection.y }) == objMap->end())
				{
					Projectile* p = new Projectile(xPos + desiredDirection.x,
					yPos + desiredDirection.y, objMap, desiredDirection);
				}
			}
			symbol = objectSigils::sSHOOT;
			}
		}
		timeElapsed -= timeToMove / moveSpeed;
	}
};


Patroller::Patroller(int initX, int initY, MapOfObjects* objMap, coords dir) : Wanderer(initX, initY, objMap) {
	moveDir = dir;
	defaultSymbol = objectSigils::sPATROL;
	symbol = defaultSymbol;
	timeToMove = 125;
};
void Patroller::whenICollide()  {
	moveDir.x = -moveDir.x;
	moveDir.y = -moveDir.y;
}


