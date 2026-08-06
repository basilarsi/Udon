//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/FPoint2D.hpp"

namespace udon {
  FPoint2D::FPoint2D(const float32 value)
    : X(value), Y(value) {
  }

  FPoint2D::FPoint2D(const float32 x, const float32 y)
    : X(x), Y(y) {
  }

  FPoint2D::FPoint2D()
    : X(0.0f), Y(0.0f) {
  }

  FPoint2D FPoint2D::operator+(const FPoint2D& other) const {
    return {
      X + other.X, Y + other.Y
    };
  }

  FPoint2D FPoint2D::operator-(const FPoint2D& other) const {
    return {
      X - other.X, Y - other.Y
    };
  }

  FPoint2D FPoint2D::operator*(const FPoint2D& other) const {
    return {
      X * other.X, Y * other.Y
    };
  }

  FPoint2D FPoint2D::operator/(const FPoint2D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y
    };
  }

  FPoint2D FPoint2D::operator+(const float32 scalar) const {
    return {
      X + scalar, Y + scalar
    };
  }

  FPoint2D FPoint2D::operator-(const float32 scalar) const {
    return {
      X - scalar, Y - scalar
    };
  }

  FPoint2D FPoint2D::operator*(const float32 scalar) const {
    return {
      X * scalar, Y * scalar
    };
  }

  FPoint2D FPoint2D::operator/(const float32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar
    };
  }

  FPoint2D& FPoint2D::operator+=(const FPoint2D& other) {
    this->X += other.X;
    this->Y += other.Y;

    return *this;
  }

  FPoint2D& FPoint2D::operator-=(const FPoint2D& other) {
    this->X -= other.X;
    this->Y -= other.Y;

    return *this;
  }

  FPoint2D& FPoint2D::operator*=(const FPoint2D& other) {
    this->X *= other.X;
    this->Y *= other.Y;

    return *this;
  }

  FPoint2D& FPoint2D::operator/=(const FPoint2D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;

    return *this;
  }

  FPoint2D& FPoint2D::operator+=(const float32 scalar) {
    this->X += scalar;
    this->Y += scalar;

    return *this;
  }

  FPoint2D& FPoint2D::operator-=(const float32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;

    return *this;
  }

  FPoint2D& FPoint2D::operator*=(const float32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;

    return *this;
  }

  FPoint2D& FPoint2D::operator/=(const float32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;

    return *this;
  }
}
