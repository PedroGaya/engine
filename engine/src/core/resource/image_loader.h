#pragma once

#include "./loader.h"
#include "./image.h"

namespace JC2D {
    class ImageLoader : public Loader {
       public:
        ImageResource* load(std::string path) override;
        void unload(Resource* imageResource) override;
    };
}  // namespace JC2D