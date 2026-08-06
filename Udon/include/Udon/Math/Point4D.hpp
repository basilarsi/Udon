//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_POINT4D_HPP
#define UDON_POINT4D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief An integer-based struct for representing arbitrary four-dimensional data.
   */
  struct UDON_API Point4D {
    int32 X, Y, Z, W;

    /* Constructors */

    explicit Point4D(int32 value);
    Point4D(int32 x, int32 y, int32 z, int32 w);
    Point4D();

    /* Operators */

    Point4D operator+(const Point4D& other) const;
    Point4D operator-(const Point4D& other) const;
    Point4D operator*(const Point4D& other) const;
    Point4D operator/(const Point4D& other) const;

    Point4D operator+(int32 scalar) const;
    Point4D operator-(int32 scalar) const;
    Point4D operator*(int32 scalar) const;
    Point4D operator/(int32 scalar) const;

    Point4D& operator+=(const Point4D& other);
    Point4D& operator-=(const Point4D& other);
    Point4D& operator*=(const Point4D& other);
    Point4D& operator/=(const Point4D& other);

    Point4D& operator+=(int32 scalar);
    Point4D& operator-=(int32 scalar);
    Point4D& operator*=(int32 scalar);
    Point4D& operator/=(int32 scalar);

    auto operator<=>(const Point4D& other) const = default;
  };
}

#endif //UDON_POINT4D_HPP