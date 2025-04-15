#include "Render.h"

void Render::DrawSkeleton(ScheduleOne::AvatarFramework::Animation::AvatarAnimation* anim, Unity::Camera* cam, Unity::Color color)
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
