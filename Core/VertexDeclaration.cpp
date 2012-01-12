#include "StdAfx.h"
#include "VertexDeclaration.h"
#include "Exception.h"
#include "ColourValue.h"

namespace Aurora
{

	VertexElement::VertexElement( ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index /*= 0*/ )
		: mSource(source), mOffset(offset), mType(theType), mSemantic(semantic), mIndex(index)
	{

	}

	ushort VertexElement::GetTypeCount( VertexElementType etype )
	{
		switch (etype)
		{
		case VET_COLOUR:
			return 1;
		case VET_FLOAT1:
			return 1;
		case VET_FLOAT2:
			return 2;
		case VET_FLOAT3:
			return 3;
		case VET_FLOAT4:
			return 4;
		case VET_SHORT1:
			return 1;
		case VET_SHORT2:
			return 2;
		case VET_SHORT3:
			return 3;
		case VET_SHORT4:
			return 4;
		case VET_UBYTE4:
			return 4;
		}
		AURORA_EXCEPT(Exception::ERR_INVALIDPARAMS, "Invalid type", "VertexElement::GetTypeCount");
	}


	size_t VertexElement::GetTypeSize( VertexElementType etype )
	{
		switch(etype)
		{
		case VET_COLOUR:
			return sizeof(RGBA);
		case VET_FLOAT1:
			return sizeof(float);
		case VET_FLOAT2:
			return sizeof(float)*2;
		case VET_FLOAT3:
			return sizeof(float)*3;
		case VET_FLOAT4:
			return sizeof(float)*4;
		case VET_SHORT1:
			return sizeof(short);
		case VET_SHORT2:
			return sizeof(short)*2;
		case VET_SHORT3:
			return sizeof(short)*3;
		case VET_SHORT4:
			return sizeof(short)*4;
		case VET_UBYTE4:
			return sizeof(unsigned char)*4;
		}
		return 0;
	}

	size_t VertexElement::GetSize( void ) const
	{
		return GetTypeSize(mType);
	}

	__forceinline bool VertexElement::operator==( const VertexElement& rhs ) const
	{
		if (mType != rhs.mType ||
			mIndex != rhs.mIndex ||
			mOffset != rhs.mOffset ||
			mSemantic != rhs.mSemantic ||
			mSource != rhs.mSource)
			return false;
		else
			return true;
	}

	__forceinline bool VertexElement::operator<( const VertexElement& rhs ) const
	{
		// Sort by source first
		if (mSource < rhs.mSource)
		{
			return true;
		}
		else if (mSource == rhs.mSource)
		{
			// Use ordering of semantics to sort
			if (mSemantic < rhs.mSemantic)
			{
				return true;
			}
			else if (mSemantic == rhs.mSemantic)
			{
				// Use index to sort
				if (mIndex < rhs.mIndex)
				{
					return true;
				}
			}
		}
		return false;
	}




	void VertexDeclaration::Sort()
	{
		mElementList.sort();
	}

	void VertexDeclaration::AddElement( ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index /*= 0*/ )
	{
		mElementList.push_back(VertexElement(source, offset, theType, semantic, index));
	}

	void VertexDeclaration::InsertElement( ushort atPosition, ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index /*= 0*/ )
	{
		if (atPosition >= mElementList.size())
		{
			AddElement(source, offset, theType, semantic, index);
			return;

			VertexElementList::iterator i = mElementList.begin();
			for (unsigned short n = 0; n < atPosition; ++n)
				++i;

			mElementList.insert(i, VertexElement(source, offset, theType, semantic, index));
		}
	}

	void VertexDeclaration::RemoveElement( ushort elem_index )
	{
		assert(elem_index < mElementList.size() && "Index out of bounds");
		VertexElementList::iterator i = mElementList.begin();
		for (unsigned short n = 0; n < elem_index; ++n)
			++i;
		mElementList.erase(i);
	}

	void VertexDeclaration::RemoveElement( VertexElementSemantic semantic, ushort index /*= 0*/ )
	{
		VertexElementList::iterator ei, eiend;
		eiend = mElementList.end();
		for (ei = mElementList.begin(); ei != eiend; ++ei)
		{
			if (ei->mSource == semantic && ei->mIndex == index)
			{
				mElementList.erase(ei);
				break;
			}
		}
	}

	void VertexDeclaration::RemoveAllElements( void )
	{
		mElementList.clear();
	}

	void VertexDeclaration::ModifyElement( ushort elem_index, ushort source, size_t offset, VertexElementType theType, VertexElementSemantic semantic, ushort index /*= 0*/ )
	{
		assert(elem_index < mElementList.size() && "Index out of bounds");
		VertexElementList::iterator i = mElementList.begin();
		std::advance(i, elem_index);
		(*i) = VertexElement(source, offset, theType, semantic, index);
	}

	size_t VertexDeclaration::GetVertexSize( ushort source )
	{
		VertexElementList::const_iterator i, iend;
		iend = mElementList.end();
		size_t sz = 0;

		for (i = mElementList.begin(); i != iend; ++i)
		{
			if (i->mSource == source)
			{
				sz += i->GetSize();

			}
		}
		return sz;
	}


	ushort VertexDeclaration::GetMaxSource( void ) const
	{
		VertexElementList::const_iterator i, iend;
		iend = mElementList.end();
		unsigned short ret = 0;
		for (i = mElementList.begin(); i != iend; ++i)
		{
			if (i->mSource > ret)
			{
				ret = i->mSource;
			}

		}
		return ret;
	}


	bool VertexDeclaration::operator==( const VertexDeclaration& rhs ) const
	{
		if (mElementList.size() != rhs.mElementList.size())
			return false;

		VertexElementList::const_iterator i, iend, rhsi, rhsiend;
		iend = mElementList.end();
		rhsiend = rhs.mElementList.end();
		rhsi = rhs.mElementList.begin();
		for (i = mElementList.begin(); i != iend && rhsi != rhsiend; ++i, ++rhsi)
		{
			if ( !(*i == *rhsi) )
				return false;
		}

		return true;
	}

	bool VertexDeclaration::operator!=( const VertexDeclaration& rhs ) const
	{
		return !(*this == rhs);
	}



}