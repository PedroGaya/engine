#pragma once

#include "./resource.h"

namespace JC2D {
    class JC2D_API ImageResource : public Resource {
       public:
        ImageResource(std::string path) : Resource(path) {}

        void load() override;
        void unload() override;

        inline unsigned int getWidth() const { return m_width; }
        inline unsigned int getHeight() const { return m_height; }
        inline unsigned int getChannels() const { return m_channels; }

       private:
        unsigned int m_channels;
        unsigned int m_width;
        unsigned int m_height;
    };
}  // namespace JC2D