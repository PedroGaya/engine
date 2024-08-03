#pragma once

#include "../resource.h"

namespace JC2D {
    class JC2D_API ImageResource : public Resource {
       public:
        ImageResource(std::string path, unsigned int width, unsigned int height, unsigned int channels)
            : Resource(path),
              m_width(width),
              m_height(height),
              m_channels(channels) {}

        RESOURCE_CLASS_TYPE(Image);

        inline unsigned int getWidth() const { return m_width; }
        inline unsigned int getHeight() const { return m_height; }
        inline unsigned int getChannels() const { return m_channels; }

       private:
        unsigned int m_channels;
        unsigned int m_width;
        unsigned int m_height;
    };
}  // namespace JC2D