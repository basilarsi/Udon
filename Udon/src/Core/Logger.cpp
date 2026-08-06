//
// Created by Basil on 8/6/2026.
//

#include "Udon/Core/Logger.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace udon {
  void Logger::Initialize(const std::string& clientName) {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    /* TODO: Variable levels that apply to everything BUT Vulkan */

    _vkLogger = spdlog::stdout_color_mt("Vulkan");
    _vkLogger->set_level(spdlog::level::trace);

    _udonLogger = spdlog::stdout_color_mt("Udon");
    _udonLogger->set_level(spdlog::level::trace);

    /* TODO: Prevent the client from using the name "Udon" */
    _clientLogger = spdlog::stdout_color_mt(clientName);
    _clientLogger->set_level(spdlog::level::trace);
  }

  std::shared_ptr<spdlog::logger> Logger::_vkLogger;
  std::shared_ptr<spdlog::logger> Logger::_udonLogger;
  std::shared_ptr<spdlog::logger> Logger::_clientLogger;
}
