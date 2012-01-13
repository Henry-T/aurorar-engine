#pragma once
#include "Singleton.h"
#include "Prerequisites.h"

class FBXLoader : public Singleton<LogManager>, public GeneralAllocatedObject
{
public:
	int LoadContent( String file);
};