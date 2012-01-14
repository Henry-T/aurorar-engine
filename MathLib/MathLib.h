#pragma once

#include "Platform.h"
#include "StdHeaders.h"

#ifdef MATHLIB_EXPORTS
#define MATHLIB_API  __declspec(dllexport)
#else
#define MATHLIB_API  __declspec(dllimport)
#endif


namespace Aurora
{
	class Radian;
	class Degree;
	class Angle;
	class Vector2;
	class Vector3;
	class Vector4;
	class Ray;
	class Plane;
	class Sphere;
	class AxisAlignedBox;
	class Math;
	class Matrix3;
	class Matrix4;
	class Quaternion;
	class PlaneBoundedVolume;
	class ColourValue;
}