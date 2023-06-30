#ifndef __PLAYEROBJECT_H__
#define __PLAYEROBJECT_H__

#include <gd.h>

namespace gd
{

class GameObject;
class AnimatedSpriteDelegate;
class GJRobotSprite;
class GJSpiderSprite;
class HardStreak;
class GhostTrailEffect;

class GDH_DLL PlayerObject : public GameObject, public AnimatedSpriteDelegate
{
	// 1128
  public:
	PAD(0x14)
	bool m_unk480;
	cocos2d::CCNode* m_unk484;
	cocos2d::CCDictionary* m_collisionLog;
	cocos2d::CCDictionary* m_collisionLog1;
	PAD(0x20)
	bool m_unk4B0;
	cocos2d::CCSprite* m_unk4B4;
	PAD(0x1c)
	bool m_unk4D4;
	cocos2d::CCArray* m_particleSystems;
	bool m_unk4DC;
	bool m_isHidden;
	int m_hasGhostTrail;
	GhostTrailEffect* m_ghostTrail;
	void* m_unknown;
	cocos2d::CCSprite* m_iconSprite;
	cocos2d::CCSprite* m_iconSpriteSecondary;
	cocos2d::CCSprite* m_iconSpriteWhitener;
	cocos2d::CCSprite* m_iconGlow;
	cocos2d::CCSprite* m_vehicleSprite;
	cocos2d::CCSprite* m_vehicleSpriteSecondary;
	cocos2d::CCSprite* m_unk500;
	cocos2d::CCSprite* m_vehicleSpriteWhitener;
	cocos2d::CCSprite* m_vehicleGlow;
	cocos2d::CCMotionStreak* m_regularTrail;
	HardStreak* m_waveTrail;
	double m_xAccel;
	double m_jumpAccel;
	double m_gravity;
	double m_unknown20;
	bool m_unk538;
	bool m_unk539;
	bool m_unk53A;
	bool m_unk53B;
	bool m_isInPlayLayer;
	bool m_unk53D;
	bool m_unk53E;
	bool m_unk53F;
	PAD(0x10)
	double m_lastJumpTime;
	double m_unk558;
	PAD(0x24)
	float m_decelerationRate;
	PAD(0x14)
	GameObject* m_objectSnappedTo;
	PAD(0x8)
	GJRobotSprite* m_robotSprite;
	GJSpiderSprite* m_spiderSprite;
	bool m_unk5B0;
	cocos2d::CCParticleSystemQuad* m_unk5B4;
	cocos2d::CCParticleSystemQuad* m_unk5B8;
	cocos2d::CCParticleSystemQuad* m_unk5BC;
	cocos2d::CCParticleSystemQuad* m_unk5C0;
	cocos2d::CCParticleSystemQuad* m_unk5C4;
	cocos2d::CCParticleSystemQuad* m_unk5C8;
	cocos2d::CCParticleSystemQuad* m_unk5CC;
	PAD(0x4)
	cocos2d::CCParticleSystemQuad* m_unk5D4;
	cocos2d::CCParticleSystemQuad* m_unk5D8;
	PAD(0x20)
	bool m_unk5FC;
	bool m_unk5FD;
	bool m_isDropping;
	PAD(0x11)
	bool m_unk610;
	bool m_isHolding;
	bool m_hasJustHeld;
	bool m_isHolding2;
	bool m_hasJustHeld2;
	int m_unk618;
	float m_unk61C;
	int m_unk620;
	bool m_canRobotJump;
	double m_yAccel;
	bool m_isOnSlope;
	bool m_wasOnSlope;
	float m_unk634;
	bool m_isShip;
	bool m_isBird;
	bool m_isBall;
	bool m_isDart;
	bool m_isRobot;
	bool m_isSpider;
	bool m_isUpsideDown;
	PAD(1);
	bool m_isOnGround;
	bool m_isDashing;
	float m_vehicleSize;
	float m_playerSpeed;
	cocos2d::CCPoint m_unk64C;
	cocos2d::CCPoint m_lastPortalPos;
	cocos2d::CCLayer* m_unk65C;
	bool m_isSliding;
	bool m_isRising;
	bool m_isLocked;
	cocos2d::CCPoint m_lastGroundedPos;
	cocos2d::CCArray* m_touchingRings;
	GameObject* m_lastActivatedPortal;
	bool m_unk674;
	bool m_unk675;
	cocos2d::ccColor3B m_playerColor1;
	cocos2d::ccColor3B m_playerColor2;
	cocos2d::CCPoint m_position;
	bool m_unk684;
	bool m_unk685;
	double m_unk688;
	PAD(0x8)
	float m_groundHeight;
	float m_unk69C;
	PAD(0x4)
	float unk6A4[200];
	PAD(0x1c)

	virtual void setVisible(bool visible)
	{
		return reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1FA860)(this, visible);
	}
	void pushButton(int button)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, int)>(base + 0x1F4E40)(this, button);
	}
	void releaseButton(int button)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, int)>(base + 0x1F4F70)(this, button);
	}
	bool playerIsFalling()
	{
		return reinterpret_cast<bool(__thiscall*)(PlayerObject*)>(base + 0x1f5d60)(this);
	}
	void runRotateAction()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9bf0)(this);
	}
	void playBurstEffect()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f6790)(this);
	}
	void resetPlayerIcon()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1F65E0)(this);
	}
	void spiderTestJump(bool param1)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1ed360)(this, param1);
	}
	void incrementJumps()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9a20)(this);
	}
	void flipGravity(bool param1, bool param2)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool, bool)>(base + 0x1f59d0)(this, param1, param2);
	}
	void runNormalRotation()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9c50)(this);
	}
	void runBallRotation()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9d10)(this);
	}
	void runBallRotation2()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1E9E30)(this);
	}
	void activateStreak()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f9080)(this);
	}
	void toggleFlyMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F5E40)(this, active);
	}
	void toggleGlitter(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x20A0D0)(this, active);
	}
	void toggleRollMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F68E0)(this, active);
	}
	void toggleBirdMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F6050)(this, active);
	}
	void toggleDartMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F62C0)(this, active);
	}
	void toggleRobotMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F6A10)(this, active);
	}
	void toggleSpiderMode(bool active)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1F6CB0)(this, active);
	}

	void setSecondColor(cocos2d::_ccColor3B const& color)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, cocos2d::_ccColor3B const&)>(base + 0x1f7870)(this, color);
	}
	
	void updatePlayerFrame(int iconID)
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*, int)>(base + 0x1f7e40)(this, iconID);
	}
	
	void updateGlowColor()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f78e0)(this);
	}
	
	void updateGlow()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f9290)(this);
	}

	void updateSpecial()
	{
		reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e8ab0)(this);
	}

	static PlayerObject* create(int cubeFrame, int shipFrame, cocos2d::CCLayer* layer)
	{
		auto ret = reinterpret_cast<PlayerObject*(__fastcall*)(int, int, cocos2d::CCLayer*)>(base + 0x1e6cf0)(
			cubeFrame, shipFrame, layer);

		__asm add esp, 0x4
	}
};
} // namespace gd

#endif