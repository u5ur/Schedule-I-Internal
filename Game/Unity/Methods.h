#pragma once

namespace Methods
{
	inline auto CalcSize = reinterpret_cast<void(*)(GUIStyle*, GUIContent*, Vector2*)>(0);
	inline auto get_mousePosition_Injected = reinterpret_cast<void(*)(Event*, Vector2*)>(0);
	inline auto Box = reinterpret_cast<void(*)(Rect, GUIContent*, GUIStyle*)>(0);
	inline auto HorizontalSlider = reinterpret_cast<float(*)(Rect, float, float, float)>(0);
	inline auto Button = reinterpret_cast<bool(*)(Rect*, GUIContent*, GUIStyle*)>(0);
	inline auto BeginGroup = reinterpret_cast<bool(*)(Rect*, GUIContent*, GUIStyle*)>(0);
	inline auto EndGroup = reinterpret_cast<void(*)()>(0);
	inline auto get_Texture = reinterpret_cast<Texture*(*)(Sprite*)>(0);
	inline auto get_Rect = reinterpret_cast<Unity::Rect(*)(Sprite*)>(0);
	inline auto DrawTexture = reinterpret_cast<void(*)(Unity::Rect, Texture*)>(0);
	inline auto Raycast = reinterpret_cast<bool(*)(Unity::Ray, float, int, Unity::QueryTriggerInteraction)>(0);
	inline auto LoadPixelMatrix = reinterpret_cast<void(*)(float, float, float, float)>(0);
	inline auto Contains = reinterpret_cast<bool(*)(String*, String)>(0);
	inline auto FindObjectsOfType = reinterpret_cast<List<Object*>*(*)(Type*)>(0);
	inline auto Internal_CreateGameObject = reinterpret_cast<void(*)(Object*, String)>(0);
	inline auto Internal_AddComponentWithType = reinterpret_cast<Component * (*)(GameObject*, Type*)>(0);
	inline auto DontDestroyOnLoad = reinterpret_cast<void(*)(Object*)>(0);
	inline auto get_time = reinterpret_cast<float(*)()>(0);
	inline auto FindObjectOfType = reinterpret_cast<Object * (*)(Type*)>(0);
	inline auto get_main = reinterpret_cast<Camera * (*)()>(0);
	inline auto get_position = reinterpret_cast<Vector3(*)(Transform*)>(0);
	inline auto get_right = reinterpret_cast<Vector3(*)(Transform*)>(0);
	inline auto get_up = reinterpret_cast<Vector3(*)(Transform*)>(0);
	inline auto get_forward = reinterpret_cast<Vector3(*)(Transform*)>(0);
	inline auto get_transform = reinterpret_cast<Transform * (*)(Component*)>(0);
	inline auto GetType = reinterpret_cast<Type * (*)(uintptr_t)>(0);
	inline auto get_FullNameOrDefault = reinterpret_cast<String * (*)(Type*)>(0);
	inline auto get_Name = reinterpret_cast<String * (*)(RuntimeFieldInfo*)>(0);
	inline auto get_FieldType = reinterpret_cast<Type * (*)(RuntimeFieldInfo*)>(0);
	inline auto GetFieldOffset = reinterpret_cast<int(*)(RuntimeFieldInfo*)>(0);
	inline auto GetComponentsInChildren = reinterpret_cast<Array<uintptr_t>*(*)(Component*, Type*)>(0);
	inline auto GetComponent = reinterpret_cast<Component * (*)(Component*, Type*)>(0);
	inline auto get_material = reinterpret_cast<Material * (*)(Renderer*)>(0);
	inline auto set_material = reinterpret_cast<void(*)(Renderer*, Material*)>(0);
	inline auto get_isVisible = reinterpret_cast<bool(*)(Renderer*)>(0);
	inline auto get_shader = reinterpret_cast<Shader * (*)(Material*)>(0);
	inline auto ShaderFind = reinterpret_cast<Shader * (*)(String)>(0);
	inline auto set_shader = reinterpret_cast<void(*)(Material*, Shader*)>(0);
	inline auto SetColor = reinterpret_cast<void(*)(Material*, String, Color)>(0);
	inline auto SetInt = reinterpret_cast<void(*)(Material*, String, int)>(0);
	inline auto PushMatrix = reinterpret_cast<void(*)()>(0);
	inline auto PopMatrix = reinterpret_cast<void(*)()>(0);
	inline auto Begin = reinterpret_cast<void(*)(int)>(0);
	inline auto GLColor = reinterpret_cast<void(*)(Color)>(0);
	inline auto Vertex = reinterpret_cast<void(*)(Vector3)>(0);
	inline auto End = reinterpret_cast<void(*)()>(0);
	inline auto CreateWithShader = reinterpret_cast<void(*)(Material*, Shader*)>(0);
	inline auto SetPass = reinterpret_cast<bool(*)(Material*, int)>(0);
	inline auto get_width = reinterpret_cast<int(*)()>(0);
	inline auto get_height = reinterpret_cast<int(*)()>(0);
	inline auto get_skin = reinterpret_cast<GUISkin * (*)()>(0);
	inline auto set_alignment = reinterpret_cast<void(*)(GUIStyle*, int)>(0);
	inline auto set_color = reinterpret_cast<void(*)(Color)>(0);
	inline auto set_fontSize = reinterpret_cast<void(*)(GUIStyle*, int)>(0);
	inline auto Label = reinterpret_cast<void(*)(Rect, GUIContent*, GUIStyle*)>(0);
	inline auto content_temp = reinterpret_cast<GUIContent * (*)(String*)>(0);
	inline auto get_current = reinterpret_cast<Event * (*)()>(0);
	inline auto get_type = reinterpret_cast<EventType(*)(Event*)>(0);
	inline auto LoadFromFile = reinterpret_cast<uintptr_t(*)(String*, uint32_t, uint64_t)>(0);
	inline auto LoadAsset = reinterpret_cast<uintptr_t(*)(uintptr_t, String*, uintptr_t)>(0);
	inline auto get_sprite = reinterpret_cast<Sprite * (*)(SpriteRenderer*)>(0);
	inline auto set_velocity = reinterpret_cast<void(*)(RigidBody*, Vector3)>(0);
	inline auto set_rotation = reinterpret_cast<void(*)(RigidBody*, Vector4)>(0);
	inline auto get_rotation = reinterpret_cast<Vector4(*)(RigidBody*)>(0);
	inline auto set_isKinematic = reinterpret_cast<void(*)(RigidBody*, bool)>(0);
	inline auto set_detectCollisions = reinterpret_cast<void(*)(RigidBody*, bool)>(0);
	inline auto set_position = reinterpret_cast<void(*)(Transform*, Vector3)>(0);


	void Init();
}