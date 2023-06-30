#include <matdash.hpp>

// defines add_hook to use minhook
#include <matdash/minhook.hpp>

// lets you use mod_main
#include <matdash/boilerplate.hpp>

#include <gd.h>

using namespace gd;
using namespace cocos2d;

//#define USE_WIN32_CONSOLE

GJGameLevel* BetterInfo::getLevelFromSaved(int levelID) {
        return static_cast<GJGameLevel*>(GameLevelManager::sharedState()->m_onlineLevels->objectForKey(std::to_string(levelID)));
}


matdash::cc::c_decl<CCLayer*> MenuGameLayer_create()
{
	auto level = GameLevelManager::sharedState()->getMainLevel(21, false);
	return PlayLayer::create(level);
}

void mod_main(HMODULE) {
	
	//if(AllocConsole()) {
	//	freopen("CONOUT$", "wt", stdout);
	//	freopen("CONIN$", "rt", stdin);
	//	freopen("CONOUT$", "w", stderr);
	//	std::ios::sync_with_stdio(1);
	//}

	matdash::add_hook<&MenuGameLayer_create>(base + 0x18e6d0);
}