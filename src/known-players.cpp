#include <matdash.hpp>

// defines add_hook to use minhook
#include <matdash/minhook.hpp>

// lets you use mod_main
#include <matdash/boilerplate.hpp>
#include <stdio.h>
#include "json.hpp"
#include <random>

#include <gd.h>

using namespace gd;
using namespace cocos2d;

//#define USE_WIN32_CONSOLE
#include "ModToolbox.hpp"

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET

constexpr const char* JSON_STRING = R"JSON(
[
    [ "AeonAir", 109, 29, 3, 0 ],
    [ "Colon", 60, 18, 10, 1 ],
    [ "Cool", 37, 20, 17, 1 ],
    [ "Cyclic", 30, 3, 12, 0 ],
    [ "DanZmeN", 104, 34, 12, 1 ],
    [ "envylol", 73, 20, 1, 1],
    [ "EVW", 28, 12, 9, 0 ],
    [ "Flub", 25, 3, 12, 1 ],
    [ "GD Flaaroni", 62, 12, 15, 0 ],
    [ "Jayuff", 22, 19, 11, 1 ],
    [ "Jeyzor", 99, 24, 25, 1 ],
    [ "Juniper", 98, 40, 12, 1 ],
    [ "Knobbelboy", 37, 10, 14, 0 ],
    [ "Knots", 50, 40, 3, 1 ],
    [ "KrmaL", 30, 9, 12, 1 ],
    [ "lemoncak3", 107, 11, 12, 0 ],
    [ "Lemons", 93, 7, 11, 1 ],
    [ "Nexus", 35, 9, 12, 1 ],
    [ "Michigun", 22, 15, 12, 1 ],
    [ "MiKhaXx", 11, 1, 15, 0 ],
    [ "mulpan", 90, 2, 12, 1 ],
    [ "npesta", 30, 2, 12, 0 ],
    [ "Norcda Childa", 53, 37, 12, 1 ],
    [ "OmegaFalcon", 11, 22, 4, 1 ],
    [ "Partition", 3, 4, 3, 0 ],
    [ "RedHuseey", 98, 9, 12, 0 ],
    [ "Riot", 35, 7, 3, 1 ],
    [ "Smiffy777", 115, 29, 14, 1 ],
    [ "SpKale", 51, 41, 12, 1 ],
    [ "SrGuillester", 23, 12, 15, 1 ],
    [ "Technical", 48, 0, 13, 0 ],
    [ "TheRealSdSlAyEr", 74, 3, 12, 1 ],
    [ "TriAxis", 51, 18, 12, 1 ],
    [ "TrusTa", 30, 7, 3, 1 ],
    [ "ViPriN", 133, 11, 13, 1 ],
    [ "Wulzy", 44, 29, 11, 0 ],
    [ "XShadowWizardX", 115, 12, 7, 1 ],
    [ "FunnyGame", 13, 18, 9, 0 ],
    [ "Zobros", 36, 12, 15, 1 ],
    [ "ZenthicAlpha", 41, 12, 3, 1 ],
    [ "Alkali", 4, 18, 8, 1 ],
    [ "Danolex", 46, 3, 11, 1 ],
    [ "Cirtrax", 93, 18, 41, 0 ],
    [ "CastriX", 120, 6, 12, 1 ]
]
)JSON";

static nlohmann::json cubes = nlohmann::json::parse(JSON_STRING);

int randomInt(int min, int max) {
	static std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

void MenuGameLayer_resetPlayer(CCNode* self)
{
	matdash::orig<&MenuGameLayer_resetPlayer>(self);
	
	auto player = MBO(gd::PlayerObject*, self, 300);
	player->toggleFlyMode(false);
	player->toggleRollMode(false);
	player->toggleBirdMode(false);
	player->toggleDartMode(false);
	player->toggleRobotMode(false);
	player->toggleSpiderMode(false);
	
	static int norepeat = 0;
	int randomIcon = randomInt(0, cubes.size() - 1);
	
	while(norepeat == randomIcon)
		randomIcon = randomInt(0, cubes.size() - 1);
	
	norepeat = randomIcon;
	
//	printf("icon chosen: %d\n", randomIcon);
	
	try //nlohmann json will throw
	{
		int iconID = cubes[randomIcon][1].template get<int>();
		player->updatePlayerFrame(iconID);
	
		auto gm = GameManager::sharedState();
	
		int color1 = cubes[randomIcon][2].template get<int>();
		player->setColor(gm->colorForIdx(color1));
	
		int color2 = cubes[randomIcon][3].template get<int>();
		player->setSecondColor(gm->colorForIdx(color2));
	
		bool glow = static_cast<bool>(cubes[randomIcon][4].template get<int>());
		if(glow)
		{
			player->updateGlowColor();
			player->updateGlow();
			player->m_iconSpriteWhitener->setVisible(true); //gd.h wrong offset
		}
		else
			player->m_iconSpriteWhitener->setVisible(false);
		
		//printf("glow: %d\n", glow);
	
	} catch(nlohmann::json::exception& e) {
		printf("something happened %s\n", e.what()); //leave in release
	}
	
}

bool MenuGameLayer_init(CCNode* self)
{
	if(!matdash::orig<&MenuGameLayer_init>(self)) return false;
	MenuGameLayer_resetPlayer(self);
	return true;
}


void mod_main(HMODULE) {
	
	//if(AllocConsole()) {
	//	freopen("CONOUT$", "wt", stdout);
	//	freopen("CONIN$", "rt", stdin);
	//	freopen("CONOUT$", "w", stderr);
	//	std::ios::sync_with_stdio(1);
	//}

	matdash::add_hook<&MenuGameLayer_resetPlayer>(base + 0x18f4b0);
	matdash::add_hook<&MenuGameLayer_init>(base + 0x18e770);
}