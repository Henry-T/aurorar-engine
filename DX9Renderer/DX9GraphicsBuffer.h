#pragma once
#include "GraphicsBuffer.h"

namespace Aurora
{
	class DX9RENDERER_API DX9GraphicsBuffer : GraphicsBuffer
	{
	public:
		DX9GraphicsBuffer();
		~DX9GraphicsBuffer();
		void			MakeDeclaration();
		void			CreateDeviceBuffer();

		IDirect3DVertexBuffer9* m_pDX9VB;
	};
}