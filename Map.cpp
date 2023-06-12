#include "Map.h"
#include "Tiles.h"

int clamper(int val, int min, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

tile* MapC(int x, int y) { //Map Coordinate
	int outX, outY;
	outY = clamper(x, 0, mapX - 1);
	outX = clamper(y, 0, mapY - 1);
	return map[outX][outY];
};

void initializeMap() {
	memcpy(map, actualmap, sizeof(actualmap));
}

const tile* actualmap[mapX][mapY] = {
	{tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,wa,wa,wa,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr},
	{tr,tr,tr,tr,gr,gr,gr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,wa,wa,wa,wa,tr,tr,tr,tr,gr,gr,gr,gr,gr,gr,tr,tr,tr,tr,tr,tr,tr,tr},
	{tr,tr,gr,gr,gr,fw,tg,gr,tr,tr,gr,gr,gr,gr,gr,tr,tr,tr,tr,wa,wa,wa,tr,tr,gr,gr,gr,tg,tg,gr,gr,gr,gr,gr,gr,gr,tr,tr,tr,tr},
	{tr,tr,gr,gr,fw,tg,tg,tg,gr,gr,gr,gr,gr,gr,gr,gr,gr,tr,tr,wa,wa,wa,gr,gr,gr,gr,tg,tr,tr,tr,tr,gr,gr,gr,gr,fw,gr,tr,tr,tr},
	{tr,tr,gr,gr,gr,tg,tg,gr,gr,gr,gr,gr,fw,gr,gr,gr,gr,gr,tr,wa,wa,wa,gr,gr,gr,tr,tr,tr,tr,tr,tr,tr,gr,gr,fw,gr,tg,gr,tr,tr},
	{tr,tr,tr,tr,tr,tr,tr,tr,gr,gr,gr,gr,gr,fw,gr,gr,gr,gr,gr,br,br,br,gr,gr,tr,tr,tr,tr,tr,tr,tr,tr,gr,gr,tg,tg,tg,tg,tr,tr},
	{tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,gr,gr,gr,gr,gr,gr,gr,tr,wa,wa,wa,gr,gr,gr,tr,tr,tr,tr,tr,gr,gr,gr,gr,tg,tg,fw,tg,gr,tr},
	{tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,gr,gr,gr,gr,tr,tr,tr,wa,wa,wa,gr,gr,gr,gr,gr,gr,gr,gr,gr,gr,gr,gr,tr,tg,tg,fw,gr,tr},
	{tr,tr,tr,tr,gr,gr,gr,gr,gr,gr,gr,gr,gr,gr,wa,wa,wa,wa,wa,wa,wa,wa,wa,gr,gr,gr,gr,gr,gr,gr,gr,gr,fw,gr,gr,gr,gr,gr,gr,tr},
	{tr,tr,gr,gr,gr,gr,gr,fw,gr,gr,gr,gr,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,tr,tr,gr,gr,gr,fw,gr,gr,tr,gr,gr,tr},
	{tr,tr,gr,gr,gr,gr,tr,gr,fw,gr,gr,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,tr,tr,tr,gr,gr,gr,gr,gr,gr,tr,tr},
	{tr,tr,gr,gr,tr,tr,tr,tr,gr,gr,gr,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,ro,ro,ro,ro,gr,gr,gr,tr,tr,tr,tr},
	{tr,tr,tr,gr,gr,tr,tr,gr,gr,fw,gr,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,pa,as,pa,as,ro,as,as,as,as,as,ro,ro},
	{tr,tr,tr,gr,gr,gr,gr,gr,fw,tg,tg,tg,tr,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,wa,as,pa,as,pa,as,ro,as,as,as,as,as,as,ro},
	{tr,tr,tr,tr,gr,gr,tg,tg,tg,tg,tg,gr,gr,gr,gr,tr,wa,wa,wa,wa,wa,wa,wa,wa,as,as,as,as,as,as,as,as,as,as,as,as,as,as,as,ro},
	{tr,gr,gr,gr,tr,tr,gr,gr,gr,tr,gr,gr,gr,fw,gr,gr,tr,tr,tr,tr,ro,ro,ro,ro,ro,ro,ro,ro,ro,as,as,as,as,ro,ro,ro,ro,as,as,ro},
	{tr,tr,gr,gr,gr,tr,tr,gr,gr,gr,gr,gr,fw,gr,tr,tr,tr,tr,tr,tr,ro,as,as,sa,ca,sa,sa,sa,as,as,sa,as,as,as,as,as,ro,as,as,ro},
	{tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,ro,as,sa,sa,sa,sa,sa,ca,sa,sa,sa,sa,as,as,as,as,ro,as,as,ro},
	{tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,tr,ro,as,as,as,as,ro,ro,ro,ro,ro,ro,ro,ro,ro,as,as,as,as,as,ro},
	{wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,ro,as,as,as,as,ro,as,pa,as,pa,as,pa,as,pa,as,as,as,as,as,ro},
	{wl,fo,fo,fo,fo,fo,fo,wl,ch,ta,pl,fl,ch,ta,pl,fl,ch,ta,pl,wl,ro,as,as,as,as,ro,as,pa,as,pa,as,pa,as,pa,as,as,as,as,as,ro},
	{wl,fo,fl,fl,fl,fl,fl,wl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,wl,ro,as,as,as,as,as,as,as,as,as,as,as,as,as,as,as,ro,ro,ro,ro},
	{wl,fo,fl,pl,pl,fl,fl,fl,fl,fl,ch,ta,pl,fl,ch,ta,fl,fl,pl,wl,as,as,as,as,as,as,as,as,sa,as,as,as,as,as,as,as,as,as,as,ro},
	{wl,fo,fl,pl,pl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,as,as,as,as,sa,as,as,as,as,as,as,as,as,as,as,sa,as,as,as,ro},
	{wl,fo,fl,fl,fl,fl,fl,fl,ch,ta,fl,fl,ch,ta,pl,fl,ch,ta,fl,fl,as,as,as,ro,sa,sa,as,sa,as,ro,ro,ro,ro,ro,ro,ro,sa,as,as,ro},
	{wl,fo,fl,fl,pl,pl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,as,as,as,ro,sa,ca,sa,sa,sa,sa,sa,sa,sa,sa,sa,ro,ca,as,sa,ro},
	{wl,fo,fl,fl,pl,pl,fl,wl,pl,fl,ch,ta,pl,fl,ch,ta,pl,fl,pl,wl,as,as,as,ro,sa,sa,sa,sa,ca,sa,sa,sa,sa,ca,sa,ro,sa,sa,sa,ro},
	{wl,fo,fl,fl,fl,fl,fl,wl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,fl,wl,as,as,as,ro,ro,ro,ro,ro,ro,ro,sa,sa,sa,sa,sa,sa,sa,sa,as,ro},
	{wl,wl,wl,fl,wl,wl,wl,wl,fl,wl,wl,wl,wl,wl,wl,wl,wl,fl,wl,wl,as,as,as,pa,as,pa,as,pa,as,as,sa,sa,sa,sa,sa,sa,sa,sa,as,ro},
	{wl,fl,fl,fl,fl,fl,pl,fl,fl,wl,cl,fl,fl,cl,cl,fl,wl,fl,wl,wl,as,as,as,pa,as,pa,as,pa,as,sa,sa,ca,sa,sa,sa,sa,sa,sa,ca,ro},
	{wl,fl,fl,fl,fl,fl,fl,fl,fl,wl,fl,fl,fl,fl,fl,fl,fl,fl,wl,wl,as,as,as,as,as,as,as,as,as,as,sa,ro,ro,ro,ro,ca,sa,sa,sa,ro},
	{wl,fl,fl,fl,fl,fl,fl,fl,fl,wl,fl,fl,fl,fl,fl,fl,wl,fl,wl,wl,as,as,as,ro,ro,ro,ro,as,as,as,as,ro,sa,sa,sa,sa,sa,sa,sa,ro},
	{wl,fl,pl,fl,fl,fl,fl,fl,fl,wl,cl,cl,cl,fl,fl,cl,wl,fl,wl,wl,as,as,as,as,as,as,ro,as,as,sa,sa,ro,ro,ro,ro,ca,sa,sa,sa,ro},
	{wl,fl,wl,wl,wl,fl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,fl,wl,wl,as,as,as,as,as,as,ro,as,as,sa,sa,sa,sa,sa,sa,sa,sa,ro,sa,ro},
	{wl,fl,fl,fl,pl,fl,fl,fl,fl,fl,fl,fl,fl,fl,pl,fl,fl,fl,fl,wl,ro,as,pa,as,as,as,as,as,as,as,sa,sa,sa,ca,sa,sa,sa,ro,sa,ro},
	{wl,fl,fl,fl,fl,fl,fl,fl,fl,pl,fl,fl,fl,fl,fl,fl,fl,fl,fl,wl,ro,as,pa,as,as,as,as,as,sa,as,sa,sa,sa,sa,sa,sa,sa,ro,sa,ro},
	{wl,wl,wl,fl,wl,wl,wl,wl,fl,wl,wl,wl,fl,wl,wl,wl,fl,wl,wl,wl,ro,ro,ro,ro,as,as,ro,as,as,as,as,ro,ro,ro,ro,sa,ca,ro,sa,ro},
	{wl,fl,fl,fl,fl,fl,wl,fl,fl,fl,wl,fl,fl,fl,fl,wl,fl,fl,fl,wl,ro,as,pa,as,pa,as,ro,as,pa,as,pa,as,pa,as,ro,sa,sa,sa,sa,ro},
	{wl,to,fl,to,fl,to,wl,fl,fl,fl,wl,fl,fl,fl,fl,wl,fl,fl,fl,wl,ro,as,pa,as,pa,as,ro,as,pa,as,pa,as,pa,as,ro,sa,sa,sa,ca,ro},
	{wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,wl,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro,ro}
};