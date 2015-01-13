// Class automatically generated by Dev-C++ New Class wizard

#ifndef BOUNDINGPOLYGON_H
#define BOUNDINGPOLYGON_H

#include "boundingvolume.h" // inheriting class's header file
#include "engine3d/geometry/vector.h"
#include "base/arraylist.h"

namespace engine3d {
    /**
     * This class represents the convex polygon for
     * model bounding 
     **/
    class BoundingPolygon : public BoundingVolume
    {
    	public:
    		BoundingPolygon() {}
    		/**
    		 * Constructs bounding polygon from 
    		 * the given array of vertices
    		 **/
    		BoundingPolygon(Vector vertices[], int number);
    		
    		BoundingPolygon* Clone() const;
    		
    		// class destructor
    		~BoundingPolygon();
    		
    		void AddVertex(const Vector& rVertex);

		    int WhichSide(const Plane& rPlane) const;

            bool Intersects(const Line& rLine) const;
		
    		bool Collides(const BoundingVolume& rOtherBound) const;
    		
    		void Transform();
		private:
            ArrayList<Vector> mVertices;
            ArrayList<Vector> mTransformedVertices;
    };
}

#endif // BOUNDINGPOLYGON_H