// Class automatically generated by Dev-C++ New Class wizard

#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H

#include "engine3d/geometry/spatial.h"
#include "engine3d/geometry/plane.h"
#include "engine3d/geometry/line.h"

using namespace base;

namespace engine3d {
/*
 * No description
 */
class BoundingVolume : public Spatial
{
	public:
		// class constructor
		BoundingVolume();

		// class constructor
		//BoundingVolume(const BoundingVolume& rBound) = 0;
		
		virtual BoundingVolume* Clone() const = 0;
		
		// class destructor
		~BoundingVolume();
		/** 
         * Tests the position of the volume against the
         * given plane. Sub-classes must implement it
		 * @return Plane::PLACEMENT_COINCIDE if the plane intersects the volume, 
         * Plane::PLACEMENT_FRONT if the volume is in the front of the plane 
         * (pointed by the plane normal) or Plane::PLACEMENT_BACK if the volume 
         * is in the back of the plane
		 */
		virtual int WhichSide(const Plane& rPlane) const = 0;
		
		/**
		 * Testis if this volume intersects with given line
		 **/
		virtual bool Intersects(const Line& rLine) const = 0;
		
		virtual bool Collides(const BoundingVolume& rOtherBound) const = 0;
		
};
}
#endif // BOUNDINGVOLUME_H
