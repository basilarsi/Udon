//
// Created by Basil on 8/6/2026.
//

#include <iostream>

#include <Udon/SDL.hpp>

#include <Udon/Core/Logger.hpp>

#include "Udon/Core/Udon.hpp"

class Game : public udon::Udon {
public:
  Game() = default;
  ~Game() override = default;

protected:

private:
};

int32 main() {
  try {
    udon::Logger::Initialize("Dummy App");

    const auto game = std::make_unique<Game>();
    game->Run();

  } catch (const std::exception& ex) {
    CLIENT_FATAL(ex.what());
    return -1;
  }

  return 0;
}
