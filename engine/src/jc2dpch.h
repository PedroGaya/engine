#pragma once

#include <string>
#include <chrono>
#include <thread>

// TODO: These are temporary. Remove after updating logging system.
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef JC2D_PLATFORM_WINDOWS
#include <Windows.h>
#endif

// Vendor
#include <glm/glm.hpp>

#include "entt.hpp"
#include "stb_image.h"
#include "spdlog/spdlog.h"