/********************************************************************
	创建时间:	6:1:2012   0:26
	文件名	:	Matrix4
	创建者:		丁亮
	
	文件作用:	4X4矩阵
*********************************************************************/
#pragma once

#include "Prerequisites.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Vector4.h"
#include "Plane.h"

namespace Aurora
{

    class MATH_API Matrix4
    {
    protected:

        union {
            Real m[4][4];
            Real _m[16];
        };
    public:

        inline Matrix4()
        {
        }

        inline Matrix4(
            Real m00, Real m01, Real m02, Real m03,
            Real m10, Real m11, Real m12, Real m13,
            Real m20, Real m21, Real m22, Real m23,
            Real m30, Real m31, Real m32, Real m33 )
        {
            m[0][0] = m00;
            m[0][1] = m01;
            m[0][2] = m02;
            m[0][3] = m03;
            m[1][0] = m10;
            m[1][1] = m11;
            m[1][2] = m12;
            m[1][3] = m13;
            m[2][0] = m20;
            m[2][1] = m21;
            m[2][2] = m22;
            m[2][3] = m23;
            m[3][0] = m30;
            m[3][1] = m31;
            m[3][2] = m32;
            m[3][3] = m33;
        }

        inline Matrix4(const Matrix3& m3x3)
        {
          operator=(IDENTITY);
          operator=(m3x3);
        }

        inline Matrix4(const Quaternion& rot)
        {
          Matrix3 m3x3;
          rot.ToRotationMatrix(m3x3);
          operator=(IDENTITY);
          operator=(m3x3);
        }

		inline void swap(Matrix4& other)
		{
			std::swap(m[0][0], other.m[0][0]);
			std::swap(m[0][1], other.m[0][1]);
			std::swap(m[0][2], other.m[0][2]);
			std::swap(m[0][3], other.m[0][3]);
			std::swap(m[1][0], other.m[1][0]);
			std::swap(m[1][1], other.m[1][1]);
			std::swap(m[1][2], other.m[1][2]);
			std::swap(m[1][3], other.m[1][3]);
			std::swap(m[2][0], other.m[2][0]);
			std::swap(m[2][1], other.m[2][1]);
			std::swap(m[2][2], other.m[2][2]);
			std::swap(m[2][3], other.m[2][3]);
			std::swap(m[3][0], other.m[3][0]);
			std::swap(m[3][1], other.m[3][1]);
			std::swap(m[3][2], other.m[3][2]);
			std::swap(m[3][3], other.m[3][3]);
		}

		inline Real* operator [] ( size_t iRow )
        {
            assert( iRow < 4 );
            return m[iRow];
        }

        inline const Real *operator [] ( size_t iRow ) const
        {
            assert( iRow < 4 );
            return m[iRow];
        }

