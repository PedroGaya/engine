#pragma once

#include "../../jc2dpch.h"
#include "./resource.h"

namespace JC2D {
    class JC2D_API ResourceManager {
       public:
        ~ResourceManager();

        static void init(std::string path);
        static void shutdown();

        template <typename T, typename... A>
        static std::weak_ptr<T> create(A&&... args);
        template <typename T>
        static std::weak_ptr<T> get(JC2D::UUID uuid);

        static inline ResourceManager& getInstance() { return *s_instance; }
        static inline std::string getAssetPath() { return m_basePath; }

       private:
        ResourceManager() = default;

       private:
        inline static std::unordered_map<JC2D::UUID, std::shared_ptr<Resource>> m_resources;

        inline static std::string m_basePath = "";
        inline static ResourceManager* s_instance = nullptr;
    };
}  // namespace JC2D