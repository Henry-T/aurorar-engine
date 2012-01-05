#pragma once

// Precompiler options
#include "Prerequisites.h"
#include "AxisAlignedBox.h"
#include "Sphere.h"
#include "Math.h"
#include "Plane.h"

namespace Aurora 
{

    class CORE_API PlaneBoundedVolume
    {
    public:
        typedef vector<Plane>::type PlaneList;

        PlaneList planes;
        Plane::Side outside;

        PlaneBoundedVolume() :outside(Plane::NEGATIVE_SIDE) {}

        PlaneBoundedVolume(Plane::Side theOutside) 
            : outside(theOutside) {}

        inline bool intersects(const AxisAlignedBox& box) const
        {
            if (box.isNull()) return false;
            if (box.isInfinite()) return true;

            // Get centre of the box
            Vector3 centre = box.getCenter();
            // Get the half-size of the box
            Vector3 halfSize = box.getHalfSize();
            
            PlaneList::const_iterator i, iend;
            iend = planes.end();
            for (i = planes.begin(); i != iend; ++i)
            {
                const Plane& plane = *i;

                Plane::Side side = plane.getSide(centre, halfSize);
                if (side == outside)
                {
                    // Found a splitting plane therefore return not intersecting
                    return false;
                }
            }

            // couldn't find a splitting plane, assume intersecting
            return true;

        }

        inline bool intersects(const Sphere& sphere) const
        {
            PlaneList::const_iterator i, iend;
            iend = planes.end();
            for (i = planes.begin(); i != iend; ++i)
            {
                const Plane& plane = *i;

                // Test which side of the plane the sphere is
                Real d = plane.getDistance(sphere.getCenter());
                // Negate d if planes point inwards
                if (outside == Plane::NEGATIVE_SIDE) d = -d;

                if ( (d - sphere.getRadius()) > 0)
                    return false;
            }

            return true;

        }

        inline std::pair<bool, Real> intersects(const Ray& ray)
        {
            return Math::intersects(ray, planes, outside == Plane::POSITIVE_SIDE);
        }

    };

    typedef vector<PlaneBoundedVolume>::type PlaneBoundedVolumeList;

}
