//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/FPoint3D.hpp"

namespace udon {
  FPoint3D::FPoint3D(const float32 value)
    : X(value), Y(value),
      Z(value) {
  }

  FPoint3D::FPoint3D(const float32 x, const float32 y, const float32 z)
    : X(x), Y(y),
      Z(z) {
  }

  FPoint3D::FPoint3D()
    : X(0.0f), Y(0.0f),
      Z(0.0f) {
  }

  FPoint3D FPoint3D::operator+(const FPoint3D& other) const {
    return {
      X + other.X, Y + other.Y,
      Z + other.Z
    };
  }

  FPoint3D FPoint3D::operator-(const FPoint3D& other) const {
    return {
      X - other.X, Y - other.Y,
      Z - other.Z
    };
  }

  FPoint3D FPoint3D::operator*(const FPoint3D& other) const {
    return {
      X * other.X, Y * other.Y,
      Z * other.Z
    };
  }

  FPoint3D FPoint3D::operator/(const FPoint3D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y,
      Z / other.Z
    };
  }

  FPoint3D FPoint3D::operator+(const float32 scalar) const {
    return {
      X + scalar, Y + scalar,
      Z + scalar
    };
  }

  FPoint3D FPoint3D::operator-(const float32 scalar) const {
    return {
      X - scalar, Y - scalar,
      Z - scalar
    };
  }

  FPoint3D FPoint3D::operator*(const float32 scalar) const {
    return {
      X * scalar, Y * scalar,
      Z * scalar
    };
  }

  FPoint3D FPoint3D::operator/(const float32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar,
      Z / scalar
    };
  }

  FPoint3D& FPoint3D::operator+=(const FPoint3D& other) {
    this->X += other.X;
    this->Y += other.Y;
    this->Z += other.Z;

    return *this;
  }

  FPoint3D& FPoint3D::operator-=(const FPoint3D& other) {
    this->X -= other.X;
    this->Y -= other.Y;
    this->Z -= other.Z;

    return *this;
  }

  FPoint3D& FPoint3D::operator*=(const FPoint3D& other) {
    this->X *= other.X;
    this->Y *= other.Y;
    this->Z *= other.Z;

    return *this;
  }

  FPoint3D& FPoint3D::operator/=(const FPoint3D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;
    this->Z /= other.Z;

    return *this;
  }

  FPoint3D& FPoint3D::operator+=(const float32 scalar) {
    this->X += scalar;
    this->Y += scalar;
    this->Z += scalar;

    return *this;
  }

  FPoint3D& FPoint3D::operator-=(const float32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;
    this->Z -= scalar;

    return *this;
  }

  FPoint3D& FPoint3D::operator*=(const float32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;
    this->Z *= scalar;

    return *this;
  }

  FPoint3D& FPoint3D::operator/=(const float32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;
    this->Z /= scalar;

    return *this;
  }
}
