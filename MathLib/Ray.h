/********************************************************************
	创建时间:	6:1:2012   0:32
	文件名	:	Ray
	创建者:		丁亮
	
	文件作用:	射线
*********************************************************************/

#pragma once

#include "MathLib.h"
#include "Vector3.h"
#include "PlaneBoundedVolume.h"

namespace Aurora 
{

    class MATHLIB_API Ray
    {
    protected:
        Vector3 mOrigin;
        Vector3 mDirection;
    public:
        Ray():mOrigin(Vector3::ZERO), mDirection(Vector3::UNIT_Z) {}
        Ray(const Vector3& origin, const Vector3& direction)
            :mOrigin(origin), mDirection(direction) {}

        void setOrigin(const Vector3& origin) {mOrigin = origin;} 

        const Vector3& getOrigin(void) const {return mOrigin;} 

        void setDirection(const Vector3& dir) {mDirection = dir;} 

        const Vector3& getDirection(void) const {return mDirection;} 

		Vector3 getPoint(Real t) const { 
			return Vector3(mOrigin + (mDirection * t));
		}

		Vector3 operator*(Real t) const { 
			return getPoint(t);
		}

		std::pair<bool, Real> intersects(const Plane& p) const
		{
			return Math::intersects(*this, p);
		}

        std::pair<bool, Real> intersects(const PlaneBoundedVolume& p) const
        {
            return Math::intersects(*this, p.planes, p.outside == Plane::POSITIVE_SIDE);
        }

		std::pair<bool, Real> intersects(const Sphere& s) const
		{
			return Math::intersects(*this, s);
		}

		std::pair<bool, Real> intersects(const AxisAlignedBox& box) const
		{
			return Math::intersects(*this, box);
		}

    };

}
