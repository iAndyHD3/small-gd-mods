#pragma once
#include <gd.h>
namespace cocos2d
{
	class CCSprite;
}
using namespace gd;

//general purpose class for helper functions that can be useful with any class at any moment
//(robtop - GameToolbox)

namespace ModToolbox
{
	const char* getTextureNameForSpriteFrame(cocos2d::CCSprite* sprite_node);
	const char* getTextureNameForSprite(cocos2d::CCSprite* sprite_node);
	int frameForIcon(IconType icon);
	const char* formattedTextureNameForSprite(cocos2d::CCSprite* sprite_node);
};
