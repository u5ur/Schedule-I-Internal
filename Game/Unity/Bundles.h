#pragma once

namespace Bundles
{
	inline Unity::Material* HologramMaterial = nullptr;
	inline Unity::Shader* HologramShader = nullptr;

	inline Unity::Material* StarNestMaterial = nullptr;
	inline Unity::Shader* StarNestShader = nullptr;

	inline void Init()
	{
		uint64_t StarNestBundle = Unity::Methods::LoadFromFile(Unity::String::New("starnest.asset"), 0, 0);
		if (StarNestBundle)
		{
			StarNestMaterial = (Unity::Material*)Unity::Methods::LoadAsset(StarNestBundle, Unity::String::New("starnest.mat"), il2cpp::TypeGetObject("UnityEngine", "Material"));
			StarNestShader = (Unity::Shader*)Unity::Methods::LoadAsset(StarNestBundle, Unity::String::New("starnest.shader"), il2cpp::TypeGetObject("UnityEngine", "Shader"));
		}

		uint64_t HologramBundle = Unity::Methods::LoadFromFile(Unity::String::New("holo_gram.asset"), 0, 0);
		if (HologramBundle)
		{
			HologramMaterial = (Unity::Material*)Unity::Methods::LoadAsset(HologramBundle, Unity::String::New("hologrammat3.mat"), il2cpp::TypeGetObject("UnityEngine", "Material"));
			HologramShader = (Unity::Shader*)Unity::Methods::LoadAsset(HologramBundle, Unity::String::New("hologram.shader"), il2cpp::TypeGetObject("UnityEngine", "Shader"));
		}
	}
}