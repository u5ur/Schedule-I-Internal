#include "Unity.h"

using namespace Unity;

void Methods::Init() {
	CalcSize = reinterpret_cast<void(*)(GUIStyle*, GUIContent*, Vector2*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUIStyle", "Internal_CalcSize_Injected", 2, "", "UnityEngine")));
	get_mousePosition_Injected = reinterpret_cast<void(*)(Event*, Vector2*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Event", "get_mousePosition_Injected", 2, "", "UnityEngine")));
	Box = reinterpret_cast<void(*)(Rect, GUIContent*, GUIStyle*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "Box", 3, "content", "UnityEngine", 2)));
	HorizontalSlider = reinterpret_cast<float(*)(Rect, float, float, float)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "HorizontalSlider", 4, "", "UnityEngine", 5)));
	Button = reinterpret_cast<bool(*)(Rect*, GUIContent*, GUIStyle*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "Button", 3, "content", "UnityEngine", 2)));
	BeginGroup = reinterpret_cast<bool(*)(Rect*, GUIContent*, GUIStyle*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "BeginGroup", 3, "content", "UnityEngine", 2)));
	EndGroup = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "EndGroup", 0, "", "UnityEngine")));
	Raycast = reinterpret_cast<bool(*)(Unity::Ray, float, int, Unity::QueryTriggerInteraction)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Physics", "Raycast", 4, "queryTriggerInteraction", "UnityEngine", 4)));
	LoadPixelMatrix = reinterpret_cast<void(*)(float, float, float, float)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "LoadPixelMatrix", 0, "", "UnityEngine")));
	Contains = reinterpret_cast<bool(*)(String*, String)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("String", "Contains", -1, "", "System")));
	FindObjectsOfType = reinterpret_cast<List<Object*>*(*)(Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Object", "FindObjectsOfType", 1, "type", "UnityEngine")));
	Internal_CreateGameObject = reinterpret_cast<void(*)(Object*, String)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GameObject", "Internal_CreateGameObject", 0, "", "UnityEngine")));
	Internal_AddComponentWithType = reinterpret_cast<Component * (*)(GameObject*, Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GameObject", "Internal_AddComponentWithType", 0, "", "UnityEngine")));
	DontDestroyOnLoad = reinterpret_cast<void(*)(Object*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Object", "DontDestroyOnLoad", 0, "", "UnityEngine")));
	get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Time", "get_time", 0, "", "UnityEngine")));
	LoadFromFile = reinterpret_cast<uintptr_t(*)(Unity::String*, uint32_t, uint64_t)>(il2cpp::ResolveICall("UnityEngine.AssetBundle::LoadFromFile_Internal(System.String,System.UInt32,System.UInt64)"));
	LoadAsset = reinterpret_cast<uintptr_t(*)(uintptr_t, Unity::String*, uintptr_t)>(il2cpp::ResolveICall("UnityEngine.AssetBundle::LoadAsset_Internal(System.String,System.Type)"));
	FindObjectOfType = reinterpret_cast<Object*(*)(Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Object", "FindObjectOfType", 1, "type", "UnityEngine")));
	get_main = reinterpret_cast<Camera*(*)()>(il2cpp::ResolveICall("UnityEngine.Camera::get_main()"));
	get_position = reinterpret_cast<Vector3(*)(Transform*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Transform", "get_position", 0, "", "UnityEngine")));
	get_transform = reinterpret_cast<Transform * (*)(Component*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Component", "get_transform", 0, "", "UnityEngine")));
	GetType = reinterpret_cast<Type * (*)(uintptr_t)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Object", "GetType", 0, "", "System")));
	get_FullNameOrDefault = reinterpret_cast<String * (*)(Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Type", "get_FullNameOrDefault", 0, "", "System")));
	get_Name = reinterpret_cast<String * (*)(RuntimeFieldInfo*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("RuntimeFieldInfo", "get_Name", 0, "", "System.Reflection")));
	get_FieldType = reinterpret_cast<Type * (*)(RuntimeFieldInfo*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("RuntimeFieldInfo", "get_FieldType", 0, "", "System.Reflection")));
	GetFieldOffset = reinterpret_cast<int(*)(RuntimeFieldInfo*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("RuntimeFieldInfo", "GetFieldOffset", 0, "", "System.Reflection")));
	GetComponentsInChildren = reinterpret_cast<List<uintptr_t>*(*)(Component*, Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Component", "GetComponentsInChildren", 0, "", "UnityEngine")));
	GetComponent = reinterpret_cast<Component * (*)(Component*, Type*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Component", "GetComponent", 0, "", "UnityEngine")));
	get_material = reinterpret_cast<Material * (*)(Renderer*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method(("Renderer"), ("get_material"), 0, (""), ("UnityEngine"))));
	set_material = reinterpret_cast<void(*)(Renderer*, Material*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method(("Renderer"), ("set_material"), 1, (""), ("UnityEngine"))));
	get_isVisible = reinterpret_cast<bool(*)(Renderer*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Renderer", "get_isVisible", 0, "", "UnityEngine")));
	get_shader = reinterpret_cast<Shader * (*)(Material*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "get_shader", -1, "", "UnityEngine")));
	ShaderFind = reinterpret_cast<Shader * (*)(String)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Shader", "Find", 1, "", "UnityEngine")));
	set_shader = reinterpret_cast<void(*)(Material*, Shader*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "set_shader", 0, "", "UnityEngine")));
	SetColor = reinterpret_cast<void(*)(Material*, String, Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "SetColor", 2, "", "UnityEngine")));
	SetInt = reinterpret_cast<void(*)(Material*, String, int)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "SetInt", 2, "", "UnityEngine")));
	PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "PushMatrix", 0, "", "UnityEngine")));
	PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "PopMatrix", 0, "", "UnityEngine")));
	Begin = reinterpret_cast<void(*)(int)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "Begin", 1, "", "UnityEngine")));
	GLColor = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "Color", 1, "", "UnityEngine")));
	Vertex = reinterpret_cast<void(*)(Vector3)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "Vertex", 1, "", "UnityEngine")));
	End = reinterpret_cast<void(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GL", "End", 0, "", "UnityEngine")));
	CreateWithShader = reinterpret_cast<void(*)(Material*, Shader*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "CreateWithShader", 2, "", "UnityEngine")));
	SetPass = reinterpret_cast<bool(*)(Material*, int)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Material", "SetPass", 1, "", "UnityEngine")));
	get_width = reinterpret_cast<int(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Screen", "get_width", 0, "", "UnityEngine")));
	get_height = reinterpret_cast<int(*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Screen", "get_height", 0, "", "UnityEngine")));
	get_skin = reinterpret_cast<GUISkin * (*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "get_skin", 0, "", "UnityEngine")));
	set_alignment = reinterpret_cast<void(*)(GUIStyle*, int)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUIStyle", "set_alignment", -1, "", "UnityEngine")));
	set_color = reinterpret_cast<void(*)(Color)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "set_color", -1, "", "UnityEngine")));
	set_fontSize = reinterpret_cast<void(*)(GUIStyle*, int)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUIStyle", "set_fontSize", -1, "", "UnityEngine")));
	Label = reinterpret_cast<void(*)(Rect, GUIContent*, GUIStyle*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "Label", 3, "content", "UnityEngine", 2)));
	content_temp = reinterpret_cast<GUIContent * (*)(String*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUIContent", "Temp", 1, "t", "UnityEngine", 1)));
	get_current = reinterpret_cast<Event * (*)()>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Event", "get_current", 0, "", "UnityEngine")));
	get_type = reinterpret_cast<EventType(*)(Event*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Event", "get_type", 0, "", "UnityEngine")));
	get_Texture = reinterpret_cast<Texture*(*)(Sprite*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Sprite", "get_texture", 0, "", "UnityEngine")));
	get_Rect = reinterpret_cast<Unity::Rect(*)(Sprite*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("Sprite", "get_rect", 0, "", "UnityEngine")));
	DrawTexture = reinterpret_cast<void(*)(Unity::Rect, Texture*)>(*reinterpret_cast<DWORD64*>(il2cpp::Method("GUI", "DrawTexture", 2, "", "UnityEngine")));
}

float Time::GetTime() {
	return Methods::get_time();
}

void Object::DontDestroyOnLoad(Object* target) {

	if (!mem.IsValidPtr(target))
		return;

	Methods::DontDestroyOnLoad(target);
}

List<Object*>* Object::FindObjectsOfType(Type* type) {

	if (!mem.IsValidPtr(type))
		return nullptr;

	return Methods::FindObjectsOfType(type);
}

Object* Object::FindObjectOfType(Type* type) {

	if (!mem.IsValidPtr(type))
		return nullptr;

	return Methods::FindObjectOfType(type);
}

Type* Object::GetType(uintptr_t object) {

	if (!mem.IsValidPtr((void*)object))
		return nullptr;

	return Methods::GetType(object);
}

Shader* Shader::Find(String name) {
	return Methods::ShaderFind(name);
}

Shader* Material::GetShader() {

	if (!mem.IsValidPtr(this)) return nullptr;
	return Methods::get_shader(this);
}

void GUI::DrawTexture(Rect pos, Texture* texture)
{
	if (!mem.IsValidPtr(texture)) return;
	Methods::DrawTexture(pos, texture);
}

Rect Sprite::GetRect()
{
	if (!mem.IsValidPtr(this)) return {};
	return Methods::get_Rect(this);
}

Texture* Sprite::GetTexture()
{
	if (!mem.IsValidPtr(this)) return {};
	return Methods::get_Texture(this);
}

void Material::SetShader(Shader* value) {

	if (!mem.IsValidPtr(this) || !mem.IsValidPtr(value)) return;
	Methods::set_shader(this, value);
}

void Material::SetColor(String name, Color value) {

	if (!mem.IsValidPtr(this)) return;
	Methods::SetColor(this, name, value);
}

void Material::SetInt(String name, int value) {

	if (!mem.IsValidPtr(this)) return;
	Methods::SetInt(this, name, value);
}

void Material::CreateWithShader(Material* self, Shader* shader) {

	if (!mem.IsValidPtr(self) || !mem.IsValidPtr(shader)) return;
	Methods::CreateWithShader(self, shader);
}

bool Material::SetPass(int pass) {

	if (!mem.IsValidPtr(this)) return false;
	return Methods::SetPass(this, pass);
}

Material* Renderer::GetMaterial() {

	if (!mem.IsValidPtr(this)) return nullptr;
	return Methods::get_material(this);
}

void Renderer::SetMaterial(Material* mat) {

	if (!mem.IsValidPtr(this)) return;
	return Methods::set_material(this, mat);
}

Transform* Component::GetTransform() {

	if (!mem.IsValidPtr(this)) return nullptr;
	return Methods::get_transform(this);
}

List<uintptr_t>* Component::GetComponentsInChildren(Type* type) {

	if (!mem.IsValidPtr(this) || !mem.IsValidPtr(type)) return nullptr;
	return Methods::GetComponentsInChildren(this, type);
}

Component* Component::GetComponent(Type* type) {

	if (!mem.IsValidPtr(this) || !mem.IsValidPtr(type)) return nullptr;
	return Methods::GetComponent(this, type);
}

Vector3 Transform::GetPosition() {
	if (!mem.IsValidPtr(this)) return Vector3::Zero();
	return Methods::get_position(this);
}

void GameObject::InternalCreateGameObject(GameObject* self, String name) {

	if (!mem.IsValidPtr(self)) return;
	Methods::Internal_CreateGameObject(self, name);
}

Component* GameObject::InternalAddComponentWithType(Type* componentType) {

	if (!mem.IsValidPtr(this) || !mem.IsValidPtr(componentType)) return nullptr;
	Methods::Internal_AddComponentWithType(this, componentType);
}

Camera* Camera::GetMain() 
{
	Camera* Main = Methods::get_main();
	if (!mem.IsValidPtr(Main)) return nullptr;

	return mem.Read<Camera*>(Main + 0x10);
}

Vector3 Camera::GetLocation()
{
	if (!mem.IsValidPtr(this)) return {};
	this->Location = mem.Read<Vector3>(this + 0x454);
	return this->Location;
}

Matrix4x4 Camera::GetViewMatrix()
{
	if (!mem.IsValidPtr(this)) return {};
	this->ViewMatrix = mem.Read<Matrix4x4>(this + 0x30C);
	return this->ViewMatrix;
}

Vector2 Camera::WorldToScreen(Vector3 world_pos)
{

	Vector3 trans_vec{ this->ViewMatrix._14, this->ViewMatrix._24, this->ViewMatrix._34 };
	Vector3 right_vec{ this->ViewMatrix._11, this->ViewMatrix._21, this->ViewMatrix._31 };
	Vector3 up_vec{ this->ViewMatrix._12, this->ViewMatrix._22, this->ViewMatrix._32 };

	float w = trans_vec.Dot(world_pos) + this->ViewMatrix._44;

	if (w < 0.1f) return {};

	float y = up_vec.Dot(world_pos) + this->ViewMatrix._42;
	float x = right_vec.Dot(world_pos) + this->ViewMatrix._41;

	return Vector2((1920 / 2) * (1.f + x / w), (1080 / 2) * (1.f - y / w));
}

int Screen::GetWidth() {
	return Methods::get_width();
}

int Screen::GetHeight() {
	return Methods::get_height();
}

void GL::PushMatrix() {
	Methods::PushMatrix();
}

void GL::PopMatrix() {
	Methods::PopMatrix();
}

void GL::Begin(int mode) {
	Methods::Begin(mode);
}

void GL::GLColor(Color color) {
	Methods::GLColor(color);
}

void GL::Vertex(Vector3 value) {
	Methods::Vertex(value);
}

void GL::End() {
	Methods::End();
}

GUIContent* GUIContent::Temp(String* t) {

	if (!mem.IsValidPtr(t)) return nullptr;
	return Methods::content_temp(t);
}

void GUIStyle::SetAlignment(int anchor) {

	if (!mem.IsValidPtr(this)) return;
	Methods::set_alignment(this, anchor);
}

void GUIStyle::SetFontSize(int size) {

	if (!mem.IsValidPtr(this)) return;
	Methods::set_fontSize(this, size);
}

Vector2 GUIStyle::CalcSize(GUIContent* content) {

	if (!mem.IsValidPtr(this)) return {};

	Vector2 size = {};
	Methods::CalcSize(this, content, &size);
	return size;
}

GUISkin* GUI::GetSkin() {
	return Methods::get_skin();
}

void GUI::SetColor(Color color) {
	return Methods::set_color(color);
}

void GUI::Label(Rect pos, GUIContent* content, GUIStyle* style) {

	if (!mem.IsValidPtr(content) || !mem.IsValidPtr(style)) return;
	Methods::Label(pos, content, style);
}

void GUI::Box(Rect pos, GUIContent* content, GUIStyle* style) {

	if (!mem.IsValidPtr(content) || !mem.IsValidPtr(style)) return;
	Methods::Box(pos, content, style);
}

float GUI::HorizontalSlider(Rect position, float value, float leftValue, float rightValue) {
	Methods::HorizontalSlider(position, value, leftValue, rightValue);
}

bool GUI::Button(Rect* position, GUIContent* content, GUIStyle* style) {

	if (!mem.IsValidPtr(content) || !mem.IsValidPtr(style)) return false;
	return Methods::Button(position, content, style);
}

void GUI::BeginGroup(Rect* position, GUIContent* content, GUIStyle* style) {

	if (!mem.IsValidPtr(content) || !mem.IsValidPtr(style))return;
	Methods::BeginGroup(position, content, style);
}

void GUI::EndGroup() 
{
	Methods::EndGroup();
}

EventType Event::GetType() 
{
	if (!mem.IsValidPtr(this)) return EventType::MouseDown;
	return Methods::get_type(this);
}

Event* Event::GetCurrent() {
	return Methods::get_current();
}

Vector2 Event::GetMousePosition() 
{
	if (!mem.IsValidPtr(this)) return {};

	Vector2 Pos = {};
	Methods::get_mousePosition_Injected(this, &Pos);
	return Pos;
}