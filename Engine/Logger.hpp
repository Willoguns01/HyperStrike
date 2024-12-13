#pragma once

#include <string>
#include <memory>

#include <spdlog/spdlog.h>

namespace HyperStrike
{
    class Logger
    {
    public:
        Logger(const std::string& name);
        ~Logger();

        template <typename T>
        void Info(const T& msg) {
            _logger->info(msg);
        }

        template <typename... T>
        void Info(spdlog::format_string_t<T...> fmt, T &&...args) {
            _logger->info(fmt, std::forward<T>(args)...);
        }

        template <typename T>
        void Warn(const T& msg) {
            _logger->warn(msg);
        }

        template <typename... T>
        void Warn(spdlog::format_string_t<T...> fmt, T &&...args) {
            _logger->warn(fmt, std::forward<T>(args)...);
        }

        template <typename T>
        void Error(const T& msg) {
            _logger->error(msg);
        }

        template <typename... T>
        void Error(spdlog::format_string_t<T...> fmt, T &&...args) {
            _logger->error(fmt, std::forward<T>(args)...);
        }

    private:
        std::shared_ptr<spdlog::logger> _logger = nullptr;
        std::string _name;
    };
}
