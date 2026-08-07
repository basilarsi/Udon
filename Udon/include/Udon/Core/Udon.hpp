//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_UDON_HPP
#define UDON_UDON_HPP

#include "Logger.hpp"
#include "Udon/Pch.hpp"
#include "Udon/SDL.hpp"
#include "Udon/Core/Window.hpp"
#include "Udon/Graphics/GraphicsDevice.hpp"

namespace udon {
  class UDON_API Udon {
  public:
    Udon();
    virtual ~Udon();

    void Run();

  protected:
    SDL::Context SDL;

    virtual void Initialize();
    virtual void Load();
    virtual void Unload();
    virtual void Update();
    virtual void Draw();
    virtual void OnExiting();

  private:
    bool _running = false;

    void InternalInit();
    void DoAppLoop();
    void InternalCleanup();
  };
}

#endif //UDON_UDON_HPP