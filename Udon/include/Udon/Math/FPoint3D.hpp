//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_FPOINT3D_HPP
#define UDON_FPOINT3D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief A float32-based struct for representing arbitrary three-dimensional data.
   */
  struct UDON_API FPoint3D {
    float32 X, Y, Z;

    /* Constructors */

    explicit FPoint3D(float32 value);
    FPoint3D(float32 x, float32 y, float32 z);
    FPoint3D();

    /* Operators */

    FPoint3D operator+(const FPoint3D& other) const;
    FPoint3D operator-(const FPoint3D& other) const;
    FPoint3D operator*(const FPoint3D& other) const;
    FPoint3D operator/(const FPoint3D& other) const;

    FPoint3D operator+(float32 scalar) const;
    FPoint3D operator-(float32 scalar) const;
    FPoint3D operator*(float32 scalar) const;
    FPoint3D operator/(float32 scalar) const;

    FPoint3D& operator+=(const FPoint3D& other);
    FPoint3D& operator-=(const FPoint3D& other);
    FPoint3D& operator*=(const FPoint3D& other);
    FPoint3D& operator/=(const FPoint3D& other);

    FPoint3D& operator+=(float32 scalar);
    FPoint3D& operator-=(float32 scalar);
    FPoint3D& operator*=(float32 scalar);
    FPoint3D& operator/=(float32 scalar);

    auto operator<=>(const FPoint3D& other) const = default;
  };
}

#endif //UDON_FPOINT3D_HPP