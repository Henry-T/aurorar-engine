#pragma once
#include "..\Core\RenderEngine.h"
#include "..\MemoryAllocator\MemoryAllocator.h"

namespace Aurora
{
	class DX9RENDERER_API DX9RenderEngine : public RenderEngine, public MemoryAllocator
	{
	public:
		DX9RenderEngine(void);
		~DX9RenderEngine(void);
	};

}
