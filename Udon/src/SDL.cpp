//
// Created by Basil on 8/6/2026.
//

#include "Udon/SDL.hpp"
#include "Udon/Core/Logger.hpp"

namespace SDL {
  Context::Context(const uint32 flags) {
    if (!SDL_Init(flags)) {
      UDON_FATAL(SDL_GetError());
      throw std::runtime_error(SDL_GetError());
    }

    UDON_VERBOSE("Initialized SDL.");
    _initialized = true;
  }

  Context::Context() {
    if (!SDL_Init(0)) {
      UDON_FATAL(SDL_GetError());
      throw std::runtime_error(SDL_GetError());
    }

    UDON_VERBOSE("Initialized SDL.");
    _initialized = true;
  }

  Context::~Context() {
    SDL_Quit();

    UDON_VERBOSE("De-initialized SDL.");
    _initialized = false;
  }

  // ReSharper disable once CppMemberFunctionMayBeStatic
  bool Context::CreateWindow(Window* window, const std::string& title, const int32 width, const int32 height, const uint64 windowFlags) const { // NOLINT(*-convert-member-functions-to-static)
    if (!_initialized) {
      UDON_ERROR("Attempted to create an SDL window, but SDL hasn't been initialized!");
      return false;
    }

    window->_handle = SDL_CreateWindow(title.c_str(), width, height, windowFlags);

    if (!window->_handle) {
      UDON_ERROR(SDL_GetError());
      return false;
    }

    UDON_VERBOSE("Created an SDL window.");
    return true;
  }

  bool Context::Initialized() {
    return _initialized;
  }

  Window::Window()
    : _handle(nullptr) {
  }

  Window::Window(Window&& other) noexcept
    : _handle(other._handle) {
    other._handle = nullptr;
  }

  Window::~Window() {
    if (_handle) {
      SDL_DestroyWindow(_handle);
      _handle = nullptr;
      UDON_VERBOSE("Automatically destroyed an SDL window.");
    }
  }

  Window& Window::operator=(Window&& other) noexcept {
    if (this != &other) {
      if (_handle) {
        SDL_DestroyWindow(_handle);
        _handle = nullptr;
      }

      _handle       = other._handle;
      other._handle = nullptr;
    }

    return *this;
  }

  Window::operator bool() const {
    return _handle;
  }

  Window::operator SDL_Window*() const {
    return _handle;
  }

  void Window::Destroy() {
    if (_handle != nullptr) {
      SDL_DestroyWindow(_handle);
      _handle = nullptr;
      UDON_VERBOSE("Manually destroyed an SDL window.");
    }
  }
}
