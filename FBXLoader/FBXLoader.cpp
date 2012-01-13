#include "FBXLoader.h"
#include "fbxsdk.h"


//-----------------------------------------------------------------------
template<> FBXLoader* Singleton<FBXLoader>::ms_Singleton = 0;
LogManager* FBXLoader::getSingletonPtr(void)
{
	return ms_Singleton;
}
LogManager& FBXLoader::getSingleton(void)
{  
	assert( ms_Singleton );  return ( *ms_Singleton );  
}
//-----------------------------------------------------------------------


int FBXLoader::LoadContent( String file)
{
	// Initialize the sdk manager. This object handles all our memory management.
	KFbxSdkManager* lSdkManager = KFbxSdkManager::Create();

	// Create the io settings object.
	KFbxIOSettings *ios = KFbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// Create an importer using our sdk manager.
	KFbxImporter* lImporter = KFbxImporter::Create(lSdkManager,"");

	// Use the first argument as the filename for the importer.
	if(!lImporter->Initialize(file.c_str(), -1, lSdkManager->GetIOSettings())) {
		printf("Call to KFbxImporter::Initialize() failed.\n");
		printf("Error returned: %s\n\n", lImporter->GetLastErrorString());
		exit(-1);
	}

	// Create a new scene so it can be populated by the imported file.
	KFbxScene* lScene = KFbxScene::Create(lSdkManager,"Scene1");

	// Import the contents of the file into the scene.
	lImporter->Import(lScene);

	// The file has been imported; we can get rid of the importer.
	lImporter->Destroy();
}