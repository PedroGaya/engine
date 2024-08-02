#include "./image.h"

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace JC2D {
    void ImageResource::load() {
        int width, height, channels;
        unsigned char* data = stbi_load(getPath().c_str(), &width, &height, &channels, 0);

        m_width = width;
        m_height = height;
        m_channels = channels;

        setData(data);
    }
    void ImageResource::unload() {
        void* data = getData();
        if (data)
            stbi_image_free(data);
        setData(nullptr);
    }

}  // namespace JC2D