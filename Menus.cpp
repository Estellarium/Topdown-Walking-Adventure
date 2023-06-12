#include "Menus.h"
#include "Constants.h"
	
#define e getE()
	std::string MainMenu[windowHeight + 3] = {
	(h + h + h + h + h + h + h + h + h + h + e + h + h + h + h + e + h + h + h + h + e + h + h + h + h + h + h + h + e + h + h),
	(h + e + h + "THE" + h + h + h + h + h + h + h + e + h + h + h + h + h + h + h + h + h + h + e + h + g + h + h + h + h),
	(h + h + "LEGEND" + h + h + h + h + h + e + h + h + h + h + h + e + e + h + h + h + h + h + h + g + h + e + h),
	(h + h + h + "of" + h + h + h + e + h + h + h + h + h + h + h + h + h + h + h + h + h + h + h + g + h + g + g + h + h + e),
	(h + h + "ZEGEND" + h + h + h + h + h + a + a + a + a + a + a + a + a + h + h + e + h + g + g + h + h + h + h),
	(h + h + h + h + h + h + e + h + h + h + h + a + a + h + h + h + h + h + h + h + h + a + a + h + h + h + h + h + h + h + h),
	(h + h + e + h + h + h + h + e + h + a + a + h + h + h + h + a + a + a + a + h + h + a + a + h + h + h + h + h + h + d + d),
	(h + h + h + h + h + h + h + h + e + a + a + h + h + a + a + h + h + h + h + a + a + a + a + h + h + e + h + h + d + d + d),
	(h + h + h + h + h + e + h + e + h + a + a + h + h + a + a + h + h + h + e + h + h + a + a + h + e + h + h + d + d + d + d),
	(h + h + h + e + h + h + h + h + h + a + a + h + h + a + a + h + e + h + h + h + h + a + a + h + h + h + h + d + d + d + d),
	(h + h + h + h + h + h + h + h + h + a + a + h + h + h + h + a + a + a + a + a + a + a + a + h + h + h + d + d + d + d + d),
	(d + d + d + h + h + h + h + e + h + h + h + a + a + h + h + h + h + h + h + h + h + a + a + a + a + h + d + d + d + d + d),
	(d + d + d + d + h + h + h + h + h + h + h + h + h + a + a + a + a + a + a + h + h + h + h + h + h + d + d + d + d + d + d),
	(d + d + d + d + d + h + h + h + h + h + e + h + h + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c),
	(d + d + d + d + d + h + h + h + h + h + h + h + h + h + h + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c + c),
	(d + d + d + d + d + b + b + b + b + b + b + b + b + b + b + b + b + b + c + c + c + c + c + c + c + c + c + c + c + c + c),
	(d + d + d + d + d + f + f + b + b + b + b + b + b + b + b + b + b + b + b + d + d + c + c + c + c + c + c + c + c + c + c),
	(d + d + d + d + d + d + f + f + b + f + f + f + b + b + b + b + b + f + f + f + f + f + d + d + d + d + d + d + d + d + d),
	(d + d + d + d + d + d + f + f + f + f + f + f + f + b + b + f + f + f + f + f + f + f + f + f + d + d + d + d + d + d + d),
	(d + d + d + d + d + d + f + f + f + f + f + f + f + f + f + f + f + f + f + f + f + d + d + d + d + d + d + d + d + d + d)
	};
#undef e

//Unused/previous attempts

/*public:
	std::string[] getMainMenu() {
		for (int i = 0; i < windowHeight; i++) {
			mainMenu[i] = buildMainMenu[i];
		}
		return mainMenu;
	}*/






/*
std::string buildMainMenu[] = {
	"                               ",
	"   THE                    %    ",
	"  LEGEND                   %   ",
	"   of                   % %%   ",
	"  ZEGEND     ████████    %%    ",
	"           ██        ██        ",
	"         ██    ████  ██      ▒▒",
	"         ██  ██    ████     ▒▒▒",
	"         ██  ██      ██    ▒▒▒▒",
	"         ██  ██      ██    ▒▒▒▒",
	"         ██    ████████   ▒▒▒▒▒",
	"▒▒▒        ██        ████ ▒▒▒▒▒",
	"▒▒▒▒         ██████      ▒▒▒▒▒▒",
	"▒▒▒▒▒        ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	"▒▒▒▒▒          ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	"▒▒▒▒▒~~~~~~~~~~~~~▓▓▓▓▓▓▓▓▓▓▓▓▓",
	"▒▒▒▒▒░░~~~~~~~~~~~~▒▒▓▓▓▓▓▓▓▓▓▓",
	"▒▒▒▒▒▒░░~░░░~~~~~░░░░░▒▒▒▒▒▒▒▒▒",
	"▒▒▒▒▒▒░░░░░░░~~░░░░░░░░░▒▒▒▒▒▒▒",
	"▒▒▒▒▒▒░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒"

};*/
