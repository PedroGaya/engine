#pragma once

#include "../../defines.h"
#include "../../uuid.h"
#include "../../jc2dpch.h"

namespace JC2D {
    enum class ResourceType {
        None = 0,
        Image
    };

#define RESOURCE_CLASS_TYPE(type)                                      \
    static ResourceType getStaticType() { return ResourceType::type; } \
    virtual ResourceType getResourceType() const override { return getStaticType(); }

    class JC2D_API Resource {
       public:
        Resource(std::string path)
            : m_id(generateUUID()),
              m_assetPath(path) {};
        ~Resource() = default;

        virtual ResourceType getResourceType() const = 0;

        inline JC2D::UUID getId() const { return m_id; };
        inline std::string getPath() const { return m_assetPath; };

        inline void setData(void* data) { m_buffer = data; }
        inline void* getData() const { return m_buffer; };

       private:
        void* m_buffer = nullptr;

        std::string m_assetPath = nullptr;
        JC2D::UUID m_id = nullptr;
    };
}  // namespace JC2D