//
// Created by Basil on 8/6/2026.
//

#include <iostream>

#include <Udon/SDL.hpp>

int32 main() {
  try {
    SDL::Context _context;

    SDL::Window _window;

    if (!_context.CreateWindow(&_window, "Test", 1280, 720, SDL_WINDOW_VULKAN)) {
      return -1;
    }

    SDL_Event _event;
    bool _running = true;
    while (_running) {
      while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_EVENT_QUIT) {
          _running = false;
        }
      }

      SDL_Delay(1);
    }
  } catch (const std::exception& ex) {
    std::cerr<<ex.what()<<"\n";
    return -1;
  }

  return 0;
}