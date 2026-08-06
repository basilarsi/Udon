//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_POINT2D_HPP
#define UDON_POINT2D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief An integer-based struct for representing arbitrary two-dimensional data.
   */
  struct UDON_API Point2D {
    int32 X, Y;

    /* Constructors */

    explicit Point2D(int32 value);
    Point2D(int32 x, int32 y);
    Point2D();

    /* Operators */

    Point2D operator+(const Point2D& other) const;
    Point2D operator-(const Point2D& other) const;
    Point2D operator*(const Point2D& other) const;
    Point2D operator/(const Point2D& other) const;

    Point2D operator+(int32 scalar) const;
    Point2D operator-(int32 scalar) const;
    Point2D operator*(int32 scalar) const;
    Point2D operator/(int32 scalar) const;

    Point2D& operator+=(const Point2D& other);
    Point2D& operator-=(const Point2D& other);
    Point2D& operator*=(const Point2D& other);
    Point2D& operator/=(const Point2D& other);

    Point2D& operator+=(int32 scalar);
    Point2D& operator-=(int32 scalar);
    Point2D& operator*=(int32 scalar);
    Point2D& operator/=(int32 scalar);

    auto operator<=>(const Point2D& other) const = default;
  };
}

#endif //UDON_POINT2D_HPP