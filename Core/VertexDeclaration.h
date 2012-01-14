/********************************************************************
	创建时间:	8:1:2012   20:46
	文件名: 	f:\Aurorar\Core\VertexDeclaration.h
	创建者:		丁亮
	
	文件作用:	顶点格式声明 当作一种资源来管理
*********************************************************************/

#pragma once

#include "Prerequisites.h"
#include "Resource.h"

namespace Aurora
{
	enum CORE_API VertexElementSemantic
	{
		VES_POSITION = 1,
		VES_BLEND_WEIGHTS = 2,
		VES_BLEND_INDICES = 3,
		VES_NORMAL = 4,
		VES_DIFFUSE = 5,
		VES_SPECULAR = 6,
		VES_TEXTURE_COORDINATES = 7,
		VES_BINORMAL = 8,
		VES_TANGENT = 9,

		VES_MAX
	};

	enum CORE_API VertexElementType
	{
		VET_FLOAT1 = 0,
		VET_FLOAT2 = 1,
		VET_FLOAT3 = 2,
		VET_FLOAT4 = 3,
		VET_COLOUR = 4,
		VET_SHORT1 = 5,
		VET_SHORT2 = 6,
		VET_SHORT3 = 7,
		VET_SHORT4 = 8,
		VET_UBYTE4 = 9,

		VET_MAX
	};

	struct CORE_API VertexElement : public ResourceAllocatedObject
	{
		ushort					mSource;
		size_t					mOffset;
		VertexElementType		mType;
		VertexElementSemantic	mSemantic;
		ushort					mIndex;

		VertexElement(void) {}

		VertexElement(ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index = 0);

		static ushort			GetTypeCount(VertexElementType etype);

		static size_t			GetTypeSize(VertexElementType etype);

		size_t					GetSize(void) const;

		bool					operator == (const VertexElement& rhs) const;

		// 为了可以用list的排序 只能用于保存对象时
		bool					operator <	(const VertexElement& rhs) const;
	};

	typedef list<VertexElement>::type VertexElementList;

	class CORE_API VertexDeclaration : public Resource
	{
	public:
		VertexDeclaration(void) {}
		virtual ~VertexDeclaration(void) {}

		virtual void		Sort();

		void				AddElement(ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index = 0);

		void				InsertElement(ushort atPosition, ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index = 0);

		void				RemoveElement(ushort elem_index);

		void				RemoveElement(VertexElementSemantic semantic, ushort index = 0);

		void				RemoveAllElements(void);

		void				ModifyElement(ushort elem_index, ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index = 0);

		size_t				GetVertexSize(ushort source);

		ushort				GetMaxSource(void) const;

		bool				operator == (const VertexDeclaration& rhs) const;

		bool				operator != (const VertexDeclaration& rhs) const;

	protected:
		VertexElementList	mElementList;
		 
	};

}