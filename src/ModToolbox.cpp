#pragma once

#include "ModToolbox.hpp"

#include <Windows.h>
#include <gd.h>

using namespace cocos2d;
using namespace gd;

//general purpose class for helper functions that can be useful with any class at any moment
//(robtop - GameToolbox)

#define public_cast(value, member) [](auto* v) { \
	class FriendClass__; \
	using T = std::remove_pointer<decltype(v)>::type; \
	class FriendeeClass__: public T { \
	protected: \
		friend FriendClass__; \
	}; \
	class FriendClass__ { \
	public: \
		auto& get(FriendeeClass__* v) { return v->member; } \
	} c; \
	return c.get(reinterpret_cast<FriendeeClass__*>(v)); \
}(value)

const char* ModToolbox::getTextureNameForSpriteFrame(cocos2d::CCSprite* sprite_node) {
	
	auto* texture = sprite_node->getTexture();
	cocos2d::CCDictElement* el;
		
	auto* frame_cache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
	auto* cached_frames = public_cast(frame_cache, m_pSpriteFrames);
	const auto rect = sprite_node->getTextureRect();
	cocos2d::CCDICT_FOREACH(cached_frames, el) {
		auto* frame = static_cast<cocos2d::CCSpriteFrame*>(el->getObject());
		if (frame->getTexture() == texture && frame->getRect().equals(rect)) {
			return el->getStrKey();
		}
	}

	return "";
}

int ModToolbox::frameForIcon(IconType icon)
{
	auto GM = GameManager::sharedState();
	switch(icon)
	{
		default: return GM->getPlayerFrame();
		case IconType::kIconTypeShip: return GM->getPlayerShip();
		case IconType::kIconTypeBall: return GM->getPlayerBall();
		case IconType::kIconTypeUfo: return GM->getPlayerBird();
		case IconType::kIconTypeWave: return GM->getPlayerDart();
		case IconType::kIconTypeRobot: return GM->getPlayerRobot();
		case IconType::kIconTypeSpider: return GM->getPlayerSpider();
	}
}


const char* ModToolbox::getTextureNameForSprite(cocos2d::CCSprite* sprite_node)
{
	auto* texture = sprite_node->getTexture();

	auto* texture_cache = CCTextureCache::sharedTextureCache();
	auto* cached_textures = public_cast(texture_cache, m_pTextures);
	CCDictElement* el;
	CCDICT_FOREACH(cached_textures, el) {
		if (el->getObject() == texture) {
			return el->getStrKey();
		}
	}

	return "";
}

#undef public_cast