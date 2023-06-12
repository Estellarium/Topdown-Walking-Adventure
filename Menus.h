#pragma once
#include <string>
#include "Constants.h"

	static const char star = 197;
	static const char forest = 178;
	static const std::string a = "\033[48;2;99;155;255m \033[0m";//azure
	static const std::string b = "\033[48;2;0;88;208;38;2;99;155;255m~\033[0m";//blue
	static const std::string c = "\033[48;2;137;58;0m \033[0m";//caramel
	static const std::string d = "\033[48;2;78;33;0m \033[0m";//dark caramel
	static std::string getE() {
		int r = rand() % 100;
		return (r < 33 ? "*" :
				r < 66 ? "." :
				r < 80 ? "+" :
				std::string(1, star));
				};//estelar
	static const std::string f = "\033[48;2;11;51;11;38;2;31;75;31m" + std::string(1, forest) + "\033[0m";//forest
	static const std::string g = "\033[48;2;255;255;255;38;2;191;191;191m%\033[0m";//gray
	static const std::string h = " ";//hollow
	//char ░ = 176;
	//char ▒ = 177;
	//char ▓ = 178;
	//char █ = 219;

	extern std::string MainMenu[windowHeight + 3];