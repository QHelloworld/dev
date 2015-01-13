// Class automatically generated by Dev-C++ New Class wizard

#include <gl.h>

#include "trianglestrip.h" // class's header file
#include "engine3d/geometry/projection.h" // class's header file
#include "engine3d/geometry/triangle.h" // class's header file
#include "engine3d/scenegraph/scene.h" // class's header file
#include "engine3d/scenegraph/camera.h" // class's header file

using namespace engine3d;
// class constructor
TriangleStrip::TriangleStrip() : Mesh(GL_TRIANGLE_STRIP)
{
	// insert your code here
}

void TriangleStrip::Copy(const TriangleStrip& ts)
{
    Mesh::Copy(ts);
}

TriangleStrip* TriangleStrip::Clone() const
{
    Debug("TriangleStrip.Clone");
    TriangleStrip* p_ts = new TriangleStrip();
    p_ts->Copy(*this);
    return p_ts;
}

// class destructor
TriangleStrip::~TriangleStrip()
{
	// insert your code here
}

void TriangleStrip::Render() 
{
//    if (distant) {
//        Debug("TriangleStrip::Draw 1");
//        Shape* s = GetDistantProjection();
//        s->Render();
//       delete s;
//    }
//    else {
        //Debug("TS::D 2");
        Mesh::Render();
//    }
}

/*
 * Projects the front face of the vertices to the far plane 
 * of the clipping area
 */
void TriangleStrip::RenderDistant()
{
    Shape shape;
    Debug("TS::RD 1");
    Debug("TS::RD 2");
	Plane plane = GetScene().GetCamera().GetFarPlane();
	// NB!!! plane normal is pointing isnide the view
	// frustrum, so this is not the plane we want
    Debug("TS::RD 3");
	Projection p;
    Debug("TS::RD 4");
	p.AddPlane(plane);
    Debug("TS::RD 5");
	//p.SetDirection(plane.GetNormal());
    Debug("TS::RD 6");
    bool first = true;
    TriangleStrip* distantProjection;
	for (int i = 2; i < mChildren.Size(); i++) {
        Debug("TS::RD 7");
        Vertex* v1 = static_cast<Vertex*>(mChildren[i - 2]);
        Debug("TS::RD 8");
        Vertex* v2 = static_cast<Vertex*>(mChildren[i - 1]);
        Debug("TS::RD 9");
        Vertex* v3 = static_cast<Vertex*>(mChildren[i]);
        Debug("TS::RD 10");

        Debug((String) "TS::RD v1: " + v1->GetWorldCoords()[0] + ", " + v1->GetWorldCoords()[1] + ", " + v1->GetWorldCoords()[2]);
        Debug((String) "TS::RD v2: " + v2->GetWorldCoords()[0] + ", " + v2->GetWorldCoords()[1] + ", " + v2->GetWorldCoords()[2]);
        Debug((String) "TS::RD v3: " + v3->GetWorldCoords()[0] + ", " + v3->GetWorldCoords()[1] + ", " + v3->GetWorldCoords()[2]);
        
        Triangle t(v1->GetWorldCoords(), v2->GetWorldCoords(), v3->GetWorldCoords());
        Debug("TS::RD 11");
        
        Vector dir = v1->GetWorldCoords() - GetScene().GetCamera().GetEye();
        
        if ((i % 2 == 0) && /*plane.GetNormal()*/dir.DotProduct(t.GetNormal()) <= 0 ||
        (i % 2 != 0) && /*plane.GetNormal()*/dir.DotProduct(t.GetNormal()) >= 0) {
            Debug("TS::RD 12");

        	Vector direction = v1->GetWorldCoords() - GetScene().GetCamera().GetEye();
        	if (direction.DotProduct(plane.GetNormal()) > GetScene().GetCamera().GetZFar()) {
        		direction = direction * -1.0;
                Debug("TS::RD 120");
        	}
            Debug("TS::RD 121");
	        p.SetDirection(direction);
            Debug("TS::RD 122");
            Vector distantVector1 = p.Project(v1->GetWorldCoords());
            Debug("TS::RD 123");
            direction = v2->GetWorldCoords() - GetScene().GetCamera().GetEye();
        	if (direction.DotProduct(plane.GetNormal()) > GetScene().GetCamera().GetZFar()) {
        		direction = direction * -1.0;
                Debug("TS::RD 1235");
        	}
            Debug("TS::RD 124");
	        p.SetDirection(direction);
            Debug("TS::RD 125");
            Vector distantVector2 = p.Project(v2->GetWorldCoords());
            Debug("TS::RD 126");
            direction = v3->GetWorldCoords() - GetScene().GetCamera().GetEye();
        	if (direction.DotProduct(plane.GetNormal()) > GetScene().GetCamera().GetZFar()) {
        		direction = direction * -1.0;
                Debug("TS::RD 1265");
        	}
            Debug("TS::RD 127");
	        p.SetDirection(direction);
            Debug("TS::RD 128");
            Vector distantVector3 = p.Project(v3->GetWorldCoords());
            Debug("TS::RD 129");
            
            //distantVector1 = distantVector1 - (distantVector1 - GetScene().GetCamera().GetCenter()) * 0.1f;
            //distantVector2 = distantVector2 - (distantVector2 - GetScene().GetCamera().GetCenter()) * 0.1f;
            //distantVector3 = distantVector3 - (distantVector3 - GetScene().GetCamera().GetCenter()) * 0.1f;
            
            Debug((String) "TS::RD dv1: " + distantVector1[0] + ", " + distantVector1[1] + ", " + distantVector1[2]);
            Debug((String) "TS::RD dv2: " + distantVector2[0] + ", " + distantVector2[1] + ", " + distantVector2[2]);
            Debug((String) "TS::RD dv3: " + distantVector3[0] + ", " + distantVector3[1] + ", " + distantVector3[2]);
            
            Vertex distantVertex1(*v1, distantVector1);
            Vertex distantVertex2(*v2, distantVector2);
            Vertex distantVertex3(*v3, distantVector3);
            if (first) {
                first = false;
	            distantProjection = new TriangleStrip();
                distantProjection->AddVertex(distantVertex1);
                distantProjection->AddVertex(distantVertex2);
                shape.AddChild(distantProjection);
            }
            assert(distantProjection);
            distantProjection->AddVertex(distantVertex3);
            Debug("TS::RD 13");
        }
        else {
            first = true;
        }
        Debug("TS::RD 14");
    }
    shape.Render();
}