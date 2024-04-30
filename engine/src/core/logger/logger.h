#pragma once
#include "../../jc2dpch.h"
#include "../../defines.h"

namespace JC2D {
    class JC2D_API Log {
       public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        static void ReportAssertionFailure(const char* expression, const char* message, const char* file, int line);

       private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
};  // namespace JC2D

// Core macros
#define JC2D_CORE_TRACE(...) ::JC2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JC2D_CORE_INFO(...) ::JC2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JC2D_CORE_WARN(...) ::JC2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JC2D_CORE_ERROR(...) ::JC2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JC2D_CORE_FATAL(...) ::JC2D::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client macros
#define JC2D_TRACE(...) ::JC2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JC2D_INFO(...) ::JC2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define JC2D_WARN(...) ::JC2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JC2D_ERROR(...) ::JC2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define JC2D_FATAL(...) ::JC2D::Log::GetClientLogger()->critical(__VA_ARGS__)