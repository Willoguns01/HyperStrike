#include <Engine/Logger.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace HyperStrike
{
    namespace
    {
        std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleSink = nullptr;
        std::shared_ptr<spdlog::sinks::basic_file_sink_mt> fileSink = nullptr;

        bool isInit = false;

        std::atomic_uint32_t refCount = 0;
    }

    Logger::Logger(const std::string& name)
    {
        if (!isInit) {
            consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            consoleSink->set_level(spdlog::level::trace);

            fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/log.txt", true);
            fileSink->set_level(spdlog::level::trace);

            isInit = true;
        }

        spdlog::sinks_init_list sinkList = {consoleSink, fileSink};

        _logger = std::make_shared<spdlog::logger>(name, sinkList.begin(), sinkList.end());
        _logger->set_level(spdlog::level::trace);
        _logger->info("Initialised logger {0}", name.c_str());

        refCount.fetch_add(1u);

        _name = name;
    }

    Logger::~Logger()
    {
        _logger->info("Cleanup logger {0}", _name.c_str());
        _logger.reset();

        refCount.fetch_sub(1u);
        if (refCount.load() == 0) {
            isInit = false;

            consoleSink.reset();
            fileSink.reset();
        }
    }
}