        inline Matrix4 concatenate(const Matrix4 &m2) const
        {
            Matrix4 r;
            r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0] + m[0][3] * m2.m[3][0];
            r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1] + m[0][3] * m2.m[3][1];
            r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2] + m[0][3] * m2.m[3][2];
            r.m[0][3] = m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3] * m2.m[3][3];

            r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0] + m[1][3] * m2.m[3][0];
            r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1] + m[1][3] * m2.m[3][1];
            r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2] + m[1][3] * m2.m[3][2];
            r.m[1][3] = m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3] * m2.m[3][3];

            r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0] + m[2][3] * m2.m[3][0];
            r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1] + m[2][3] * m2.m[3][1];
            r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2] + m[2][3] * m2.m[3][2];
            r.m[2][3] = m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3] * m2.m[3][3];

            r.m[3][0] = m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2] * m2.m[2][0] + m[3][3] * m2.m[3][0];
            r.m[3][1] = m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2] * m2.m[2][1] + m[3][3] * m2.m[3][1];
            r.m[3][2] = m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2] * m2.m[2][2] + m[3][3] * m2.m[3][2];
            r.m[3][3] = m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2] * m2.m[2][3] + m[3][3] * m2.m[3][3];

            return r;
        }

        inline Matrix4 operator * ( const Matrix4 &m2 ) const
        {
            return concatenate( m2 );
        }

        inline Vector3 operator * ( const Vector3 &v ) const
        {
            Vector3 r;

            Real fInvW = 1.0f / ( m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] );

            r.x = ( m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] ) * fInvW;
            r.y = ( m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] ) * fInvW;
            r.z = ( m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] ) * fInvW;

            return r;
        }
        inline Vector4 operator * (const Vector4& v) const
        {
            return Vector4(
                m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w, 
                m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
                m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
                m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w
                );
        }
        inline Plane operator * (const Plane& p) const
        {
            Plane ret;
			Matrix4 invTrans = inverse().transpose();
			Vector4 v4( p.normal.x, p.normal.y, p.normal.z, p.d );
			v4 = invTrans * v4;
			ret.normal.x = v4.x; 
			ret.normal.y = v4.y; 
			ret.normal.z = v4.z;
			ret.d = v4.w / ret.normal.normalise();

            return ret;
        }

        inline Matrix4 operator + ( const Matrix4 &m2 ) const
        {
            Matrix4 r;

            r.m[0][0] = m[0][0] + m2.m[0][0];
            r.m[0][1] = m[0][1] + m2.m[0][1];
            r.m[0][2] = m[0][2] + m2.m[0][2];
            r.m[0][3] = m[0][3] + m2.m[0][3];

            r.m[1][0] = m[1][0] + m2.m[1][0];
            r.m[1][1] = m[1][1] + m2.m[1][1];
            r.m[1][2] = m[1][2] + m2.m[1][2];
            r.m[1][3] = m[1][3] + m2.m[1][3];

            r.m[2][0] = m[2][0] + m2.m[2][0];
            r.m[2][1] = m[2][1] + m2.m[2][1];
            r.m[2][2] = m[2][2] + m2.m[2][2];
            r.m[2][3] = m[2][3] + m2.m[2][3];

            r.m[3][0] = m[3][0] + m2.m[3][0];
            r.m[3][1] = m[3][1] + m2.m[3][1];
            r.m[3][2] = m[3][2] + m2.m[3][2];
            r.m[3][3] = m[3][3] + m2.m[3][3];

            return r;
        }

        inline Matrix4 operator - ( const Matrix4 &m2 ) const
        {
            Matrix4 r;
            r.m[0][0] = m[0][0] - m2.m[0][0];
            r.m[0][1] = m[0][1] - m2.m[0][1];
            r.m[0][2] = m[0][2] - m2.m[0][2];
            r.m[0][3] = m[0][3] - m2.m[0][3];

            r.m[1][0] = m[1][0] - m2.m[1][0];
            r.m[1][1] = m[1][1] - m2.m[1][1];
            r.m[1][2] = m[1][2] - m2.m[1][2];
            r.m[1][3] = m[1][3] - m2.m[1][3];

            r.m[2][0] = m[2][0] - m2.m[2][0];
            r.m[2][1] = m[2][1] - m2.m[2][1];
            r.m[2][2] = m[2][2] - m2.m[2][2];
            r.m[2][3] = m[2][3] - m2.m[2][3];

            r.m[3][0] = m[3][0] - m2.m[3][0];
            r.m[3][1] = m[3][1] - m2.m[3][1];
            r.m[3][2] = m[3][2] - m2.m[3][2];
            r.m[3][3] = m[3][3] - m2.m[3][3];

            return r;
        }

        inline bool operator == ( const Matrix4& m2 ) const
        {
            if( 
                m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
                m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[1][2] || m[1][3] != m2.m[1][3] ||
                m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[2][2] || m[2][3] != m2.m[2][3] ||
                m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[3][2] || m[3][3] != m2.m[3][3] )
                return false;
            return true;
        }

        inline bool operator != ( const Matrix4& m2 ) const
        {
            if( 
                m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
                m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[1][2] || m[1][3] != m2.m[1][3] ||
                m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[2][2] || m[2][3] != m2.m[2][3] ||
                m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[3][2] || m[3][3] != m2.m[3][3] )
                return true;
            return false;
        }

        inline void operator = ( const Matrix3& mat3 )
        {
            m[0][0] = mat3.m[0][0]; m[0][1] = mat3.m[0][1]; m[0][2] = mat3.m[0][2];
            m[1][0] = mat3.m[1][0]; m[1][1] = mat3.m[1][1]; m[1][2] = mat3.m[1][2];
            m[2][0] = mat3.m[2][0]; m[2][1] = mat3.m[2][1]; m[2][2] = mat3.m[2][2];
        }

        inline Matrix4 transpose(void) const
        {
            return Matrix4(m[0][0], m[1][0], m[2][0], m[3][0],
                           m[0][1], m[1][1], m[2][1], m[3][1],
                           m[0][2], m[1][2], m[2][2], m[3][2],
                           m[0][3], m[1][3], m[2][3], m[3][3]);
        }

        inline void setTrans( const Vector3& v )
        {
            m[0][3] = v.x;
            m[1][3] = v.y;
            m[2][3] = v.z;
        }

        inline Vector3 getTrans() const
        {
          return Vector3(m[0][3], m[1][3], m[2][3]);
        }
   
        inline void makeTrans( const Vector3& v )
        {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = v.x;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = v.y;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = v.z;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }

        inline void makeTrans( Real tx, Real ty, Real tz )
        {
            m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = tx;
            m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = ty;
            m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = tz;
            m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
        }

        inline static Matrix4 getTrans( const Vector3& v )
        {
            Matrix4 r;

            r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = v.x;
            r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = v.y;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = v.z;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        inline static Matrix4 getTrans( Real t_x, Real t_y, Real t_z )
        {
            Matrix4 r;

            r.m[0][0] = 1.0; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = t_x;
            r.m[1][0] = 0.0; r.m[1][1] = 1.0; r.m[1][2] = 0.0; r.m[1][3] = t_y;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = 1.0; r.m[2][3] = t_z;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        inline void setScale( const Vector3& v )
        {
            m[0][0] = v.x;
            m[1][1] = v.y;
            m[2][2] = v.z;
        }

        inline static Matrix4 getScale( const Vector3& v )
        {
            Matrix4 r;
            r.m[0][0] = v.x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
            r.m[1][0] = 0.0; r.m[1][1] = v.y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = v.z; r.m[2][3] = 0.0;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        inline static Matrix4 getScale( Real s_x, Real s_y, Real s_z )
        {
            Matrix4 r;
            r.m[0][0] = s_x; r.m[0][1] = 0.0; r.m[0][2] = 0.0; r.m[0][3] = 0.0;
            r.m[1][0] = 0.0; r.m[1][1] = s_y; r.m[1][2] = 0.0; r.m[1][3] = 0.0;
            r.m[2][0] = 0.0; r.m[2][1] = 0.0; r.m[2][2] = s_z; r.m[2][3] = 0.0;
            r.m[3][0] = 0.0; r.m[3][1] = 0.0; r.m[3][2] = 0.0; r.m[3][3] = 1.0;

            return r;
        }

        inline void extract3x3Matrix(Matrix3& m3x3) const
        {
            m3x3.m[0][0] = m[0][0];
            m3x3.m[0][1] = m[0][1];
            m3x3.m[0][2] = m[0][2];
            m3x3.m[1][0] = m[1][0];
            m3x3.m[1][1] = m[1][1];
            m3x3.m[1][2] = m[1][2];
            m3x3.m[2][0] = m[2][0];
            m3x3.m[2][1] = m[2][1];
            m3x3.m[2][2] = m[2][2];

        }

		inline bool hasScale() const
		{
			// check magnitude of column vectors (==local axes)
			Real t = m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0];
			if (!Math::RealEqual(t, 1.0, (Real)1e-04))
				return true;
			t = m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1];
			if (!Math::RealEqual(t, 1.0, (Real)1e-04))
				return true;
			t = m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2];
			if (!Math::RealEqual(t, 1.0, (Real)1e-04))
				return true;

			return false;
		}

		inline bool hasNegativeScale() const
		{
			return determinant() < 0;
		}

        inline Quaternion extractQuaternion() const
        {
          Matrix3 m3x3;
          extract3x3Matrix(m3x3);
          return Quaternion(m3x3);
        }

        static const Matrix4 ZERO;
        static const Matrix4 IDENTITY;
      
        static const Matrix4 CLIPSPACE2DTOIMAGESPACE;

        inline Matrix4 operator*(Real scalar) const
        {
            return Matrix4(
                scalar*m[0][0], scalar*m[0][1], scalar*m[0][2], scalar*m[0][3],
                scalar*m[1][0], scalar*m[1][1], scalar*m[1][2], scalar*m[1][3],
                scalar*m[2][0], scalar*m[2][1], scalar*m[2][2], scalar*m[2][3],
                scalar*m[3][0], scalar*m[3][1], scalar*m[3][2], scalar*m[3][3]);
        }

        inline MATH_API friend std::ostream& operator <<
            ( std::ostream& o, const Matrix4& m )
        {
            o << "Matrix4(";
			for (size_t i = 0; i < 4; ++i)
            {
                o << " row" << (unsigned)i << "{";
                for(size_t j = 0; j < 4; ++j)
                {
                    o << m[i][j] << " ";
                }
                o << "}";
            }
            o << ")";
            return o;
        }
		
		Matrix4 adjoint() const;
		Real determinant() const;
		Matrix4 inverse() const;

        void makeTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation);

        void makeInverseTransform(const Vector3& position, const Vector3& scale, const Quaternion& orientation);

        void decomposition(Vector3& position, Vector3& scale, Quaternion& orientation) const;

        inline bool isAffine(void) const
        {
            return m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
        }

        Matrix4 inverseAffine(void) const;

        inline Matrix4 concatenateAffine(const Matrix4 &m2) const
        {
            assert(isAffine() && m2.isAffine());

            return Matrix4(
                m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0],
                m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1],
                m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2],
                m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3],

                m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0],
                m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1],
                m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2],
                m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3],

                m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0],
                m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1],
                m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2],
                m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3],

                0, 0, 0, 1);
        }

        inline Vector3 transformAffine(const Vector3& v) const
        {
            assert(isAffine());

            return Vector3(
                    m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3], 
                    m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3],
                    m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3]);
        }

        inline Vector4 transformAffine(const Vector4& v) const
        {
            assert(isAffine());

            return Vector4(
                m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w, 
                m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
                m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
                v.w);
        }
    };

    inline Vector4 operator * (const Vector4& v, const Matrix4& mat)
    {
        return Vector4(
            v.x*mat[0][0] + v.y*mat[1][0] + v.z*mat[2][0] + v.w*mat[3][0],
            v.x*mat[0][1] + v.y*mat[1][1] + v.z*mat[2][1] + v.w*mat[3][1],
            v.x*mat[0][2] + v.y*mat[1][2] + v.z*mat[2][2] + v.w*mat[3][2],
            v.x*mat[0][3] + v.y*mat[1][3] + v.z*mat[2][3] + v.w*mat[3][3]
            );
    }

	typedef Matrix4 float4x4;

}
