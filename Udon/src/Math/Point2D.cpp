//
// Created by Basil on 8/6/2026.
//

#include "Udon/Math/Point2D.hpp"

namespace udon {
  Point2D::Point2D(const int32 value)
    : X(value), Y(value) {
  }

  Point2D::Point2D(const int32 x, const int32 y)
    : X(x), Y(y) {
  }

  Point2D::Point2D()
    : X(0.0f), Y(0.0f) {
  }

  Point2D Point2D::operator+(const Point2D& other) const {
    return {
      X + other.X, Y + other.Y
    };
  }

  Point2D Point2D::operator-(const Point2D& other) const {
    return {
      X - other.X, Y - other.Y
    };
  }

  Point2D Point2D::operator*(const Point2D& other) const {
    return {
      X * other.X, Y * other.Y
    };
  }

  Point2D Point2D::operator/(const Point2D& other) const {
    /* TODO: Division by zero guard */
    return {
      X / other.X, Y / other.Y
    };
  }

  Point2D Point2D::operator+(const int32 scalar) const {
    return {
      X + scalar, Y + scalar
    };
  }

  Point2D Point2D::operator-(const int32 scalar) const {
    return {
      X - scalar, Y - scalar
    };
  }

  Point2D Point2D::operator*(const int32 scalar) const {
    return {
      X * scalar, Y * scalar
    };
  }

  Point2D Point2D::operator/(const int32 scalar) const {
    /* TODO: Division by zero guard */
    return {
      X / scalar, Y / scalar
    };
  }

  Point2D& Point2D::operator+=(const Point2D& other) {
    this->X += other.X;
    this->Y += other.Y;

    return *this;
  }

  Point2D& Point2D::operator-=(const Point2D& other) {
    this->X -= other.X;
    this->Y -= other.Y;

    return *this;
  }

  Point2D& Point2D::operator*=(const Point2D& other) {
    this->X *= other.X;
    this->Y *= other.Y;

    return *this;
  }

  Point2D& Point2D::operator/=(const Point2D& other) {
    /* TODO: Division by zero guard */
    this->X /= other.X;
    this->Y /= other.Y;

    return *this;
  }

  Point2D& Point2D::operator+=(const int32 scalar) {
    this->X += scalar;
    this->Y += scalar;

    return *this;
  }

  Point2D& Point2D::operator-=(const int32 scalar) {
    this->X -= scalar;
    this->Y -= scalar;

    return *this;
  }

  Point2D& Point2D::operator*=(const int32 scalar) {
    this->X *= scalar;
    this->Y *= scalar;

    return *this;
  }

  Point2D& Point2D::operator/=(const int32 scalar) {
    /* TODO: Division by zero guard */
    this->X /= scalar;
    this->Y /= scalar;

    return *this;
  }
}