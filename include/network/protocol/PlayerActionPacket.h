#pragma once

#include "../../util/ActorRuntimeID.h"
#include "Packet.h"

struct PlayerActionPacket : Packet {
	enum Action : uint32_t;

	/**
	 * Block position for some actions
	 */
	union {
		struct {
			int32_t x = 0, y = 0, z = 0;
		};
		BlockPos blockPos;
	};
	/**
	 * Block face for some actions
	 */
	uint32_t face = 0;
	/**
	 * Action
	 * @see PlayerActionPacket::Action
	 */
	Action action;
	/**
	 * Player Runtime ID
	 */
	ActorRuntimeID rid;

	PlayerActionPacket(ActorRuntimeID rid, Action action) : rid(rid), action(action) {}

	PlayerActionPacket(const PlayerActionPacket &other) : rid(other.rid), blockPos(other.blockPos), face(other.face), action(other.action) {}

	enum Action : uint32_t {
		StartBreak = 0,
		AbortBreak = 1,
		StopBreak = 2,
		GetUpdatedBlock = 3,
		DropItem = 4,
		StartSleeping = 5,
		StopSleeping = 6,
		Respawn = 7,
		Jump = 8,
		StartSprinting = 9,
		StopSprinting = 10,
		StartSneaking = 11,
		StopSneaking = 12,
		RequestDimensionChange = 13,
		DimensionChangeAck = 14,
		StartGlide = 15,
		StopGlide = 16,
		BuildDenied = 17,
		ContinueBreak = 18,
		ChangeSkin = 19,
		SetEnchantmentSeed = 20,
		StartSwimming = 21,
		StopSwimming = 22,
		StartSpinAttack = 23,
		StopSpinAttack = 24,
		InteractBlock = 25
	};

#include "VirtualTemplate.h"
};
