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
}  // namespace JC2D

// Core macros
#define JC2D_CORE_TRACE(...) ::JC2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JC2D_CORE_INFO(...) ::JC2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JC2D_CORE_WARN(...) ::JC2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JC2D_CORE_ERROR(...) ::JC2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JC2D_CORE_FATAL(...) ::JC2D::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client macros
#define JC2D_TRACE(...) ::JC2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JC2D_INFO(...) ::JC2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define JC2D_WARN(...) ::JC2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JC2D_ERROR(...) ::JC2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define JC2D_FATAL(...) ::JC2D::Log::GetClientLogger()->fatal(__VA_ARGS__)