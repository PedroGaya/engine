#pragma once

#include "../../defines.h"
#include "../../uuid.h"
#include "../../jc2dpch.h"

namespace JC2D {
    class JC2D_API Resource {
       public:
        Resource(std::string path)
            : m_id(generateUUID()),
              m_assetPath(path) {};
        ~Resource() = default;

        inline JC2D::UUID getId() const { return m_id; };
        inline std::string getPath() const { return m_assetPath; };

        inline void setData(unsigned char* data) { m_buffer = data; }
        inline unsigned char* getData() const { return m_buffer; };

        virtual void load() = 0;
        virtual void unload() = 0;

       private:
        unsigned char* m_buffer = nullptr;

        std::string m_assetPath = nullptr;
        JC2D::UUID m_id = nullptr;
    };
}  // namespace JC2D