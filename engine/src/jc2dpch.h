#pragma once

#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <vector>
#include <numeric>
#include <utility>

#ifdef JC2D_PLATFORM_WINDOWS
#include <Windows.h>
#endif

// Vendor
#include <glad/glad.h>
#include <AL/al.h>
#include <png.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "entt.hpp"
#include "stb_image.h"
#include "spdlog/spdlog.h"