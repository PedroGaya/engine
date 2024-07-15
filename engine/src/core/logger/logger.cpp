#include "../../jc2dpch.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "logger.h"
#include "../../asserts.h"

namespace JC2D {
    std::shared_ptr<spdlog::logger> Log::s_coreLogger;
    std::shared_ptr<spdlog::logger> Log::s_clientLogger;

    void Log::init() {
        spdlog::set_pattern("%^[%X.%e] %n: %v%$");

        s_coreLogger = spdlog::stdout_color_mt("JC2D");
        s_coreLogger->set_level(spdlog::level::trace);

        s_clientLogger = spdlog::stdout_color_mt("APP");
        s_clientLogger->set_level(spdlog::level::trace);
    }

    void Log::reportAssertionFailure(const char* expression, const char* message, const char* file, int line) {
        JC2D_CORE_FATAL("Assertion Failure: {0}, message: {1}, in file: {2}, line: {3}", expression, message, file, line);
    }
}  // namespace JC2D
