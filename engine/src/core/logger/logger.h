#pragma once
#include "../../jc2dpch.h"
#include "../../defines.h"

namespace JC2D {
    class JC2D_API Log {
       public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

        static void reportAssertionFailure(const char* expression, const char* message, const char* file, int line);

       private:
        static std::shared_ptr<spdlog::logger> s_coreLogger;
        static std::shared_ptr<spdlog::logger> s_clientLogger;
    };
};  // namespace JC2D

// Core macros
#define JC2D_CORE_TRACE(...) ::JC2D::Log::getCoreLogger()->trace(__VA_ARGS__)
#define JC2D_CORE_INFO(...) ::JC2D::Log::getCoreLogger()->info(__VA_ARGS__)
#define JC2D_CORE_WARN(...) ::JC2D::Log::getCoreLogger()->warn(__VA_ARGS__)
#define JC2D_CORE_ERROR(...) ::JC2D::Log::getCoreLogger()->error(__VA_ARGS__)
#define JC2D_CORE_FATAL(...) ::JC2D::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client macros
#define JC2D_TRACE(...) ::JC2D::Log::getClientLogger()->trace(__VA_ARGS__)
#define JC2D_INFO(...) ::JC2D::Log::getClientLogger()->info(__VA_ARGS__)
#define JC2D_WARN(...) ::JC2D::Log::getClientLogger()->warn(__VA_ARGS__)
#define JC2D_ERROR(...) ::JC2D::Log::getClientLogger()->error(__VA_ARGS__)
#define JC2D_FATAL(...) ::JC2D::Log::getClientLogger()->critical(__VA_ARGS__)