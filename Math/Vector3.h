/********************************************************************
	创建时间:	6:1:2012   0:34
	文件名	:	Vector3
	创建者:		丁亮
	
	文件作用:	三维向量
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Math.h"
#include "Quaternion.h"

namespace Aurora
{
    class MATH_API Vector3
    {
    public:
		Real x, y, z;

    public:
        inline Vector3()
        {
        }

        inline Vector3( const Real fX, const Real fY, const Real fZ )
            : x( fX ), y( fY ), z( fZ )
        {
        }

        inline explicit Vector3( const Real afCoordinate[3] )
            : x( afCoordinate[0] ),
              y( afCoordinate[1] ),
              z( afCoordinate[2] )
        {
        }

        inline explicit Vector3( const int afCoordinate[3] )
        {
            x = (Real)afCoordinate[0];
            y = (Real)afCoordinate[1];
            z = (Real)afCoordinate[2];
        }

        inline explicit Vector3( Real* const r )
            : x( r[0] ), y( r[1] ), z( r[2] )
        {
        }

        inline explicit Vector3( const Real scaler )
            : x( scaler )
            , y( scaler )
            , z( scaler )
        {
        }

		inline void swap(Vector3& other)
		{
			std::swap(x, other.x);
			std::swap(y, other.y);
			std::swap(z, other.z);
		}

		inline Real operator [] ( const size_t i ) const
        {
            assert( i < 3 );

            return *(&x+i);
        }

		inline Real& operator [] ( const size_t i )
        {
            assert( i < 3 );

            return *(&x+i);
        }

		inline Real* ptr()
		{
			return &x;
		}

		inline const Real* ptr() const
		{
			return &x;
		}

        inline Vector3& operator = ( const Vector3& rkVector )
        {
            x = rkVector.x;
            y = rkVector.y;
            z = rkVector.z;

            return *this;
        }

        inline Vector3& operator = ( const Real fScaler )
        {
            x = fScaler;
            y = fScaler;
            z = fScaler;

            return *this;
        }

        inline bool operator == ( const Vector3& rkVector ) const
        {
            return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
        }

        inline bool operator != ( const Vector3& rkVector ) const
        {
            return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
        }

        inline Vector3 operator + ( const Vector3& rkVector ) const
        {
            return Vector3(
                x + rkVector.x,
                y + rkVector.y,
                z + rkVector.z);
        }

        inline Vector3 operator - ( const Vector3& rkVector ) const
        {
            return Vector3(
                x - rkVector.x,
                y - rkVector.y,
                z - rkVector.z);
        }

        inline Vector3 operator * ( const Real fScalar ) const
        {
            return Vector3(
                x * fScalar,
                y * fScalar,
                z * fScalar);
        }

        inline Vector3 operator * ( const Vector3& rhs) const
        {
            return Vector3(
                x * rhs.x,
                y * rhs.y,
                z * rhs.z);
        }

        inline Vector3 operator / ( const Real fScalar ) const
        {
            assert( fScalar != 0.0 );

            Real fInv = 1.0f / fScalar;

            return Vector3(
                x * fInv,
                y * fInv,
                z * fInv);
        }

        inline Vector3 operator / ( const Vector3& rhs) const
        {
            return Vector3(
                x / rhs.x,
                y / rhs.y,
                z / rhs.z);
        }

        inline const Vector3& operator + () const
        {
            return *this;
        }

        inline Vector3 operator - () const
        {
            return Vector3(-x, -y, -z);
        }

        inline friend Vector3 operator * ( const Real fScalar, const Vector3& rkVector )
        {
            return Vector3(
                fScalar * rkVector.x,
                fScalar * rkVector.y,
                fScalar * rkVector.z);
        }

        inline friend Vector3 operator / ( const Real fScalar, const Vector3& rkVector )
        {
            return Vector3(
                fScalar / rkVector.x,
                fScalar / rkVector.y,
                fScalar / rkVector.z);
        }

        inline friend Vector3 operator + (const Vector3& lhs, const Real rhs)
        {
            return Vector3(
                lhs.x + rhs,
                lhs.y + rhs,
                lhs.z + rhs);
        }

        inline friend Vector3 operator + (const Real lhs, const Vector3& rhs)
        {
            return Vector3(
                lhs + rhs.x,
                lhs + rhs.y,
                lhs + rhs.z);
        }

        inline friend Vector3 operator - (const Vector3& lhs, const Real rhs)
        {
            return Vector3(
                lhs.x - rhs,
                lhs.y - rhs,
                lhs.z - rhs);
        }

        inline friend Vector3 operator - (const Real lhs, const Vector3& rhs)
        {
            return Vector3(
                lhs - rhs.x,
                lhs - rhs.y,
                lhs - rhs.z);
        }

        inline Vector3& operator += ( const Vector3& rkVector )
        {
            x += rkVector.x;
            y += rkVector.y;
            z += rkVector.z;

            return *this;
        }

        inline Vector3& operator += ( const Real fScalar )
        {
            x += fScalar;
            y += fScalar;
            z += fScalar;
            return *this;
        }

        inline Vector3& operator -= ( const Vector3& rkVector )
        {
            x -= rkVector.x;
            y -= rkVector.y;
            z -= rkVector.z;

            return *this;
        }

        inline Vector3& operator -= ( const Real fScalar )
        {
            x -= fScalar;
            y -= fScalar;
            z -= fScalar;
            return *this;
        }

        inline Vector3& operator *= ( const Real fScalar )
        {
            x *= fScalar;
            y *= fScalar;
            z *= fScalar;
            return *this;
        }

        inline Vector3& operator *= ( const Vector3& rkVector )
        {
            x *= rkVector.x;
            y *= rkVector.y;
            z *= rkVector.z;

            return *this;
        }

        inline Vector3& operator /= ( const Real fScalar )
        {
            assert( fScalar != 0.0 );

            Real fInv = 1.0f / fScalar;

            x *= fInv;
            y *= fInv;
            z *= fInv;

            return *this;
        }

        inline Vector3& operator /= ( const Vector3& rkVector )
        {
            x /= rkVector.x;
            y /= rkVector.y;
            z /= rkVector.z;

            return *this;
        }

        inline Real length () const
        {
            return Math::Sqrt( x * x + y * y + z * z );
        }

        inline Real squaredLength () const
        {
            return x * x + y * y + z * z;
        }

        inline Real distance(const Vector3& rhs) const
        {
            return (*this - rhs).length();
        }

        inline Real squaredDistance(const Vector3& rhs) const
        {
            return (*this - rhs).squaredLength();
        }

        inline Real dotProduct(const Vector3& vec) const
        {
            return x * vec.x + y * vec.y + z * vec.z;
        }

        inline Real absDotProduct(const Vector3& vec) const
        {
            return Math::Abs(x * vec.x) + Math::Abs(y * vec.y) + Math::Abs(z * vec.z);
        }

        inline Real normalise()
        {
            Real fLength = Math::Sqrt( x * x + y * y + z * z );

            // Will also work for zero-sized vectors, but will change nothing
            if ( fLength > 1e-08 )
            {
                Real fInvLength = 1.0f / fLength;
                x *= fInvLength;
                y *= fInvLength;
                z *= fInvLength;
            }

            return fLength;
        }

        inline Vector3 crossProduct( const Vector3& rkVector ) const
        {
            return Vector3(
                y * rkVector.z - z * rkVector.y,
                z * rkVector.x - x * rkVector.z,
                x * rkVector.y - y * rkVector.x);
        }

        inline Vector3 midPoint( const Vector3& vec ) const
        {
            return Vector3(
                ( x + vec.x ) * 0.5f,
                ( y + vec.y ) * 0.5f,
                ( z + vec.z ) * 0.5f );
        }

        inline bool operator < ( const Vector3& rhs ) const
        {
            if( x < rhs.x && y < rhs.y && z < rhs.z )
                return true;
            return false;
        }

        inline bool operator > ( const Vector3& rhs ) const
        {
            if( x > rhs.x && y > rhs.y && z > rhs.z )
                return true;
            return false;
        }

        inline void makeFloor( const Vector3& cmp )
        {
            if( cmp.x < x ) x = cmp.x;
            if( cmp.y < y ) y = cmp.y;
            if( cmp.z < z ) z = cmp.z;
        }

        inline void makeCeil( const Vector3& cmp )
        {
            if( cmp.x > x ) x = cmp.x;
            if( cmp.y > y ) y = cmp.y;
            if( cmp.z > z ) z = cmp.z;
        }

        inline Vector3 perpendicular(void) const
        {
            static const Real fSquareZero = (Real)(1e-06 * 1e-06);

            Vector3 perp = this->crossProduct( Vector3::UNIT_X );

            // Check length
            if( perp.squaredLength() < fSquareZero )
            {
                /* This vector is the Y axis multiplied by a scalar, so we have
                   to use another axis.
                */
                perp = this->crossProduct( Vector3::UNIT_Y );
            }
			perp.normalise();

            return perp;
        }
     
        inline Vector3 randomDeviant(
            const Radian& angle,
            const Vector3& up = Vector3::ZERO ) const
        {
            Vector3 newUp;

            if (up == Vector3::ZERO)
            {
                // Generate an up vector
                newUp = this->perpendicular();
            }
            else
            {
                newUp = up;
            }

            // Rotate up vector by random amount around this
            Quaternion q;
            q.FromAngleAxis( Radian(Math::UnitRandom() * Math::TWO_PI), *this );
            newUp = q * newUp;

            // Finally rotate this by given angle around randomised up
            q.FromAngleAxis( angle, newUp );
            return q * (*this);
        }

		inline Radian angleBetween(const Vector3& dest)
		{
			Real lenProduct = length() * dest.length();

			// Divide by zero check
			if(lenProduct < 1e-6f)
				lenProduct = 1e-6f;

			Real f = dotProduct(dest) / lenProduct;

			f = Math::Clamp(f, (Real)-1.0, (Real)1.0);
			return Math::ACos(f);

		}
    
        Quaternion getRotationTo(const Vector3& dest,
			const Vector3& fallbackAxis = Vector3::ZERO) const
        {
            // Based on Stan Melax's article in Game Programming Gems
            Quaternion q;
            // Copy, since cannot modify local
            Vector3 v0 = *this;
            Vector3 v1 = dest;
            v0.normalise();
            v1.normalise();

            Real d = v0.dotProduct(v1);
            // If dot == 1, vectors are the same
            if (d >= 1.0f)
            {
                return Quaternion::IDENTITY;
            }
			if (d < (1e-6f - 1.0f))
			{
				if (fallbackAxis != Vector3::ZERO)
				{
					// rotate 180 degrees about the fallback axis
					q.FromAngleAxis(Radian(Math::PI), fallbackAxis);
				}
				else
				{
					// Generate an axis
					Vector3 axis = Vector3::UNIT_X.crossProduct(*this);
					if (axis.isZeroLength()) // pick another if colinear
						axis = Vector3::UNIT_Y.crossProduct(*this);
					axis.normalise();
					q.FromAngleAxis(Radian(Math::PI), axis);
				}
			}
			else
			{
                Real s = Math::Sqrt( (1+d)*2 );
	            Real invs = 1 / s;

				Vector3 c = v0.crossProduct(v1);

    	        q.x = c.x * invs;
        	    q.y = c.y * invs;
            	q.z = c.z * invs;
            	q.w = s * 0.5f;
				q.normalise();
			}
            return q;
        }

        inline bool isZeroLength(void) const
        {
            Real sqlen = (x * x) + (y * y) + (z * z);
            return (sqlen < (1e-06 * 1e-06));

        }

        inline Vector3 normalisedCopy(void) const
        {
            Vector3 ret = *this;
            ret.normalise();
            return ret;
        }

        inline Vector3 reflect(const Vector3& normal) const
        {
            return Vector3( *this - ( 2 * this->dotProduct(normal) * normal ) );
        }

		inline bool positionEquals(const Vector3& rhs, Real tolerance = 1e-03) const
		{
			return Math::RealEqual(x, rhs.x, tolerance) &&
				Math::RealEqual(y, rhs.y, tolerance) &&
				Math::RealEqual(z, rhs.z, tolerance);

		}

		inline bool positionCloses(const Vector3& rhs, Real tolerance = 1e-03f) const
		{
			return squaredDistance(rhs) <=
                (squaredLength() + rhs.squaredLength()) * tolerance;
		}

		inline bool directionEquals(const Vector3& rhs,
			const Radian& tolerance) const
		{
			Real dot = dotProduct(rhs);
			Radian angle = Math::ACos(dot);

			return Math::Abs(angle.valueRadians()) <= tolerance.valueRadians();

		}

		/// Check whether this vector contains valid values
		inline bool isNaN() const
		{
			return Math::isNaN(x) || Math::isNaN(y) || Math::isNaN(z);
		}

		// special points
        static const Vector3 ZERO;
        static const Vector3 UNIT_X;
        static const Vector3 UNIT_Y;
        static const Vector3 UNIT_Z;
        static const Vector3 NEGATIVE_UNIT_X;
        static const Vector3 NEGATIVE_UNIT_Y;
        static const Vector3 NEGATIVE_UNIT_Z;
        static const Vector3 UNIT_SCALE;

        inline MATH_API friend std::ostream& operator <<
            ( std::ostream& o, const Vector3& v )
        {
            o << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
            return o;
        }
    };

	typedef Vector3 Point3D;
	typedef Vector3 float3;

}
