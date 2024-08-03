#include "./resource_manager.h"
#include "../../asserts.h"

namespace JC2D {
    ResourceManager::~ResourceManager() { shutdown(); }

    void ResourceManager::init(std::string assetPath) {
        if (!s_instance) {
            s_instance = new ResourceManager();
            m_baseAssetPath = assetPath;
        }
    }

    void ResourceManager::shutdown() {
        delete s_instance;
        s_instance = nullptr;
    }
}  // namespace JC2D