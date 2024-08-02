#include "./resource_manager.h"
#include "../../asserts.h"

namespace JC2D {
    ResourceManager::~ResourceManager() { shutdown(); }

    template <typename T, typename... A>
    std::weak_ptr<T> ResourceManager::create(A&&... args) {
        auto resource = std::make_shared<T>(std::forward<A>(args)...);
        std::weak_ptr<Resource> wpResource = resource;

        m_resources.insert(std::make_pair(resource->getId(), resource));
        return wpResource;
    };

    template <typename T>
    std::weak_ptr<T> ResourceManager::get(JC2D::UUID uuid) {
        std::shared_ptr<Resource> resource = m_resources.find(uuid);
        std::weak_ptr<Resource> wpResource = resource;
        return wpResource;
    };

    void ResourceManager::init(std::string assetPath) {
        if (!s_instance) {
            s_instance = new ResourceManager();
            m_basePath = assetPath;
        }
    }

    void ResourceManager::shutdown() {
        delete s_instance;
        s_instance = nullptr;
    }
}  // namespace JC2D