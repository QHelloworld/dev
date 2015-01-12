// Class automatically generated by Dev-C++ New Class wizard

#include <math.h>


#include "vector.h" // class's header file

using namespace engine3d;

//Vector::Vector()
//{
//}

// class constructor
Vector::Vector(int dim, bool zeroCoords)
{
    this->dim = dim;
    this->coords = new double[dim];
    if (zeroCoords) {
        for (int i = 0; i < dim; i++) {
            coords[i] = 0;
        }
    }
}

// class constructor
Vector::Vector(int dim, double coords[])
{
    this->dim = dim;
    this->coords = new double[dim];
    for (int i = 0; i < dim; i++) {
    	this->coords[i] = coords[i];
    }
}

Vector::Vector(double x, double y, double z, double w)
{
    dim = 4;
    coords = new double[dim];
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
    coords[3] = w;
}

Vector::Vector(double x, double y, double z)
{
    dim = 3;
    coords = new double[dim];
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
}

Vector::Vector(double x, double y)
{
    dim = 2;
    coords = new double[dim];
    coords[0] = x;
    coords[1] = y;
}

Vector::Vector(double x)
{
    dim = 1;
    coords = new double[dim];
    coords[0] = x;
}

Vector::Vector(const Vector& v)
{
    dim = v.dim;
    coords = new double[dim];
    for (int i = 0; i < dim; i++) {
    	coords[i] = v.coords[i];
    }
}

Vector& Vector::operator=(const Vector& v) {
    if (this != &v) {
        if (coords) {
            delete coords;
        }
        dim = v.dim;
        coords = new double[dim];
        for (int i = 0; i < dim; i++) {
            coords[i] = v.coords[i];
        }
    }
    return *this;
}

Vector Vector::operator-() const {
    Vector v(dim, false);//(*this);
    for (int i = 0; i < dim; i++) {
        v.coords[i] = -coords[i];
    }
    return v;
}


double Vector::operator[](int i) const {
    assert(i >= 0 && i < dim);
    return coords[i];
}

Vector Vector::operator+(const Vector& v) const {
    assert(dim == v.dim);
    Vector result(dim, false);
    for (int i = 0; i < dim; i++) {
        result.coords[i] = coords[i] + v.coords[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& v) const {
    assert(dim == v.dim);
    Vector result(dim, false);
    for (int i = 0; i < dim; i++) {
        result.coords[i] = coords[i] - v.coords[i];
    }
    return result;
}

Vector Vector::operator*(double c) const {
    Vector result(dim, false);
    for (int i = 0; i < dim; i++) {
        result.coords[i] = coords[i] * c;
    }
    return result;
}

Vector Vector::operator/(double c) const {
    Vector result(dim, false);
    for (int i = 0; i < dim; i++) {
        result.coords[i] = coords[i] / c;
    }
    return result;
}

Vector& Vector::operator+=(const Vector& v) {
    assert(dim == v.dim);
    for (int i = 0; i < dim; i++) {
        coords[i] += v.coords[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    assert(dim == v.dim);
    for (int i = 0; i < dim; i++) {
        coords[i] -= v.coords[i];
    }
    return *this;
}

Vector& Vector::operator*=(double c) {
    for (int i = 0; i < dim; i++) {
        coords[i] *= c;
    }
    return *this;
}

Vector& Vector::operator/=(double c) {
    for (int i = 0; i < dim; i++) {
        coords[i] /= c;
    }
    return *this;
}

// class destructor
Vector::~Vector()
{
    if (coords) {
	   delete []coords;
    }
}

// returns the coordinate of this vector at the specified index
//double Vector::GetCoord(int index) const 
//{
//    assert(dim > index);
//	return coords[index];
//}

void Vector::SetCoord(int index, double d) 
{
	coords[index] = d;
}

//double Vector::GetX() const 
//{
//    assert(dim > 0);
//	return coords[0];
//}
//
//double Vector::GetY() const 
//{
//    assert(dim > 1);
//	return coords[1];
//}
//
//double Vector::GetZ() const 
//{
//    assert(dim > 2);
//	return coords[2];
//}
//
//double Vector::GetW() const 
//{
//    assert(dim > 3);
//	return coords[3];
//}

//void Vector::Add(const Vector& v)
//{
//    assert(v.GetDim() == dim);
//    for (int i = 0; i < dim; i++) {
//        coords[i] += v.GetCoord(i);
//    }
//}
//
//void Vector::Mul(const double c)
//{
//    for (int i = 0; i < dim; i++) {
//        coords[i] *= c;
//    }
//}
//
//void Vector::Sub(const Vector& v)
//{
//    assert(v.GetDim() == dim);
//    for (int i = 0; i < dim; i++) {
//        coords[i] -= v.GetCoord(i);
//    }
//}

// Calculates the scalar product of the given vector and this vector
double Vector::DotProduct(const Vector& v) const
{
    assert(v.dim == dim);
    double product = 0;
    for (int i = 0; i < dim; i++) {
        product += v.coords[i] * coords[i];
    }
	return product;
}

Vector Vector::CrossProduct(const Vector& v) const
{
    assert(v.dim == dim && dim == 3);
    double vx = coords[1] * v.coords[2] - coords[2] * v.coords[1];
    double vy = coords[2] * v.coords[0] - coords[0] * v.coords[2];
    double vz = coords[0] * v.coords[1] - coords[1] * v.coords[0];
	return Vector(vx, vy, vz);
}

// Returns the dimention of this vector
int Vector::GetDim() const
{
	return dim;
}

// Returns the norm of this vector
double Vector::Length() const
{
    if (dim == 1) {
        return fabs(coords[0]);
    }
	return sqrt(DotProduct(*this));
}

// Returns the squared norm of this vector
double Vector::Length2() const
{
	return DotProduct(*this);
}

// Normalizes the vector and returns the reference to this
Vector& Vector::Normalize() {
    *this /= Length();
    return (*this);
}

Vector Vector::GetProjection(const Vector& axis) const {
    Vector projection = Vector(axis).Normalize();
    return projection * projection.DotProduct(*this);
}

String Vector::ToString() const {
    String s;
    for (int i = 0; i < dim; i++) {
        if (i != 0) {
            s = s + ",";
        }
        s = s + coords[i];
    }
    return s;
}
