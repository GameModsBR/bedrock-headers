#pragma once

#include "world/Block.h"
#include "../Mob.h"

struct EnderMan : Mob {
	// TODO: find types
	static EnderMan *SPEED_MODIFIER_ATTACKING;
	static EnderMan *SPEED_MODIFIER_ATTACKING_UUID;
	static EnderMan *mMayTake;
	static EnderMan *mMayTakeIsSetup;

	void _teleport();

	void setCarryingBlock(Block const &);

	Block *getCarryingBlock();

	bool canBeAffectedByArrow(MobEffectInstance const &);
};
