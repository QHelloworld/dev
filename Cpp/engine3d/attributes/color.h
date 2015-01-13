// Class automatically generated by Dev-C++ New Class wizard

#ifndef COLOR_H
#define COLOR_H

#include "base/object.h" // inheriting class's header file
using namespace base;

namespace engine3d {
/*
 * No description
 */
class Color : public Object
{
	public:
		// class constructor
		//Color(double red = 1.0, double green = 1.0, double blue , double alpha = 1.0);
		Color(const double& red = 1.0, const double& green = 1.0, const double& blue = 1.0, const double& alpha = 1.0);
		// class destructor
		~Color();
	public:
        const double red;
        const double green;
        const double blue;
        const double alpha;
};
}
#endif // COLOR_H