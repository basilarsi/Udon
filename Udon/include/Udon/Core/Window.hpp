//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_WINDOW_HPP
#define UDON_WINDOW_HPP

#include <optional>
#include <vulkan/vulkan.h>

#include "Udon/SDL.hpp"

namespace udon {
  struct WindowCreateInfo final {
    std::string Title;
  };

  class UDON_API Window final {
  public:
    /**
     * @brief Reads and validates a given WindowCreateInfo struct, then stores it for later initialization.
     * @return True if the structure passed validation, false otherwise.
     * @remarks If you send a struct, and it fails to validate, the window will refuse to construct until a valid struct is provided.
     */
    [[nodiscard]] static bool SendConfig(const WindowCreateInfo& createInfo);

    /**
     * @brief Attempts to create a window. You shouldn't call this unless you're using a custom app loop.
     * @return True on success, false otherwise.
     */
    [[nodiscard]] static bool Construct(const SDL::Context& context);

    /**
     * @brief Checks whether the window is initialized.
     */
    [[nodiscard]] static bool Initialized();

    /**
     * @brief Destroys the window, you shouldn't call this unless you're using a custom app loop.
     */
    static void Teardown();

    [[nodiscard]] static VkSurfaceKHR CreateSurface(VkInstance instance);

  private:
    static inline std::optional<WindowCreateInfo> _createInfo             = std::nullopt;
    static inline bool                            _failedConfigValidation = false;
    static inline bool                            _initialized            = false;
    static inline SDL::Window                     _window;
  };
}

#endif //UDON_WINDOW_HPP
