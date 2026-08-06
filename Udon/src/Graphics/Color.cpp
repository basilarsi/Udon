//
// Created by Basil on 8/6/2026.
//

#include "Udon/Graphics/Color.hpp"

namespace udon {
  Color::Color(const uint32 hex) : HexCode(hex) {
  }

  Color::Color(const byte r, const byte g, const byte b, const byte a)
    : A(a), B(b),
      G(g), R(r) {
  }

  Color::Color(const int32 r, const int32 g, const int32 b, const int32 a)
    : A(static_cast<byte>(a)), B(static_cast<byte>(b)),
      G(static_cast<byte>(g)), R(static_cast<byte>(r)) {
  }

  Color::Color(const float32 r, const float32 g, const float32 b, const float32 a)
    : A(static_cast<byte>(a * 255.0f)), B(static_cast<byte>(b * 255.0f)),
      G(static_cast<byte>(g * 255.0f)), R(static_cast<byte>(r * 255.0f)) {
  }
}
