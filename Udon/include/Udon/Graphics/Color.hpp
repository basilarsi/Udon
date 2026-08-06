//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_COLOR_HPP
#define UDON_COLOR_HPP

#include "Udon/Pch.hpp"

namespace udon {
  /**
   * @brief Representation of a four-channel color.
   */
  union Color {
    uint32 HexCode;

    struct {
      byte A, B, G, R;
    };

    /* Constructors */

    explicit Color(uint32 hex);
    Color(byte r, byte g, byte b, byte a);
    Color(int32 r, int32 g, int32 b, int32 a);
    Color(float32 r, float32 g, float32 b, float32 a);
  };
}

#endif //UDON_COLOR_HPP