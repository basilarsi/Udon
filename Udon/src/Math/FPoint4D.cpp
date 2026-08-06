//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/FPoint4D.hpp"

namespace udon {
  FPoint4D::FPoint4D(const float32 value)
    : X(value), Y(value),
      Z(value), W(value) {
  }

  FPoint4D::FPoint4D(const float32 x, const float32 y, const float32 z, const float32 w)
    : X(x), Y(y),
      Z(z), W(w) {
  }

  FPoint4D::FPoint4D()
    : X(0.0f), Y(0.0f),
      Z(0.0f), W(0.0f) {
  }

  FPoint4D FPoint4D::operator+(const FPoint4D& other) const {
    return {
      X + other.X, Y + other.Y,
      Z + other.Z, W + other.W
    };
  }

  FPoint4D FPoint4D::operator-(const FPoint4D& other) const {
    return {
      X - other.X, Y - other.Y, Z - other.Z,
      W - other.W
    };
  }

  FPoint4D FPoint4D::operator*(const FPoint4D& other) const {
    return {
      X * other.X, Y * other.Y, Z * other.Z,
      W * other.W
    };
  }

  FPoint4D FPoint4D::operator/(const FPoint4D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y, Z / other.Z,
      W / other.W
    };
  }

  FPoint4D FPoint4D::operator+(const float32 scalar) const {
    return {
      X + scalar, Y + scalar, Z + scalar,
      W + scalar
    };
  }

  FPoint4D FPoint4D::operator-(const float32 scalar) const {
    return {
      X - scalar, Y - scalar, Z - scalar,
      W - scalar
    };
  }

  FPoint4D FPoint4D::operator*(const float32 scalar) const {
    return {
      X * scalar, Y * scalar, Z * scalar,
      W * scalar
    };
  }

  FPoint4D FPoint4D::operator/(const float32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar, Z / scalar,
      W / scalar
    };
  }

  FPoint4D& FPoint4D::operator+=(const FPoint4D& other) {
    this->X += other.X;
    this->Y += other.Y;
    this->Z += other.Z;
    this->W += other.W;

    return *this;
  }

  FPoint4D& FPoint4D::operator-=(const FPoint4D& other) {
    this->X -= other.X;
    this->Y -= other.Y;
    this->Z -= other.Z;
    this->W -= other.W;

    return *this;
  }

  FPoint4D& FPoint4D::operator*=(const FPoint4D& other) {
    this->X *= other.X;
    this->Y *= other.Y;
    this->Z *= other.Z;
    this->W *= other.W;

    return *this;
  }

  FPoint4D& FPoint4D::operator/=(const FPoint4D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;
    this->Z /= other.Z;
    this->W /= other.W;

    return *this;
  }

  FPoint4D& FPoint4D::operator+=(const float32 scalar) {
    this->X += scalar;
    this->Y += scalar;
    this->Z += scalar;
    this->W += scalar;

    return *this;
  }

  FPoint4D& FPoint4D::operator-=(const float32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;
    this->Z -= scalar;
    this->W -= scalar;

    return *this;
  }

  FPoint4D& FPoint4D::operator*=(const float32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;
    this->Z *= scalar;
    this->W *= scalar;

    return *this;
  }

  FPoint4D& FPoint4D::operator/=(const float32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;
    this->Z /= scalar;
    this->W /= scalar;

    return *this;
  }
}
