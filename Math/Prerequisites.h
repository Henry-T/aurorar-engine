#pragma once

#include "../Common/Prerequisites.h"
#include "MathHeader.h"

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
}

namespace Aurora
{
	typedef boost::shared_ptr<Radian>				RadianPtr;
	typedef boost::shared_ptr<Degree>				DegreePtr;
	typedef boost::shared_ptr<Angle>				AnglePtr;
	typedef boost::shared_ptr<Vector2>				Vector2Ptr;
	typedef boost::shared_ptr<Vector3>				Vector3Ptr;
	typedef boost::shared_ptr<Vector4>				Vector4Ptr;
	typedef boost::shared_ptr<Ray>					RayPtr;
	typedef boost::shared_ptr<Plane>				PlanePtr;
	typedef boost::shared_ptr<Sphere>				SpherePtr;
	typedef boost::shared_ptr<AxisAlignedBox>		AxisAlignedBoxPtr;
	typedef boost::shared_ptr<Math>					MathPtr;
	typedef boost::shared_ptr<Matrix3>				Matrix3Ptr;
	typedef boost::shared_ptr<Matrix4>				Matrix4Ptr;
	typedef boost::shared_ptr<Quaternion>			QuaternionPtr;
	typedef boost::shared_ptr<PlaneBoundedVolume>	PlaneBoundedVolumePtr;
}