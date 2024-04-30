#include "../../jc2dpch.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "logger.h"
#include "../../asserts.h"

namespace JC2D {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init() {
        spdlog::set_pattern("%^[T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("JC2D");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

    void Log::ReportAssertionFailure(const char* expression, const char* message, const char* file, int line) {
        JC2D_CORE_FATAL("Assertion Failure: {0}, message: {1}, in file: {2}, line: {3}", expression, message, file, line);
    }
}  // namespace JC2D
