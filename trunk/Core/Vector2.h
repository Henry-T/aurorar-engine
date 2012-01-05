#pragma once

#include "Prerequisites.h"
#include "Math.h"

namespace Aurora
{
    class CORE_API Vector2
    {
    public:
        Real x, y;

    public:
        inline Vector2()
        {
        }

        inline Vector2(const Real fX, const Real fY )
            : x( fX ), y( fY )
        {
        }

        inline explicit Vector2( const Real scaler )
            : x( scaler), y( scaler )
        {
        }

        inline explicit Vector2( const Real afCoordinate[2] )
            : x( afCoordinate[0] ),
              y( afCoordinate[1] )
        {
        }

        inline explicit Vector2( const int afCoordinate[2] )
        {
            x = (Real)afCoordinate[0];
            y = (Real)afCoordinate[1];
        }

        inline explicit Vector2( Real* const r )
            : x( r[0] ), y( r[1] )
        {
        }

		inline void swap(Vector2& other)
		{
			std::swap(x, other.x);
			std::swap(y, other.y);
		}

		inline Real operator [] ( const size_t i ) const
        {
            assert( i < 2 );

            return *(&x+i);
        }

		inline Real& operator [] ( const size_t i )
        {
            assert( i < 2 );

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

        inline Vector2& operator = ( const Vector2& rkVector )
        {
            x = rkVector.x;
            y = rkVector.y;

            return *this;
        }

		inline Vector2& operator = ( const Real fScalar)
		{
			x = fScalar;
			y = fScalar;

			return *this;
		}

        inline bool operator == ( const Vector2& rkVector ) const
        {
            return ( x == rkVector.x && y == rkVector.y );
        }

        inline bool operator != ( const Vector2& rkVector ) const
        {
            return ( x != rkVector.x || y != rkVector.y  );
        }

        inline Vector2 operator + ( const Vector2& rkVector ) const
        {
            return Vector2(
                x + rkVector.x,
                y + rkVector.y);
        }

        inline Vector2 operator - ( const Vector2& rkVector ) const
        {
            return Vector2(
                x - rkVector.x,
                y - rkVector.y);
        }

        inline Vector2 operator * ( const Real fScalar ) const
        {
            return Vector2(
                x * fScalar,
                y * fScalar);
        }

        inline Vector2 operator * ( const Vector2& rhs) const
        {
            return Vector2(
                x * rhs.x,
                y * rhs.y);
        }

        inline Vector2 operator / ( const Real fScalar ) const
        {
            assert( fScalar != 0.0 );

            Real fInv = 1.0f / fScalar;

            return Vector2(
                x * fInv,
                y * fInv);
        }

        inline Vector2 operator / ( const Vector2& rhs) const
        {
            return Vector2(
                x / rhs.x,
                y / rhs.y);
        }

        inline const Vector2& operator + () const
        {
            return *this;
        }

        inline Vector2 operator - () const
        {
            return Vector2(-x, -y);
        }

        inline friend Vector2 operator * ( const Real fScalar, const Vector2& rkVector )
        {
            return Vector2(
                fScalar * rkVector.x,
                fScalar * rkVector.y);
        }

        inline friend Vector2 operator / ( const Real fScalar, const Vector2& rkVector )
        {
            return Vector2(
                fScalar / rkVector.x,
                fScalar / rkVector.y);
        }

        inline friend Vector2 operator + (const Vector2& lhs, const Real rhs)
        {
            return Vector2(
                lhs.x + rhs,
                lhs.y + rhs);
        }

        inline friend Vector2 operator + (const Real lhs, const Vector2& rhs)
        {
            return Vector2(
                lhs + rhs.x,
                lhs + rhs.y);
        }

        inline friend Vector2 operator - (const Vector2& lhs, const Real rhs)
        {
            return Vector2(
                lhs.x - rhs,
                lhs.y - rhs);
        }

        inline friend Vector2 operator - (const Real lhs, const Vector2& rhs)
        {
            return Vector2(
                lhs - rhs.x,
                lhs - rhs.y);
        }

        inline Vector2& operator += ( const Vector2& rkVector )
        {
            x += rkVector.x;
            y += rkVector.y;

            return *this;
        }

        inline Vector2& operator += ( const Real fScaler )
        {
            x += fScaler;
            y += fScaler;

            return *this;
        }

        inline Vector2& operator -= ( const Vector2& rkVector )
        {
            x -= rkVector.x;
            y -= rkVector.y;

            return *this;
        }

        inline Vector2& operator -= ( const Real fScaler )
        {
            x -= fScaler;
            y -= fScaler;

            return *this;
        }

        inline Vector2& operator *= ( const Real fScalar )
        {
            x *= fScalar;
            y *= fScalar;

            return *this;
        }

        inline Vector2& operator *= ( const Vector2& rkVector )
        {
            x *= rkVector.x;
            y *= rkVector.y;

            return *this;
        }

        inline Vector2& operator /= ( const Real fScalar )
        {
            assert( fScalar != 0.0 );

            Real fInv = 1.0f / fScalar;

            x *= fInv;
            y *= fInv;

            return *this;
        }

        inline Vector2& operator /= ( const Vector2& rkVector )
        {
            x /= rkVector.x;
            y /= rkVector.y;

            return *this;
        }

        inline Real length () const
        {
            return Math::Sqrt( x * x + y * y );
        }

        inline Real squaredLength () const
        {
            return x * x + y * y;
        }

        inline Real distance(const Vector2& rhs) const
        {
            return (*this - rhs).length();
        }

        inline Real squaredDistance(const Vector2& rhs) const
        {
            return (*this - rhs).squaredLength();
        }

        inline Real dotProduct(const Vector2& vec) const
        {
            return x * vec.x + y * vec.y;
        }

        inline Real normalise()
        {
            Real fLength = Math::Sqrt( x * x + y * y);

            // Will also work for zero-sized vectors, but will change nothing
            if ( fLength > 1e-08 )
            {
                Real fInvLength = 1.0f / fLength;
                x *= fInvLength;
                y *= fInvLength;
            }

            return fLength;
        }

        inline Vector2 midPoint( const Vector2& vec ) const
        {
            return Vector2(
                ( x + vec.x ) * 0.5f,
                ( y + vec.y ) * 0.5f );
        }

        inline bool operator < ( const Vector2& rhs ) const
        {
            if( x < rhs.x && y < rhs.y )
                return true;
            return false;
        }

        inline bool operator > ( const Vector2& rhs ) const
        {
            if( x > rhs.x && y > rhs.y )
                return true;
            return false;
        }

        inline void makeFloor( const Vector2& cmp )
        {
            if( cmp.x < x ) x = cmp.x;
            if( cmp.y < y ) y = cmp.y;
        }

        inline void makeCeil( const Vector2& cmp )
        {
            if( cmp.x > x ) x = cmp.x;
            if( cmp.y > y ) y = cmp.y;
        }

        inline Vector2 perpendicular(void) const
        {
            return Vector2 (-y, x);
        }

        inline Real crossProduct( const Vector2& rkVector ) const
        {
            return x * rkVector.y - y * rkVector.x;
        }

        inline Vector2 randomDeviant(
            Real angle) const
        {

            angle *=  Math::UnitRandom() * Math::TWO_PI;
            Real cosa = cos(angle);
            Real sina = sin(angle);
            return  Vector2(cosa * x - sina * y,
                            sina * x + cosa * y);
        }

        inline bool isZeroLength(void) const
        {
            Real sqlen = (x * x) + (y * y);
            return (sqlen < (1e-06 * 1e-06));

        }

        inline Vector2 normalisedCopy(void) const
        {
            Vector2 ret = *this;
            ret.normalise();
            return ret;
        }

        inline Vector2 reflect(const Vector2& normal) const
        {
            return Vector2( *this - ( 2 * this->dotProduct(normal) * normal ) );
        }
		/// Check whether this vector contains valid values
		inline bool isNaN() const
		{
			return Math::isNaN(x) || Math::isNaN(y);
		}

        static const Vector2 ZERO;
        static const Vector2 UNIT_X;
        static const Vector2 UNIT_Y;
        static const Vector2 NEGATIVE_UNIT_X;
        static const Vector2 NEGATIVE_UNIT_Y;
        static const Vector2 UNIT_SCALE;

        inline CORE_API friend std::ostream& operator <<
            ( std::ostream& o, const Vector2& v )
        {
            o << "Vector2(" << v.x << ", " << v.y <<  ")";
            return o;
        }

    };

}
