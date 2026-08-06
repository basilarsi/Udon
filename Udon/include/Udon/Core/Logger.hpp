//
// Created by Basil on 8/6/2026.
//

#ifndef UDON_LOGGER_HPP
#define UDON_LOGGER_HPP

#include <spdlog/spdlog.h>

namespace udon {
  class UDON_API Logger final {
  public:
    /**
     * @brief Initializes the Udon logger, you need to call this BEFORE running your app.
     * @param clientName The name that will be applied to the client logger.
     */
    static void Initialize(const std::string& clientName);

    static std::shared_ptr<spdlog::logger> _vkLogger;
    static std::shared_ptr<spdlog::logger> _udonLogger;
    static std::shared_ptr<spdlog::logger> _clientLogger;
  };
}

#define VK_VERBOSE(...) ::udon::Logger::_vkLogger->trace(__VA_ARGS__)
#define VK_INFO(...)    ::udon::Logger::_vkLogger->info(__VA_ARGS__)
#define VK_WARN(...)    ::udon::Logger::_vkLogger->warn(__VA_ARGS__)
#define VK_ERROR(...)   ::udon::Logger::_vkLogger->error(__VA_ARGS__)
#define VK_FATAL(...)   ::udon::Logger::_vkLogger->critical(__VA_ARGS__)

#define UDON_VERBOSE(...) ::udon::Logger::_udonLogger->trace(__VA_ARGS__)
#define UDON_INFO(...)    ::udon::Logger::_udonLogger->info(__VA_ARGS__)
#define UDON_WARN(...)    ::udon::Logger::_udonLogger->warn(__VA_ARGS__)
#define UDON_ERROR(...)   ::udon::Logger::_udonLogger->error(__VA_ARGS__)
#define UDON_FATAL(...)   ::udon::Logger::_udonLogger->critical(__VA_ARGS__)

#define CLIENT_VERBOSE(...) ::udon::Logger::_clientLogger->trace(__VA_ARGS__)
#define CLIENT_INFO(...)    ::udon::Logger::_clientLogger->info(__VA_ARGS__)
#define CLIENT_WARN(...)    ::udon::Logger::_clientLogger->warn(__VA_ARGS__)
#define CLIENT_ERROR(...)   ::udon::Logger::_clientLogger->error(__VA_ARGS__)
#define CLIENT_FATAL(...)   ::udon::Logger::_clientLogger->critical(__VA_ARGS__)

#endif //UDON_LOGGER_HPP