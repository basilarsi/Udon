//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/Point3D.hpp"

namespace udon {
  Point3D::Point3D(const int32 value)
    : X(value), Y(value),
      Z(value) {
  }

  Point3D::Point3D(const int32 x, const int32 y, const int32 z)
    : X(x), Y(y),
      Z(z) {
  }

  Point3D::Point3D()
    : X(0.0f), Y(0.0f),
      Z(0.0f) {
  }

  Point3D Point3D::operator+(const Point3D& other) const {
    return {
      X + other.X, Y + other.Y,
      Z + other.Z
    };
  }

  Point3D Point3D::operator-(const Point3D& other) const {
    return {
      X - other.X, Y - other.Y,
      Z - other.Z
    };
  }

  Point3D Point3D::operator*(const Point3D& other) const {
    return {
      X * other.X, Y * other.Y,
      Z * other.Z
    };
  }

  Point3D Point3D::operator/(const Point3D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y,
      Z / other.Z
    };
  }

  Point3D Point3D::operator+(const int32 scalar) const {
    return {
      X + scalar, Y + scalar,
      Z + scalar
    };
  }

  Point3D Point3D::operator-(const int32 scalar) const {
    return {
      X - scalar, Y - scalar,
      Z - scalar
    };
  }

  Point3D Point3D::operator*(const int32 scalar) const {
    return {
      X * scalar, Y * scalar,
      Z * scalar
    };
  }

  Point3D Point3D::operator/(const int32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar,
      Z / scalar
    };
  }

  Point3D& Point3D::operator+=(const Point3D& other) {
    this->X += other.X;
    this->Y += other.Y;
    this->Z += other.Z;

    return *this;
  }

  Point3D& Point3D::operator-=(const Point3D& other) {
    this->X -= other.X;
    this->Y -= other.Y;
    this->Z -= other.Z;

    return *this;
  }

  Point3D& Point3D::operator*=(const Point3D& other) {
    this->X *= other.X;
    this->Y *= other.Y;
    this->Z *= other.Z;

    return *this;
  }

  Point3D& Point3D::operator/=(const Point3D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;
    this->Z /= other.Z;

    return *this;
  }

  Point3D& Point3D::operator+=(const int32 scalar) {
    this->X += scalar;
    this->Y += scalar;
    this->Z += scalar;

    return *this;
  }

  Point3D& Point3D::operator-=(const int32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;
    this->Z -= scalar;

    return *this;
  }

  Point3D& Point3D::operator*=(const int32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;
    this->Z *= scalar;

    return *this;
  }

  Point3D& Point3D::operator/=(const int32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;
    this->Z /= scalar;

    return *this;
  }
}