//
// Created by Basil on 8/7/2026.
//

#include "Udon/Core/Udon.hpp"

namespace udon {
  Udon::Udon() {

  }

  Udon::~Udon() {

  }

  void Udon::Run() {
    InternalInit();
    Initialize();

    Load();

    DoAppLoop();

    Unload();

    OnExiting();
    InternalCleanup();
  }

  void Udon::Initialize() { }
  void Udon::Load()       { }
  void Udon::Unload()     { }
  void Udon::Update()     { }
  void Udon::Draw()       { }
  void Udon::OnExiting()  { }

  void Udon::InternalInit() {
    if (!Window::Construct(SDL)) {
      throw std::runtime_error("Couldn't construct the window!");
    }

    if (!GraphicsDevice::Initialize()) {
      throw std::runtime_error("Couldn't initialize the Graphics Device!");
    }
  }

  void Udon::DoAppLoop() {
    SDL_Event event;
    _running = true;
    while (_running) {
      while (SDL_PollEvent(&event)) {
        switch (event.type) {
          case SDL_EVENT_QUIT: {
            _running = false;
            break;
          }

          default:
            break;
        }
      }

      Update();

      Draw();

      SDL_Delay(1);
    }
  }

  void Udon::InternalCleanup() {
    GraphicsDevice::Teardown();
    Window::Teardown();
  }
}
