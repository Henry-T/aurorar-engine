/********************************************************************
	创建时间:	6:1:2012   0:24
	文件名	:	AxisAlignedBox
	创建者:		丁亮
	
	文件作用:	AABB
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Vector3.h"
#include "Matrix4.h"

namespace Aurora 
{

	class MATH_API AxisAlignedBox
	{
	public:
		enum Extent
		{
			EXTENT_NULL,
			EXTENT_FINITE,
			EXTENT_INFINITE
		};
	protected:

		Vector3 mMinimum;
		Vector3 mMaximum;
		Extent mExtent;
		mutable Vector3* mpCorners;

	public:
		/*
		1-----2
		/|    /|
		/ |   / |
		5-----4  |
		|  0--|--3
		| /   | /
		|/    |/
		6-----7
		*/
		typedef enum 
		{
			FAR_LEFT_BOTTOM = 0,
			FAR_LEFT_TOP = 1,
			FAR_RIGHT_TOP = 2,
			FAR_RIGHT_BOTTOM = 3,
			NEAR_RIGHT_BOTTOM = 7,
			NEAR_LEFT_BOTTOM = 6,
			NEAR_LEFT_TOP = 5,
			NEAR_RIGHT_TOP = 4
		} CornerEnum;

		inline AxisAlignedBox() : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
		{
			// Default to a null box 
			setMinimum( -0.5, -0.5, -0.5 );
			setMaximum( 0.5, 0.5, 0.5 );
			mExtent = EXTENT_NULL;
		}
		inline AxisAlignedBox(Extent e) : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
		{
			setMinimum( -0.5, -0.5, -0.5 );
			setMaximum( 0.5, 0.5, 0.5 );
			mExtent = e;
		}

		inline AxisAlignedBox(const AxisAlignedBox & rkBox) : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)

		{
			if (rkBox.isNull())
				setNull();
			else if (rkBox.isInfinite())
				setInfinite();
			else
				setExtents( rkBox.mMinimum, rkBox.mMaximum );
		}

		inline AxisAlignedBox( const Vector3& min, const Vector3& max ) : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
		{
			setExtents( min, max );
		}

		inline AxisAlignedBox(
			Real mx, Real my, Real mz,
			Real Mx, Real My, Real Mz ) : mMinimum(Vector3::ZERO), mMaximum(Vector3::UNIT_SCALE), mpCorners(0)
		{
			setExtents( mx, my, mz, Mx, My, Mz );
		}

		AxisAlignedBox& operator=(const AxisAlignedBox& rhs)
		{
			// Specifically override to avoid copying mpCorners
			if (rhs.isNull())
				setNull();
			else if (rhs.isInfinite())
				setInfinite();
			else
				setExtents(rhs.mMinimum, rhs.mMaximum);

			return *this;
		}

		~AxisAlignedBox()
		{
			if (mpCorners)
				NED_FREE(mpCorners, MEMCATEGORY_SCENE_CONTROL);
		}

		inline const Vector3& getMinimum(void) const
		{ 
			return mMinimum; 
		}

		inline Vector3& getMinimum(void)
		{ 
			return mMinimum; 
		}

		inline const Vector3& getMaximum(void) const
		{ 
			return mMaximum;
		}

		inline Vector3& getMaximum(void)
		{ 
			return mMaximum;
		}

		inline void setMinimum( const Vector3& vec )
		{
			mExtent = EXTENT_FINITE;
			mMinimum = vec;
		}

		inline void setMinimum( Real x, Real y, Real z )
		{
			mExtent = EXTENT_FINITE;
			mMinimum.x = x;
			mMinimum.y = y;
			mMinimum.z = z;
		}

		inline void setMinimumX(Real x)
		{
			mMinimum.x = x;
		}

		inline void setMinimumY(Real y)
		{
			mMinimum.y = y;
		}

		inline void setMinimumZ(Real z)
		{
			mMinimum.z = z;
		}

		inline void setMaximum( const Vector3& vec )
		{
			mExtent = EXTENT_FINITE;
			mMaximum = vec;
		}

		inline void setMaximum( Real x, Real y, Real z )
		{
			mExtent = EXTENT_FINITE;
			mMaximum.x = x;
			mMaximum.y = y;
			mMaximum.z = z;
		}

		inline void setMaximumX( Real x )
		{
			mMaximum.x = x;
		}

		inline void setMaximumY( Real y )
		{
			mMaximum.y = y;
		}

		inline void setMaximumZ( Real z )
		{
			mMaximum.z = z;
		}

		/** Sets both minimum and maximum extents at once.
		*/
		inline void setExtents( const Vector3& min, const Vector3& max )
		{
            assert( (min.x <= max.x && min.y <= max.y && min.z <= max.z) &&
                "The minimum corner of the box must be less than or equal to maximum corner" );

			mExtent = EXTENT_FINITE;
			mMinimum = min;
			mMaximum = max;
		}

		inline void setExtents(
			Real mx, Real my, Real mz,
			Real Mx, Real My, Real Mz )
		{
            assert( (mx <= Mx && my <= My && mz <= Mz) &&
                "The minimum corner of the box must be less than or equal to maximum corner" );

			mExtent = EXTENT_FINITE;

			mMinimum.x = mx;
			mMinimum.y = my;
			mMinimum.z = mz;

			mMaximum.x = Mx;
			mMaximum.y = My;
			mMaximum.z = Mz;

		}

		/** Returns a pointer to an array of 8 corner points, useful for
		collision vs. non-aligned objects.
		@remarks
		If the order of these corners is important, they are as
		follows: The 4 points of the minimum Z face (note that
		because Ogre uses right-handed coordinates, the minimum Z is
		at the 'back' of the box) starting with the minimum point of
		all, then anticlockwise around this face (if you are looking
		onto the face from outside the box). Then the 4 points of the
		maximum Z face, starting with maximum point of all, then
		anticlockwise around this face (looking onto the face from
		outside the box). Like this:
		<pre>
		1-----2
		/|    /|
		/ |   / |
		5-----4  |
		|  0--|--3
		| /   | /
		|/    |/
		6-----7
		</pre>
		@remarks as this implementation uses a static member, make sure to use your own copy !
		*/
		inline const Vector3* getAllCorners(void) const
		{
			assert( (mExtent == EXTENT_FINITE) && "Can't get corners of a null or infinite AAB" );

			// The order of these items is, using right-handed co-ordinates:
			// Minimum Z face, starting with Min(all), then anticlockwise
			//   around face (looking onto the face)
			// Maximum Z face, starting with Max(all), then anticlockwise
			//   around face (looking onto the face)
			// Only for optimization/compatibility.
			if (!mpCorners)
				mpCorners = NED_ALLOC_T(Vector3, 8, MEMCATEGORY_SCENE_CONTROL);

			mpCorners[0] = mMinimum;
			mpCorners[1].x = mMinimum.x; mpCorners[1].y = mMaximum.y; mpCorners[1].z = mMinimum.z;
			mpCorners[2].x = mMaximum.x; mpCorners[2].y = mMaximum.y; mpCorners[2].z = mMinimum.z;
			mpCorners[3].x = mMaximum.x; mpCorners[3].y = mMinimum.y; mpCorners[3].z = mMinimum.z;            

			mpCorners[4] = mMaximum;
			mpCorners[5].x = mMinimum.x; mpCorners[5].y = mMaximum.y; mpCorners[5].z = mMaximum.z;
			mpCorners[6].x = mMinimum.x; mpCorners[6].y = mMinimum.y; mpCorners[6].z = mMaximum.z;
			mpCorners[7].x = mMaximum.x; mpCorners[7].y = mMinimum.y; mpCorners[7].z = mMaximum.z;

			return mpCorners;
		}

		Vector3 getCorner(CornerEnum cornerToGet) const
		{
			switch(cornerToGet)
			{
			case FAR_LEFT_BOTTOM:
				return mMinimum;
			case FAR_LEFT_TOP:
				return Vector3(mMinimum.x, mMaximum.y, mMinimum.z);
			case FAR_RIGHT_TOP:
				return Vector3(mMaximum.x, mMaximum.y, mMinimum.z);
			case FAR_RIGHT_BOTTOM:
				return Vector3(mMaximum.x, mMinimum.y, mMinimum.z);
			case NEAR_RIGHT_BOTTOM:
				return Vector3(mMaximum.x, mMinimum.y, mMaximum.z);
			case NEAR_LEFT_BOTTOM:
				return Vector3(mMinimum.x, mMinimum.y, mMaximum.z);
			case NEAR_LEFT_TOP:
				return Vector3(mMinimum.x, mMaximum.y, mMaximum.z);
			case NEAR_RIGHT_TOP:
				return mMaximum;
			default:
				return Vector3();
			}
		}

		MATH_API friend std::ostream& operator<<( std::ostream& o, const AxisAlignedBox aab )
		{
			switch (aab.mExtent)
			{
			case EXTENT_NULL:
				o << "AxisAlignedBox(null)";
				return o;

			case EXTENT_FINITE:
				o << "AxisAlignedBox(min=" << aab.mMinimum << ", max=" << aab.mMaximum << ")";
				return o;

			case EXTENT_INFINITE:
				o << "AxisAlignedBox(infinite)";
				return o;

			default: // shut up compiler
				assert( false && "Never reached" );
				return o;
			}
		}

		void merge( const AxisAlignedBox& rhs )
		{
			// Do nothing if rhs null, or this is infinite
			if ((rhs.mExtent == EXTENT_NULL) || (mExtent == EXTENT_INFINITE))
			{
				return;
			}
			// Otherwise if rhs is infinite, make this infinite, too
			else if (rhs.mExtent == EXTENT_INFINITE)
			{
				mExtent = EXTENT_INFINITE;
			}
			// Otherwise if current null, just take rhs
			else if (mExtent == EXTENT_NULL)
			{
				setExtents(rhs.mMinimum, rhs.mMaximum);
			}
			// Otherwise merge
			else
			{
				Vector3 min = mMinimum;
				Vector3 max = mMaximum;
				max.makeCeil(rhs.mMaximum);
				min.makeFloor(rhs.mMinimum);

				setExtents(min, max);
			}

		}

		inline void merge( const Vector3& point )
		{
			switch (mExtent)
			{
			case EXTENT_NULL: // if null, use this point
				setExtents(point, point);
				return;

			case EXTENT_FINITE:
				mMaximum.makeCeil(point);
				mMinimum.makeFloor(point);
				return;

			case EXTENT_INFINITE: // if infinite, makes no difference
				return;
			}

			assert( false && "Never reached" );
		}

		inline void transform( const Matrix4& matrix )
		{
			// Do nothing if current null or infinite
			if( mExtent != EXTENT_FINITE )
				return;

			Vector3 oldMin, oldMax, currentCorner;

			// Getting the old values so that we can use the existing merge method.
			oldMin = mMinimum;
			oldMax = mMaximum;

			// reset
			setNull();

			// We sequentially compute the corners in the following order :
			// 0, 6, 5, 1, 2, 4 ,7 , 3
			// This sequence allows us to only change one member at a time to get at all corners.

			// For each one, we transform it using the matrix
			// Which gives the resulting point and merge the resulting point.

			// First corner 
			// min min min
			currentCorner = oldMin;
			merge( matrix * currentCorner );

			// min,min,max
			currentCorner.z = oldMax.z;
			merge( matrix * currentCorner );

			// min max max
			currentCorner.y = oldMax.y;
			merge( matrix * currentCorner );

			// min max min
			currentCorner.z = oldMin.z;
			merge( matrix * currentCorner );

			// max max min
			currentCorner.x = oldMax.x;
			merge( matrix * currentCorner );

			// max max max
			currentCorner.z = oldMax.z;
			merge( matrix * currentCorner );

			// max min max
			currentCorner.y = oldMin.y;
			merge( matrix * currentCorner );

			// max min min
			currentCorner.z = oldMin.z;
			merge( matrix * currentCorner ); 
		}

		void transformAffine(const Matrix4& m)
		{
			assert(m.isAffine());

			// Do nothing if current null or infinite
			if ( mExtent != EXTENT_FINITE )
				return;

			Vector3 centre = getCenter();
			Vector3 halfSize = getHalfSize();

			Vector3 newCentre = m.transformAffine(centre);
			Vector3 newHalfSize(
				Math::Abs(m[0][0]) * halfSize.x + Math::Abs(m[0][1]) * halfSize.y + Math::Abs(m[0][2]) * halfSize.z, 
				Math::Abs(m[1][0]) * halfSize.x + Math::Abs(m[1][1]) * halfSize.y + Math::Abs(m[1][2]) * halfSize.z,
				Math::Abs(m[2][0]) * halfSize.x + Math::Abs(m[2][1]) * halfSize.y + Math::Abs(m[2][2]) * halfSize.z);

			setExtents(newCentre - newHalfSize, newCentre + newHalfSize);
		}

		inline void setNull()
		{
			mExtent = EXTENT_NULL;
		}

		inline bool isNull(void) const
		{
			return (mExtent == EXTENT_NULL);
		}

		bool isFinite(void) const
		{
			return (mExtent == EXTENT_FINITE);
		}

		inline void setInfinite()
		{
			mExtent = EXTENT_INFINITE;
		}

		bool isInfinite(void) const
		{
			return (mExtent == EXTENT_INFINITE);
		}

		inline bool intersects(const AxisAlignedBox& b2) const
		{
			// Early-fail for nulls
			if (this->isNull() || b2.isNull())
				return false;

			// Early-success for infinites
			if (this->isInfinite() || b2.isInfinite())
				return true;

			// Use up to 6 separating planes
			if (mMaximum.x < b2.mMinimum.x)
				return false;
			if (mMaximum.y < b2.mMinimum.y)
				return false;
			if (mMaximum.z < b2.mMinimum.z)
				return false;

			if (mMinimum.x > b2.mMaximum.x)
				return false;
			if (mMinimum.y > b2.mMaximum.y)
				return false;
			if (mMinimum.z > b2.mMaximum.z)
				return false;

			// otherwise, must be intersecting
			return true;

		}

		inline AxisAlignedBox intersection(const AxisAlignedBox& b2) const
		{
            if (this->isNull() || b2.isNull())
			{
				return AxisAlignedBox();
			}
			else if (this->isInfinite())
			{
				return b2;
			}
			else if (b2.isInfinite())
			{
				return *this;
			}

			Vector3 intMin = mMinimum;
            Vector3 intMax = mMaximum;

            intMin.makeCeil(b2.getMinimum());
            intMax.makeFloor(b2.getMaximum());

            // Check intersection isn't null
            if (intMin.x < intMax.x &&
                intMin.y < intMax.y &&
                intMin.z < intMax.z)
            {
                return AxisAlignedBox(intMin, intMax);
            }

            return AxisAlignedBox();
		}

		Real volume(void) const
		{
			switch (mExtent)
			{
			case EXTENT_NULL:
				return 0.0f;

			case EXTENT_FINITE:
				{
					Vector3 diff = mMaximum - mMinimum;
					return diff.x * diff.y * diff.z;
				}

			case EXTENT_INFINITE:
				return Math::POS_INFINITY;

			default: // shut up compiler
				assert( false && "Never reached" );
				return 0.0f;
			}
		}

		inline void scale(const Vector3& s)
		{
			// Do nothing if current null or infinite
			if (mExtent != EXTENT_FINITE)
				return;

			// NB assumes centered on origin
			Vector3 min = mMinimum * s;
			Vector3 max = mMaximum * s;
			setExtents(min, max);
		}

		bool intersects(const Sphere& s) const
		{
			return Math::intersects(s, *this); 
		}

		bool intersects(const Plane& p) const
		{
			return Math::intersects(p, *this);
		}

		bool intersects(const Vector3& v) const
		{
			switch (mExtent)
			{
			case EXTENT_NULL:
				return false;

			case EXTENT_FINITE:
				return(v.x >= mMinimum.x  &&  v.x <= mMaximum.x  && 
					v.y >= mMinimum.y  &&  v.y <= mMaximum.y  && 
					v.z >= mMinimum.z  &&  v.z <= mMaximum.z);

			case EXTENT_INFINITE:
				return true;

			default: // shut up compiler
				assert( false && "Never reached" );
				return false;
			}
		}
		/// Gets the centre of the box
		Vector3 getCenter(void) const
		{
			assert( (mExtent == EXTENT_FINITE) && "Can't get center of a null or infinite AAB" );

			return Vector3(
				(mMaximum.x + mMinimum.x) * 0.5f,
				(mMaximum.y + mMinimum.y) * 0.5f,
				(mMaximum.z + mMinimum.z) * 0.5f);
		}
		/// Gets the size of the box
		Vector3 getSize(void) const
		{
			switch (mExtent)
			{
			case EXTENT_NULL:
				return Vector3::ZERO;

			case EXTENT_FINITE:
				return mMaximum - mMinimum;

			case EXTENT_INFINITE:
				return Vector3(
					Math::POS_INFINITY,
					Math::POS_INFINITY,
					Math::POS_INFINITY);

			default: // shut up compiler
				assert( false && "Never reached" );
				return Vector3::ZERO;
			}
		}
		/// Gets the half-size of the box
		Vector3 getHalfSize(void) const
		{
			switch (mExtent)
			{
			case EXTENT_NULL:
				return Vector3::ZERO;

			case EXTENT_FINITE:
				return (mMaximum - mMinimum) * 0.5;

			case EXTENT_INFINITE:
				return Vector3(
					Math::POS_INFINITY,
					Math::POS_INFINITY,
					Math::POS_INFINITY);

			default: // shut up compiler
				assert( false && "Never reached" );
				return Vector3::ZERO;
			}
		}

        bool contains(const Vector3& v) const
        {
            if (isNull())
                return false;
            if (isInfinite())
                return true;

            return mMinimum.x <= v.x && v.x <= mMaximum.x &&
                   mMinimum.y <= v.y && v.y <= mMaximum.y &&
                   mMinimum.z <= v.z && v.z <= mMaximum.z;
        }

        bool contains(const AxisAlignedBox& other) const
        {
            if (other.isNull() || this->isInfinite())
                return true;

            if (this->isNull() || other.isInfinite())
                return false;

            return this->mMinimum.x <= other.mMinimum.x &&
                   this->mMinimum.y <= other.mMinimum.y &&
                   this->mMinimum.z <= other.mMinimum.z &&
                   other.mMaximum.x <= this->mMaximum.x &&
                   other.mMaximum.y <= this->mMaximum.y &&
                   other.mMaximum.z <= this->mMaximum.z;
        }

        bool operator== (const AxisAlignedBox& rhs) const
        {
            if (this->mExtent != rhs.mExtent)
                return false;

            if (!this->isFinite())
                return true;

            return this->mMinimum == rhs.mMinimum &&
                   this->mMaximum == rhs.mMaximum;
        }

        bool operator!= (const AxisAlignedBox& rhs) const
        {
            return !(*this == rhs);
        }

		static const AxisAlignedBox BOX_NULL;
		static const AxisAlignedBox BOX_INFINITE;


	};

	typedef AxisAlignedBox AABB;

}
