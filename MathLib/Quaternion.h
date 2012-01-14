/********************************************************************
	创建时间:	6:1:2012   0:32
	文件名	:	Quaternion
	创建者:		丁亮
	
	文件作用:	四元数
*********************************************************************/
#pragma once

#include "MathLib.h"
#include "Math.h"

namespace Aurora 
{

    class MATHLIB_API Quaternion
    {
    public:
        inline Quaternion (
            Real fW = 1.0,
            Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0)
		{
			w = fW;
			x = fX;
			y = fY;
			z = fZ;
		}
 
        inline Quaternion(const Matrix3& rot)
        {
            this->FromRotationMatrix(rot);
        }

        inline Quaternion(const Radian& rfAngle, const Vector3& rkAxis)
        {
            this->FromAngleAxis(rfAngle, rkAxis);
        }

        inline Quaternion(const Vector3& xaxis, const Vector3& yaxis, const Vector3& zaxis)
        {
            this->FromAxes(xaxis, yaxis, zaxis);
        }

        inline Quaternion(const Vector3* akAxis)
        {
            this->FromAxes(akAxis);
        }

		inline Quaternion(Real* valptr)
		{
			memcpy(&w, valptr, sizeof(Real)*4);
		}

		inline void swap(Quaternion& other)
		{
			std::swap(w, other.w);
			std::swap(x, other.x);
			std::swap(y, other.y);
			std::swap(z, other.z);
		}

		inline Real operator [] ( const size_t i ) const
		{
			assert( i < 4 );

			return *(&w+i);
		}

		inline Real& operator [] ( const size_t i )
		{
			assert( i < 4 );

			return *(&w+i);
		}

		inline Real* ptr()
		{
			return &w;
		}

		inline const Real* ptr() const
		{
			return &w;
		}

		void FromRotationMatrix (const Matrix3& kRot);
        void ToRotationMatrix (Matrix3& kRot) const;
        void FromAngleAxis (const Radian& rfAngle, const Vector3& rkAxis);
        void ToAngleAxis (Radian& rfAngle, Vector3& rkAxis) const;
        inline void ToAngleAxis (Degree& dAngle, Vector3& rkAxis) const {
            Radian rAngle;
            ToAngleAxis ( rAngle, rkAxis );
            dAngle = rAngle;
        }
        void FromAxes (const Vector3* akAxis);
        void FromAxes (const Vector3& xAxis, const Vector3& yAxis, const Vector3& zAxis);
        void ToAxes (Vector3* akAxis) const;
        void ToAxes (Vector3& xAxis, Vector3& yAxis, Vector3& zAxis) const;
     
        Vector3 xAxis(void) const;
        Vector3 yAxis(void) const;
        Vector3 zAxis(void) const;

        inline Quaternion& operator= (const Quaternion& rkQ)
		{
			w = rkQ.w;
			x = rkQ.x;
			y = rkQ.y;
			z = rkQ.z;
			return *this;
		}
        Quaternion operator+ (const Quaternion& rkQ) const;
        Quaternion operator- (const Quaternion& rkQ) const;
        Quaternion operator* (const Quaternion& rkQ) const;
        Quaternion operator* (Real fScalar) const;
        MATHLIB_API friend Quaternion operator* (Real fScalar,
            const Quaternion& rkQ);
        Quaternion operator- () const;
        inline bool operator== (const Quaternion& rhs) const
		{
			return (rhs.x == x) && (rhs.y == y) &&
				(rhs.z == z) && (rhs.w == w);
		}
        inline bool operator!= (const Quaternion& rhs) const
		{
			return !operator==(rhs);
		}

        Real Dot (const Quaternion& rkQ) const; 
        Real Norm () const;
        Real normalise(void); 
        Quaternion Inverse () const;
        Quaternion UnitInverse () const; 
        Quaternion Exp () const;
        Quaternion Log () const;

        Vector3 operator* (const Vector3& rkVector) const;

		Radian getRoll(bool reprojectAxis = true) const;
   	
		Radian getPitch(bool reprojectAxis = true) const;
   	
		Radian getYaw(bool reprojectAxis = true) const;		
	
		bool equals(const Quaternion& rhs, const Radian& tolerance) const;

        static Quaternion Slerp (Real fT, const Quaternion& rkP,
            const Quaternion& rkQ, bool shortestPath = false);

        static Quaternion SlerpExtraSpins (Real fT,
            const Quaternion& rkP, const Quaternion& rkQ,
            int iExtraSpins);

        static void Intermediate (const Quaternion& rkQ0,
            const Quaternion& rkQ1, const Quaternion& rkQ2,
            Quaternion& rka, Quaternion& rkB);

        static Quaternion Squad (Real fT, const Quaternion& rkP,
            const Quaternion& rkA, const Quaternion& rkB,
            const Quaternion& rkQ, bool shortestPath = false);

        static Quaternion nlerp(Real fT, const Quaternion& rkP, 
            const Quaternion& rkQ, bool shortestPath = false);

        static const Real ms_fEpsilon;

        static const Quaternion ZERO;
        static const Quaternion IDENTITY;

		Real w, x, y, z;

		inline bool isNaN() const
		{
			return Math::isNaN(x) || Math::isNaN(y) || Math::isNaN(z) || Math::isNaN(w);
		}

        inline MATHLIB_API friend std::ostream& operator <<
            ( std::ostream& o, const Quaternion& q )
        {
            o << "Quaternion(" << q.w << ", " << q.x << ", " << q.y << ", " << q.z << ")";
            return o;
        }

    };

	typedef Quaternion Quat;

}
