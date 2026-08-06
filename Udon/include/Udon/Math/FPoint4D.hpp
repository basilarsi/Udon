//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_FPOINT4D_HPP
#define UDON_FPOINT4D_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief A float32-based struct for representing arbitrary four-dimensional data.
   */
  struct UDON_API FPoint4D {
    float32 X, Y, Z, W;

    /* Constructors */

    explicit FPoint4D(float32 value);
    FPoint4D(float32 x, float32 y, float32 z, float32 w);
    FPoint4D();

    /* Operators */

    FPoint4D operator+(const FPoint4D& other) const;
    FPoint4D operator-(const FPoint4D& other) const;
    FPoint4D operator*(const FPoint4D& other) const;
    FPoint4D operator/(const FPoint4D& other) const;

    FPoint4D operator+(float32 scalar) const;
    FPoint4D operator-(float32 scalar) const;
    FPoint4D operator*(float32 scalar) const;
    FPoint4D operator/(float32 scalar) const;

    FPoint4D& operator+=(const FPoint4D& other);
    FPoint4D& operator-=(const FPoint4D& other);
    FPoint4D& operator*=(const FPoint4D& other);
    FPoint4D& operator/=(const FPoint4D& other);

    FPoint4D& operator+=(float32 scalar);
    FPoint4D& operator-=(float32 scalar);
    FPoint4D& operator*=(float32 scalar);
    FPoint4D& operator/=(float32 scalar);

    auto operator<=>(const FPoint4D& other) const = default;
  };
}

#endif //UDON_FPOINT4D_HPP