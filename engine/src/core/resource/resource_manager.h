#pragma once

#include "../../jc2dpch.h"
#include "../../asserts.h"

#include "./resource.h"
#include "./loader.h"

namespace JC2D {
    class JC2D_API ResourceManager {
       public:
        ~ResourceManager();

        static void init(std::string path);
        static void shutdown();

        template <typename T>
        static std::weak_ptr<T> load(std::string path) {
            std::string fullPath = m_baseAssetPath + path;

            Loader* loader = m_loaders.find(T::getStaticType())->second;
            auto resource = static_cast<T*>(loader->load(fullPath));

            auto shared = std::shared_ptr<T>(resource);
            m_resources.insert({fullPath, shared});

            return shared;
        };

        template <typename T>
        static std::weak_ptr<T> get(JC2D::UUID uuid) {
            std::shared_ptr<Resource> resource = m_resources.find(uuid);
            std::weak_ptr<Resource> wpResource = resource;
            return wpResource;
        };

        static inline ResourceManager& getInstance() { return *s_instance; }
        static inline std::string getBaseAssetPath() { return m_baseAssetPath; }

        static inline void registerLoader(ResourceType type, Loader* loader) { m_loaders.insert({type, loader}); }

       private:
        ResourceManager() = default;

       private:
        inline static std::unordered_map<ResourceType, Loader*> m_loaders;
        inline static std::unordered_map<std::string, std::shared_ptr<Resource>> m_resources;

        inline static std::string m_baseAssetPath = "";
        inline static ResourceManager* s_instance = nullptr;
    };
}  // namespace JC2D