//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_FPOINT2D_HPP
#define UDON_FPOINT2D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief A float32-based struct for representing arbitrary two-dimensional data.
   */
  struct UDON_API FPoint2D {
    float32 X, Y;

    /* Constructors */

    explicit FPoint2D(float32 value);
    FPoint2D(float32 x, float32 y);
    FPoint2D();

    /* Operators */

    FPoint2D operator+(const FPoint2D& other) const;
    FPoint2D operator-(const FPoint2D& other) const;
    FPoint2D operator*(const FPoint2D& other) const;
    FPoint2D operator/(const FPoint2D& other) const;

    FPoint2D operator+(float32 scalar) const;
    FPoint2D operator-(float32 scalar) const;
    FPoint2D operator*(float32 scalar) const;
    FPoint2D operator/(float32 scalar) const;

    FPoint2D& operator+=(const FPoint2D& other);
    FPoint2D& operator-=(const FPoint2D& other);
    FPoint2D& operator*=(const FPoint2D& other);
    FPoint2D& operator/=(const FPoint2D& other);

    FPoint2D& operator+=(float32 scalar);
    FPoint2D& operator-=(float32 scalar);
    FPoint2D& operator*=(float32 scalar);
    FPoint2D& operator/=(float32 scalar);

    auto operator<=>(const FPoint2D& other) const = default;
  };
}

#endif //UDON_FPOINT2D_HPP