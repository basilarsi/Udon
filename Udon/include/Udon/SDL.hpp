//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_SDL_HPP
#define UDON_SDL_HPP

#include <SDL3/SDL.h>

#include "Udon/Pch.hpp"

namespace SDL {
  struct Window;

  /**
   * @brief Thin RAII wrapper over SDL.
   */
  class UDON_API Context final {
  public:
    /* Constructors */

    explicit Context(uint32 flags);
    Context(const Context& other) = delete;
    Context(Context&& other) = delete;
    Context();
    ~Context();

    /* Operators */

    Context& operator=(const Context& other) = delete;
    Context& operator=(Context&& other) = delete;

    /* Methods */

    [[nodiscard]] bool CreateWindow(Window* window, const std::string& title, int32 width, int32 height, uint64 windowFlags) const;

    static bool Initialized();

  private:
    static inline bool _initialized = false;
  };

  /**
   * @brief Thin RAII over an SDL_Window.
   */
  struct UDON_API Window final {
    /* Constructors */

    Window();
    Window(const Window& other) = delete;
    Window(Window&& other) noexcept;
    ~Window();

    /* Operators */

    Window& operator=(const Window& other) = delete;
    Window& operator=(Window&& other) noexcept;

    explicit operator bool() const;

    /* That's the point... */
    // ReSharper disable once CppNonExplicitConversionOperator
    operator SDL_Window*() const;

    friend class Context;

  private:
    SDL_Window* _handle;
  };
}

#endif //UDON_SDL_HPP
