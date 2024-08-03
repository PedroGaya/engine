#include "./image_loader.h"

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace JC2D {
    ImageResource* ImageLoader::load(std::string path) {
        int width, height, channels;
        unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

        ImageResource* resource = new ImageResource(path, width, height, channels);

        resource->setData(data);

        return resource;
    };
    void ImageLoader::unload(Resource* imageResource) {
        void* data = imageResource->getData();
        if (data)
            stbi_image_free(data);
        imageResource->setData(nullptr);
    };
}  // namespace JC2D