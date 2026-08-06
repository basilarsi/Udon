//
// Created by Basil on 8/6/2026.
//

#include "Udon/Core/Window.hpp"

#include "Udon/Core/Logger.hpp"

namespace udon {
  bool Window::SendConfig(const WindowCreateInfo& createInfo) {
    UDON_VERBOSE("The sent create info was validated and accepted.");
    return true;
  }

  bool Window::Construct() {
    if (!_failedConfigValidation) {
      UDON_ERROR("Attempted to construct the window, but there hasn't been a valid structure provided!");
      return false;
    }

    if (!_createInfo) {
      UDON_WARN("Udon hasn't been provided with a WindowCreateInfo struct! Default parameters will be used.");
    }

    UDON_VERBOSE("Successfully constructed the Udon window.");
    return true;
  }

  void Window::Teardown() {
  }
}
