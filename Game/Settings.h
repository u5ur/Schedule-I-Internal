#pragma once

#define DEBUG true

#define USE_ASSETBUNDLE false


/// How to use custom chams ///
// ~ General Use
// Go to Materials folder and get the .asset files
// Place in directory with Schedule I.exe
// set USE_ASSETBUNDLE to true

// ~ Custom Use
// Download or create your own asset bundles. 
// Load bundle from file or memory, here is file for example
// LoadFromFile(Unity::String::New("pathto/your.asset"), 0, 0)
// Load the asset from its bundle path
// LoadAsset(YourLoadedBundle, Unity::String::New("pathto/your.mat"), il2cpp::TypeGetObject(NameSpace, ClassName))
///

namespace Settings
{

	namespace Aimbot
	{
		inline bool bAimbot = true;
		inline bool bRapidFire = true;
	}

	namespace Visuals
	{
		inline bool bSkeleton = true;
		inline bool bChams = true;
		inline bool bInventory = true;
		inline bool bCustomSky = true;
	}
}