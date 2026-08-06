//
// Created by Basil on 8/6/2026.
//

#include "Udon/SDL.hpp"

namespace SDL {
  Context::Context(const uint32 flags) {
    if (!SDL_Init(flags)) {
      throw std::runtime_error(SDL_GetError());
    }

    _initialized = true;
  }

  Context::Context() {
    if (!SDL_Init(0)) {
      throw std::runtime_error(SDL_GetError());
    }

    _initialized = true;
  }

  Context::~Context() {
    SDL_Quit();

    _initialized = false;
  }

  // ReSharper disable once CppMemberFunctionMayBeStatic
  bool Context::CreateWindow(Window* window, const std::string& title, const int32 width, const int32 height, const uint64 windowFlags) const { // NOLINT(*-convert-member-functions-to-static)
    if (!_initialized) {
      return false;
    }

    window->_handle = SDL_CreateWindow(title.c_str(), width, height, windowFlags);

    if (!window->_handle) {
      return false;
    }

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
}
