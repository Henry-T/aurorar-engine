/********************************************************************
	创建时间:	6:1:2012   0:26
	文件名	:	Plane
	创建者:		丁亮
	
	文件作用:	平面 Ax + By + Cz + D = 0
*********************************************************************/
#pragma once

#include "Vector3.h"
#include "MathLib.h"
#include "UtilLib.h"

namespace Aurora
{

    class MATHLIB_API Plane
    {
    public:
  
        Plane ();
        Plane (const Plane& rhs);
    
        Plane (const Vector3& rkNormal, Real fConstant);
	
		Plane (Real a, Real b, Real c, Real d);
        Plane (const Vector3& rkNormal, const Vector3& rkPoint);
        Plane (const Vector3& rkPoint0, const Vector3& rkPoint1,
            const Vector3& rkPoint2);

        enum Side
        {
            NO_SIDE,
            POSITIVE_SIDE,
            NEGATIVE_SIDE,
            BOTH_SIDE
        };

        Side getSide (const Vector3& rkPoint) const;

        Side getSide (const AxisAlignedBox& rkBox) const;

        Side getSide (const Vector3& centre, const Vector3& halfSize) const;

        Real getDistance (const Vector3& rkPoint) const;

        void redefine(const Vector3& rkPoint0, const Vector3& rkPoint1,
            const Vector3& rkPoint2);

		void redefine(const Vector3& rkNormal, const Vector3& rkPoint);

		Vector3 projectVector(const Vector3& v) const;

        Real normalise(void);

		Vector3 normal;
        Real d;

        bool operator==(const Plane& rhs) const
        {
            return (rhs.d == d && rhs.normal == normal);
        }
        bool operator!=(const Plane& rhs) const
        {
            return (rhs.d != d && rhs.normal != normal);
        }

        MATHLIB_API friend std::ostream& operator<< (std::ostream& o, const Plane& p);
    };

    typedef vector<Plane>::type PlaneList;

}