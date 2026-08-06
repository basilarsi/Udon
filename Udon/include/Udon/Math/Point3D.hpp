//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_POINT3D_HPP
#define UDON_POINT3D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief An integer-based struct for representing arbitrary three-dimensional data.
   */
  struct UDON_API Point3D {
    int32 X, Y, Z;

    /* Constructors */

    explicit Point3D(int32 value);
    Point3D(int32 x, int32 y, int32 z);
    Point3D();

    /* Operators */

    Point3D operator+(const Point3D& other) const;
    Point3D operator-(const Point3D& other) const;
    Point3D operator*(const Point3D& other) const;
    Point3D operator/(const Point3D& other) const;

    Point3D operator+(int32 scalar) const;
    Point3D operator-(int32 scalar) const;
    Point3D operator*(int32 scalar) const;
    Point3D operator/(int32 scalar) const;

    Point3D& operator+=(const Point3D& other);
    Point3D& operator-=(const Point3D& other);
    Point3D& operator*=(const Point3D& other);
    Point3D& operator/=(const Point3D& other);

    Point3D& operator+=(int32 scalar);
    Point3D& operator-=(int32 scalar);
    Point3D& operator*=(int32 scalar);
    Point3D& operator/=(int32 scalar);

    auto operator<=>(const Point3D& other) const = default;
  };
}

#endif //UDON_POINT3D_HPP