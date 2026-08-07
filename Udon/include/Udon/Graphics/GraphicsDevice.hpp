//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_GRAPHICSDEVICE_HPP
#define UDON_GRAPHICSDEVICE_HPP

#include <optional>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan_raii.hpp>

#include "Udon/Pch.hpp"
#include "Udon/Core/Logger.hpp"
#include "Udon/Core/Window.hpp"

namespace udon {
  struct GraphicsDeviceCreateInfo final {
    std::string AppName       = "Udon Client";
    uint32      AppVersion    = VK_MAKE_VERSION(1, 0, 0);
    bool        UseValidation = true;
  };

  class UDON_API GraphicsDevice final {
  public:
    static bool SendConfig(const GraphicsDeviceCreateInfo& gfxdCreateInfo);

    static bool Initialize();

    static void Teardown();

  private:
    static inline bool                                    _failedCreateInfoValidation = false;
    static inline std::optional<GraphicsDeviceCreateInfo> _gfxdCreateInfo             = std::nullopt;

    static inline vk::raii::Context                _vulkan;
    static inline vk::raii::Instance               _instance       = nullptr;
    static inline vk::raii::DebugUtilsMessengerEXT _debugMessenger = nullptr;
    static inline vk::raii::PhysicalDevice         _physicalDevice = nullptr;
    static inline vk::raii::Device                 _device         = nullptr;
    static inline vk::raii::Queue                  _graphicsQueue  = nullptr;
    static inline vk::raii::SurfaceKHR             _surface        = nullptr;
  };
}

#endif //UDON_GRAPHICSDEVICE_HPP
