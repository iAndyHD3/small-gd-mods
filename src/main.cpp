#include <matdash.hpp>

// defines add_hook to use minhook
#include <matdash/minhook.hpp>

// lets you use mod_main
#include <matdash/boilerplate.hpp>

#include <gd.h>

using namespace gd;
using namespace cocos2d;

//#define USE_WIN32_CONSOLE
#include "ModToolbox.hpp"

void MenuLayer_updateUserProfileButton(CCNode* self)
{
	matdash::orig<&MenuLayer_updateUserProfileButton>(self);
	int count = self->getChildrenCount();
	for(int i = 0; i < count; i++)
	{
		auto node = (CCNode*)self->getChildren()->objectAtIndex(i);
		if(auto menu = dynamic_cast<CCMenu*>(node))
		{
			int menuCount = menu->getChildrenCount();
			for(int j = 0; j <	menuCount; j++)
			{
				auto button = (CCMenuItemSpriteExtra*)menu->getChildren()->objectAtIndex(j);
				auto spr = (CCSprite*)button->getChildren()->objectAtIndex(0);
				if(strcmp(ModToolbox::getTextureNameForSpriteFrame(spr), "GJ_profileButton_001.png") == 0) 
				{
					auto GM = GameManager::sharedState();
					auto m_pProfileIconSprite = SimplePlayer::create(0);
					m_pProfileIconSprite->updatePlayerFrame(ModToolbox::frameForIcon(GM->getPlayerIconType()), GM->getPlayerIconType());
					m_pProfileIconSprite->setColor(GM->colorForIdx(GM->getPlayerColor()));
					m_pProfileIconSprite->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
					m_pProfileIconSprite->setGlowOutline(GM->getPlayerGlow());
					spr->addChild(m_pProfileIconSprite);
					spr->setDisplayFrame(m_pProfileIconSprite->displayFrame());
					return;
				}
			}
		}
	}
}


void mod_main(HMODULE) {
	
	//if(AllocConsole()) {
	//	freopen("CONOUT$", "wt", stdout);
	//	freopen("CONIN$", "rt", stdin);
	//	freopen("CONOUT$", "w", stderr);
	//	std::ios::sync_with_stdio(1);
	//}

	matdash::add_hook<&MenuLayer_updateUserProfileButton>(base + 0x191700);
}