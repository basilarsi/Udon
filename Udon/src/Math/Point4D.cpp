//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/Point4D.hpp"

namespace udon {
  Point4D::Point4D(const int32 value)
    : X(value), Y(value),
      Z(value), W(value) {
  }

  Point4D::Point4D(const int32 x, const int32 y, const int32 z, const int32 w)
    : X(x), Y(y),
      Z(z), W(w) {
  }

  Point4D::Point4D()
    : X(0.0f), Y(0.0f),
      Z(0.0f), W(0.0f) {
  }

  Point4D Point4D::operator+(const Point4D& other) const {
    return {
      X + other.X, Y + other.Y,
      Z + other.Z, W + other.W
    };
  }

  Point4D Point4D::operator-(const Point4D& other) const {
    return {
      X - other.X, Y - other.Y, Z - other.Z,
      W - other.W
    };
  }

  Point4D Point4D::operator*(const Point4D& other) const {
    return {
      X * other.X, Y * other.Y, Z * other.Z,
      W * other.W
    };
  }

  Point4D Point4D::operator/(const Point4D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y, Z / other.Z,
      W / other.W
    };
  }

  Point4D Point4D::operator+(const int32 scalar) const {
    return {
      X + scalar, Y + scalar, Z + scalar,
      W + scalar
    };
  }

  Point4D Point4D::operator-(const int32 scalar) const {
    return {
      X - scalar, Y - scalar, Z - scalar,
      W - scalar
    };
  }

  Point4D Point4D::operator*(const int32 scalar) const {
    return {
      X * scalar, Y * scalar, Z * scalar,
      W * scalar
    };
  }

  Point4D Point4D::operator/(const int32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar, Z / scalar,
      W / scalar
    };
  }

  Point4D& Point4D::operator+=(const Point4D& other) {
    this->X += other.X;
    this->Y += other.Y;
    this->Z += other.Z;
    this->W += other.W;

    return *this;
  }

  Point4D& Point4D::operator-=(const Point4D& other) {
    this->X -= other.X;
    this->Y -= other.Y;
    this->Z -= other.Z;
    this->W -= other.W;

    return *this;
  }

  Point4D& Point4D::operator*=(const Point4D& other) {
    this->X *= other.X;
    this->Y *= other.Y;
    this->Z *= other.Z;
    this->W *= other.W;

    return *this;
  }

  Point4D& Point4D::operator/=(const Point4D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;
    this->Z /= other.Z;
    this->W /= other.W;

    return *this;
  }

  Point4D& Point4D::operator+=(const int32 scalar) {
    this->X += scalar;
    this->Y += scalar;
    this->Z += scalar;
    this->W += scalar;

    return *this;
  }

  Point4D& Point4D::operator-=(const int32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;
    this->Z -= scalar;
    this->W -= scalar;

    return *this;
  }

  Point4D& Point4D::operator*=(const int32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;
    this->Z *= scalar;
    this->W *= scalar;

    return *this;
  }

  Point4D& Point4D::operator/=(const int32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;
    this->Z /= scalar;
    this->W /= scalar;

    return *this;
  }
}