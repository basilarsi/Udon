//
// Created by Basil on 8/6/2026.
//

#include "Udon/Graphics/Vertex.hpp"

namespace udon {
  Vertex::Vertex(const FPoint3D& position)
    : VertexPosition(position),
      VertexColor(0xFFFFFFFF),
      VertexNormal(0, 0, 0),
      VertexUV(0, 0) {
  }

  Vertex::Vertex(const FPoint3D& position, const Color& color)
    : VertexPosition(position),
      VertexColor(color),
      VertexNormal(0, 0, 0),
      VertexUV(0, 0) {
  }

  Vertex::Vertex(const FPoint3D& position, const Color& color, const FPoint3D& normal)
    : VertexPosition(position),
      VertexColor(color),
      VertexNormal(normal),
      VertexUV(0, 0) {
  }

  Vertex::Vertex(const FPoint3D& position, const Color& color, const FPoint3D& normal, const FPoint2D& uv)
    : VertexPosition(position),
      VertexColor(color),
      VertexNormal(normal),
      VertexUV(uv) {
  }

  vk::VertexInputBindingDescription Vertex::BindingDescription() {
    vk::VertexInputBindingDescription description{};
    description.binding   = 0;
    description.stride    = sizeof(Vertex);
    description.inputRate = vk::VertexInputRate::eVertex;

    return description;
  }

  std::array<vk::VertexInputAttributeDescription, 4> Vertex::AttributeDescriptions() {
    vk::VertexInputAttributeDescription positionDescription{};
    positionDescription.location = 0;
    positionDescription.binding  = 0;
    positionDescription.format   = vk::Format::eR32G32B32Sfloat;
    positionDescription.offset   = offsetof(Vertex, VertexPosition);

    vk::VertexInputAttributeDescription colorDescription{};
    colorDescription.location = 1;
    colorDescription.binding  = 0;
    colorDescription.format   = vk::Format::eR32Uint;
    colorDescription.offset   = offsetof(Vertex, VertexColor);

    vk::VertexInputAttributeDescription normalDescription{};
    normalDescription.location = 2;
    normalDescription.binding  = 0;
    normalDescription.format   = vk::Format::eR32G32B32Sfloat;
    normalDescription.offset   = offsetof(Vertex, VertexNormal);

    vk::VertexInputAttributeDescription uvDescription{};
    uvDescription.location = 3;
    uvDescription.binding  = 0;
    uvDescription.format   = vk::Format::eR32G32Sfloat;
    uvDescription.offset   = offsetof(Vertex, VertexUV);

    return {
      positionDescription,
      colorDescription,
      normalDescription,
      uvDescription
    };
  }
}
