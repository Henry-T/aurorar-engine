/********************************************************************
	创建时间:	6:1:2012   0:33
	文件名	:	Sphere
	创建者:		丁亮
	
	文件作用:	球
*********************************************************************/

#pragma once

#include "MathLib.h"
#include "Vector3.h"

namespace Aurora
{

    class MATHLIB_API Sphere
    {
    protected:
        Real mRadius;
        Vector3 mCenter;
    public:

        Sphere() : mRadius(1.0), mCenter(Vector3::ZERO) {}

        Sphere(const Vector3& center, Real radius)
            : mRadius(radius), mCenter(center) {}

        Real getRadius(void) const { return mRadius; }

        void setRadius(Real radius) { mRadius = radius; }

        const Vector3& getCenter(void) const { return mCenter; }

        void setCenter(const Vector3& center) { mCenter = center; }

		bool intersects(const Sphere& s) const
		{
            return (s.mCenter - mCenter).squaredLength() <= Math::Sqr(s.mRadius + mRadius);
		}
	
		bool intersects(const AxisAlignedBox& box) const
		{
			return Math::intersects(*this, box);
		}
	
		bool intersects(const Plane& plane) const
		{
			return Math::intersects(*this, plane);
		}
		
		bool intersects(const Vector3& v) const
		{
            return ((v - mCenter).squaredLength() <= Math::Sqr(mRadius));
		}
		
		void merge(const Sphere& oth)
		{
			Vector3 diff =  oth.getCenter() - mCenter;
			Real lengthSq = diff.squaredLength();
			Real radiusDiff = oth.getRadius() - mRadius;
			
			// Early-out
			if (Math::Sqr(radiusDiff) >= lengthSq) 
			{
				// One fully contains the other
				if (radiusDiff <= 0.0f) 
					return; // no change
				else 
				{
					mCenter = oth.getCenter();
					mRadius = oth.getRadius();
					return;
				}
			}
			
			Real length = Math::Sqrt(lengthSq);
			
			Vector3 newCenter;
			Real newRadius;
			if ((length + oth.getRadius()) > mRadius) 
			{
				Real t = (length + radiusDiff) / (2.0f * length);
				newCenter = mCenter + diff * t;
			} 
			// otherwise, we keep our existing center
			
			newRadius = 0.5f * (length + mRadius + oth.getRadius());
			
			mCenter = newCenter;
			mRadius = newRadius;
		}
        
    };

}
