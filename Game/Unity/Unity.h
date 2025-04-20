#pragma once
#include "Math.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <il2cpp.h>
#include <Memory.h>

#define MAX_STRING_LEN 128

namespace Unity
{
	class String;
	class Object;
	class Type;
	class Component;
	class GameObject;
	class Camera;
	class Transform;
	class RuntimeType;
	class RuntimeFieldInfo;
	class Material;
	class Renderer;
	class Shader;
	class GUI;
	class GUISkin;
	class GUIStyle;
	class GUIContent;
	class Event;
	class Physics;
	class Texture;
	class Sprite;
	class SpriteRenderer;
	class RigidBody;
	class CharacterController;
	class Collider;
	class Animator;
	class AnimationEvent;
	class AnimationClip;
	class RuntimeAnimatorController;
	class AnimatorControllerParameter;

#include "Enums.h"
#include "Structs.h"
#include "Methods.h"
#include "Bundles.h"

	class Time {
	public:
		static float GetTime();
	};

	class Object {
	public:
		static void DontDestroyOnLoad(Object* target);
		static List<Object*>* FindObjectsOfType(Type* type);
		static Object* FindObjectOfType(Type* type);
		static Type* GetType(uintptr_t object);
	};

	class Shader : public Object {
	public:
		static Shader* Find(String name);
	};

	class Material : public Object {
	public:
		Shader* GetShader();
		void SetShader(Shader* value);
		void SetColor(String name, Color value);
		void SetInt(String name, int value);
		static void CreateWithShader(Material* self, Shader* shader);
		bool SetPass(int pass);
	public:
		static inline Material* material = nullptr;
	};

	class Sprite {
	public:
		Rect GetRect();
		Texture* GetTexture();
	};

	class Renderer {
	public:
		Material* GetMaterial();
		void SetMaterial(Material* mat);
	};

	class SpriteRenderer {
	public:
		Sprite* GetSprite();
	};

	class Component : public Object {
	public:
		Transform* GetTransform();
		Array<uintptr_t>* GetComponentsInChildren(Type* type);
		Component* GetComponent(Type* type);
	};

	class AnimatorControllerParameter
	{
	public:
		Unity::String* GetName();
	};

	class AnimationEvent
	{
	public:
		AnimatorStateInfo GetStateInfo();
	};

	class AnimationClip
	{
	public:
		Unity::Array<AnimationEvent*>* GetAnimationEvents(); // this is empty, it points to an array but the array is empty
	};

	class RuntimeAnimatorController
	{
	public:
		Unity::Array<AnimationClip*>* GetAnimationClips();	
	};

	class Animator
	{
	public:
		void Play(String* name, int layer, float time);
		void SetCullingMode(AnimatorCullingMode mode);
		void SetBool(String* name, bool value);
		void SetTrigger(String* name);
		int StringToHash(String* name);
		RuntimeAnimatorController* GetAnimController();
		Unity::Array<AnimatorControllerParameter*>* GetParameters();
	};

	class Transform : public Component {
	public:
		void SetPosition(Vector3 value);
		void LookAt(Vector3 value);
		Vector3 GetForward();
		Vector3 GetUp();
		Vector3 GetRight();
		Vector3 GetPosition();
	};

	class GameObject : public Object {
	public:
		static void InternalCreateGameObject(GameObject* self, String name);
		Component* InternalAddComponentWithType(Type* componentType);
	};

	class Camera : public Component {
	public:

		static inline Vector3 Location = {};
		static inline Matrix4x4 ViewMatrix = {};

		static Camera* GetMain();
		Vector3 GetLocation();
		Matrix4x4 GetViewMatrix();
		Vector2 WorldToScreen(Vector3 world_pos);
	};

	class RigidBody : public Component
	{
	public:
		void SetVelocity(Vector3 value);
		void SetRotation(Vector4 value);
		void SetisKinematic(bool value);
		void SetDetectCollisions(bool value);
		Vector4 GetRotation();
	};

	class Collider : public Component
	{
	public:
		RigidBody* GetAttachedRigidbody();
		void SetEnabled(bool value);
	};

	class CharacterController : public Collider
	{
	public:
		void SetDetectCollisions(bool value);
	};

	class Screen {
	public:
		static int GetWidth();
		static int GetHeight();
	};

	class GL {
	public:
		static void PushMatrix();
		static void PopMatrix();
		static void Begin(int mode);
		static void GLColor(Color color);
		static void Vertex(Vector3 value);
		static void End();
	};

	class GUIContent {
	public:
		static GUIContent* Temp(String* t);
	};

	class GUIStyle {
	public:
		Vector2 CalcSize(GUIContent* content);
		void SetAlignment(int anchor);
		void SetFontSize(int size);

	};

	class GUISkin {
	public:

	public:
		static inline GUIStyle* label = 0;
	};

	class GUI {
	public:
		static GUISkin* GetSkin();
		static void DrawTexture(Rect pos, Texture* texture);
		static void SetColor(Color color);
		static void Label(Rect pos, GUIContent* content, GUIStyle* style);
		static void Box(Rect pos, GUIContent* content, GUIStyle* style);
		static float HorizontalSlider(Rect position, float value, float leftValue, float rightValue);
		static bool Button(Rect* position, GUIContent* content, GUIStyle* style);
		static void BeginGroup(Rect* position, GUIContent* content, GUIStyle* style);
		static void EndGroup();
	};

	class Event {
	public:
		EventType GetType();
		static Event* GetCurrent();
		Vector2 GetMousePosition();
	};
}
