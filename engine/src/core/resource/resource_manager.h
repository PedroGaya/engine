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
            if (m_resources.find(path) == m_resources.end()) {
                std::string fullPath = m_baseAssetPath + path;

                Loader* loader = m_loaders.find(T::getStaticType())->second;
                auto resource = static_cast<T*>(loader->load(fullPath));

                auto shared = std::shared_ptr<T>(resource);
                m_resources.insert({fullPath, shared});

                return shared;
            } else {
                return get<T>(path);
            }
        };

        static void unload(std::string assetPath) {
            std::string path = m_baseAssetPath + assetPath;
            auto resource = m_resources.find(path)->second;
            auto loader = m_loaders.find(resource->getResourceType())->second;

            loader->unload(resource.get());
            resource.reset();
            m_resources.erase(path);
        };

        template <typename T>
        static std::weak_ptr<T> get(std::string path) {
            std::shared_ptr<Resource> resource = m_resources.find(path)->second;
            std::shared_ptr<T> derived = std::dynamic_pointer_cast<T>(resource);
            return derived;
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