// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "base/object.h" // inheriting class's header file
//#include "scene.h"

using namespace base;

namespace engine3d {

    class Scene;
    
    /**
     * No description
     */
    class Controller : public Object
    {
    	public:
    		// class constructor
    		Controller(const Scene& rScene);
    		// class destructor
    		~Controller();
    		virtual void Execute() {}
    	protected:
            const Scene& mrScene;
    };
}
#endif // CONTROLLER_H
