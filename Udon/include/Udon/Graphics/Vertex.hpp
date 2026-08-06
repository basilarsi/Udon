//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_VERTEX_HPP
#define UDON_VERTEX_HPP

#include <vulkan/vulkan_raii.hpp>

#include "Color.hpp"
#include "Udon/Math/FPoint2D.hpp"
#include "Udon/Math/FPoint3D.hpp"

namespace udon {
  struct UDON_API Vertex final {
    FPoint3D VertexPosition;
    Color    VertexColor;
    FPoint3D VertexNormal;
    FPoint2D VertexUV;

    /* Constructors */

    explicit Vertex(const FPoint3D& position);
    Vertex(const FPoint3D& position, const Color& color);
    Vertex(const FPoint3D& position, const Color& color, const FPoint3D& normal);
    Vertex(const FPoint3D& position, const Color& color, const FPoint3D& normal, const FPoint2D& uv);

    static vk::VertexInputBindingDescription BindingDescription();
    static std::array<vk::VertexInputAttributeDescription, 4> AttributeDescriptions();
  };
}

#endif //UDON_VERTEX_HPP