#include "Render.h"

void Render::helper::DrawSkeleton(ScheduleOne::AvatarFramework::Animation::AvatarAnimation* anim, Unity::Camera* cam, Unity::Color color)
{
	auto head_b = anim->GetBonePos(ScheduleOne::Bone::Head);
	auto spine4_b = anim->GetBonePos(ScheduleOne::Bone::Spine4);
	auto l_upperarm_b = anim->GetBonePos(ScheduleOne::Bone::L_UpperArm);
	auto l_forearm_b = anim->GetBonePos(ScheduleOne::Bone::L_Forearm);
	auto l_hand_b = anim->GetBonePos(ScheduleOne::Bone::L_Hand);
	auto r_upperarm_b = anim->GetBonePos(ScheduleOne::Bone::R_UpperArm);
	auto r_forearm_b = anim->GetBonePos(ScheduleOne::Bone::R_Forearm);
	auto r_hand_b = anim->GetBonePos(ScheduleOne::Bone::R_Hand);
	auto pelvis_b = anim->GetBonePos(ScheduleOne::Bone::Pelvis);
	auto l_hip_b = anim->GetBonePos(ScheduleOne::Bone::L_Hip);
	auto l_knee_b = anim->GetBonePos(ScheduleOne::Bone::L_Knee);
	auto l_foot_b = anim->GetBonePos(ScheduleOne::Bone::L_Foot);
	auto r_hip_b = anim->GetBonePos(ScheduleOne::Bone::R_Hip);
	auto r_knee_b = anim->GetBonePos(ScheduleOne::Bone::R_Knee);
	auto r_foot_b = anim->GetBonePos(ScheduleOne::Bone::R_Foot);
	auto r_toe_b = anim->GetBonePos(ScheduleOne::Bone::R_Toe);
	auto l_toe_b = anim->GetBonePos(ScheduleOne::Bone::L_Toe);

	Vector2 head = cam->WorldToScreen(head_b);
	Vector2 spine = cam->WorldToScreen(spine4_b);
	Vector2 l_upperarm = cam->WorldToScreen(l_upperarm_b);
	Vector2 l_forearm = cam->WorldToScreen(l_forearm_b);
	Vector2 l_hand = cam->WorldToScreen(l_hand_b);
	Vector2 r_upperarm = cam->WorldToScreen(r_upperarm_b);
	Vector2 r_forearm = cam->WorldToScreen(r_forearm_b);
	Vector2 r_hand = cam->WorldToScreen(r_hand_b);
	Vector2 pelvis = cam->WorldToScreen(pelvis_b);
	Vector2 l_hip = cam->WorldToScreen(l_hip_b);
	Vector2 l_knee = cam->WorldToScreen(l_knee_b);
	Vector2 l_foot = cam->WorldToScreen(l_foot_b);
	Vector2 r_hip = cam->WorldToScreen(r_hip_b);
	Vector2 r_knee = cam->WorldToScreen(r_knee_b);
	Vector2 r_foot = cam->WorldToScreen(r_foot_b);
	Vector2 r_toe = cam->WorldToScreen(r_toe_b);
	Vector2 l_toe = cam->WorldToScreen(l_toe_b);

	UI::DrawLine(head, spine, color);
	UI::DrawLine(spine, l_upperarm, color);
	UI::DrawLine(l_upperarm, l_forearm, color);
	UI::DrawLine(l_forearm, l_hand, color);
	UI::DrawLine(spine, r_upperarm, color);
	UI::DrawLine(r_upperarm, r_forearm, color);
	UI::DrawLine(r_forearm, r_hand, color);
	UI::DrawLine(spine, pelvis, color);
	UI::DrawLine(pelvis, l_hip, color);
	UI::DrawLine(l_hip, l_knee, color);
	UI::DrawLine(l_knee, l_foot, color);
	UI::DrawLine(pelvis, r_hip, color);
	UI::DrawLine(r_hip, r_knee, color);
	UI::DrawLine(r_knee, r_foot, color);
	UI::DrawLine(r_foot, r_toe, color);
	UI::DrawLine(l_foot, l_toe, color);
}

bool Render::helper::IsVisible(Unity::Camera* cam, Vector3 target_pos)
{
	Vector3 Direction = (target_pos - cam->Location);
	float dist = Direction.Magnitude() * 0.9f;
	return !Unity::Methods::Raycast(Unity::Ray(cam->Location, Direction), dist, -1, Unity::QueryTriggerInteraction::Ignore);
}

void Render::helper::UnlockAllDoors()
{
	auto TimedAccessZones = ScheduleOne::Map::TimedAccessZone::GetTimedAccessZones();
	if (!mem.IsValidPtr(TimedAccessZones)) return;

	auto Size = TimedAccessZones->GetSize();
	if (Size <= 0 || Size >= 100) return;

	for (int i = 0; i < Size; i++)
	{
		auto TimedAccessZone = TimedAccessZones->Get(i);
		if (!mem.IsValidPtr(TimedAccessZone)) continue;

		TimedAccessZone->SetOpenTime(0);
		TimedAccessZone->SetCloseTime(0);
	}
}

void Render::helper::SetDealerCardsFaceUp(ScheduleOne::Casino::BlackjackGameController* bj)
{
	if (!mem.IsValidPtr(bj)) return;

	auto DealerCards = bj->GetDealerCards();
	if (!mem.IsValidPtr(DealerCards)) return;

	auto Size = DealerCards->GetSize();
	if (Size <= 0 || Size >= 1000) return;

	for (int i = 0; i < Size; i++)
	{
		auto Card = DealerCards->Get(i);
		if (!mem.IsValidPtr(Card)) continue;

		Card->GetCardController()->SendCardFaceUp(Card->GetCardID(), true);
	}
}

void Render::helper::SetDeckCardsFaceUp(ScheduleOne::Casino::BlackjackGameController* bj)
{
	if (!mem.IsValidPtr(bj)) return;

	auto DeckCards = bj->GetPlayStack();
	if (!mem.IsValidPtr(DeckCards)) return;

	auto Size = DeckCards->GetSize();
	if (Size <= 0 || Size >= 1000) return;

	for (int i = 0; i < Size; i++)
	{
		auto Card = DeckCards->Get(i);
		if (!mem.IsValidPtr(Card)) continue;

		Card->GetCardController()->SendCardFaceUp(Card->GetCardID(), true);
	}
}

void Render::helper::SetPlayerCards(ScheduleOne::Casino::BlackjackGameController* bj)
{
	if (!mem.IsValidPtr(bj)) return;

	auto PlayerCards = bj->GetPlayerCards();
	if (!mem.IsValidPtr(PlayerCards)) return;

	auto Size = PlayerCards->GetSize();
	if (Size <= 0 || Size >= 1000) return;

	for (int i = 0; i < Size; i++)
	{
		auto Card = PlayerCards->Get(i);
		if (!mem.IsValidPtr(Card)) continue;

		auto Controller = Card->GetCardController();
		if (!mem.IsValidPtr(Controller)) continue;

		if (i == 0)
		{
			Controller->SetCardValue(Card->GetCardID(), ScheduleOne::Casino::ECardSuit::Hearts, ScheduleOne::Casino::ECardValue::King);
		}
		else if (i == 1)
		{
			Controller->SetCardValue(Card->GetCardID(), ScheduleOne::Casino::ECardSuit::Hearts, ScheduleOne::Casino::ECardValue::Ace);
		}
	}
}
