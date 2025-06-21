#pragma once
#include <cmath>
#include <stdexcept>
#include <ostream>
#include <algorithm>

namespace huzlip::geometry {

class Vector3D {
public:
    double x, y, z;
    constexpr Vector3D() noexcept : x(0), y(0), z(0) {}
    constexpr Vector3D(double xx, double yy, double zz) noexcept : x(xx), y(yy), z(zz) {}

    double& operator[](int i) {
        if (i==0) return x;
        if (i==1) return y;
        if (i==2) return z;
        throw std::out_of_range("Vector3D index");
    }
    double operator[](int i) const {
        if (i==0) return x;
        if (i==1) return y;
        if (i==2) return z;
        throw std::out_of_range("Vector3D index");
    }

    Vector3D operator+(const Vector3D& o) const { return {x+o.x, y+o.y, z+o.z}; }
    Vector3D operator-(const Vector3D& o) const { return {x-o.x, y-o.y, z-o.z}; }
    Vector3D operator*(double s) const { return {x*s, y*s, z*s}; }
    Vector3D operator/(double s) const { return {x/s, y/s, z/s}; }
    Vector3D& operator+=(const Vector3D& o) { x+=o.x; y+=o.y; z+=o.z; return *this; }
    Vector3D& operator-=(const Vector3D& o) { x-=o.x; y-=o.y; z-=o.z; return *this; }

    double dot(const Vector3D& o) const { return x*o.x + y*o.y + z*o.z; }
    Vector3D cross(const Vector3D& o) const { return Vector3D(y*o.z-z*o.y, z*o.x-x*o.z, x*o.y-y*o.x); }

    double norm() const { return std::sqrt(x*x+y*y+z*z); }
    Vector3D normalized() const { double n=norm(); return n>0 ? *this/n : *this; }
};

inline Vector3D operator*(double s, const Vector3D& v) { return v*s; }

} // namespace huzlip::geometry