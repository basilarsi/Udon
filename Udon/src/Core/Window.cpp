//
// Created by Basil on 8/6/2026.
//

#include <SDL3/SDL_vulkan.h>

#include "Udon/Core/Window.hpp"
#include "Udon/Core/Logger.hpp"

namespace udon {
  bool Window::SendConfig(const WindowCreateInfo& createInfo) {
    if (createInfo.Title.empty()) {
      UDON_ERROR("You can't set the window's title to an empty string!");
      return false;
    }

    UDON_VERBOSE("The sent WindowCreateInfo struct was validated and accepted.");
    return true;
  }

  bool Window::Construct(const SDL::Context& context) {
    if (_failedConfigValidation) {
      UDON_ERROR("Attempted to construct the window, but there hasn't been a valid structure provided!");
      return false;
    }

    if (!_createInfo) {
      UDON_WARN("Udon hasn't been provided with a WindowCreateInfo struct! Default parameters will be used.");
    }

    auto createInfo = _createInfo ? *_createInfo : WindowCreateInfo{};

    if (!context.CreateWindow(&_window, "Test App", 1280, 720, SDL_WINDOW_VULKAN)) {
      /* the context will automatically log the failure */
      return false;
    }

    UDON_VERBOSE("Successfully constructed the Udon window.");
    _initialized = true;
    return true;
  }

  bool Window::Initialized() {
    return _initialized;
  }

  void Window::Teardown() {
    _window.Destroy();
    _initialized = false;
  }

  // ReSharper disable once CppParameterMayBeConst
  VkSurfaceKHR Window::CreateSurface(VkInstance instance) {
    VkSurfaceKHR tempSurface = VK_NULL_HANDLE;
    if (!SDL_Vulkan_CreateSurface(_window, instance, nullptr, &tempSurface)) {
      UDON_ERROR(SDL_GetError());
      return VK_NULL_HANDLE;
    }

    return tempSurface;
  }
}
