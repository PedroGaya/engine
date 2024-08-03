#pragma once

#include "../../defines.h"
#include "./resource.h"

namespace JC2D {
    class JC2D_API Loader {
       public:
        Loader() = default;
        ~Loader() = default;

        virtual Resource* load(std::string fullPath) = 0;
        virtual void unload(Resource* resource) = 0;

       private:
    };
}  // namespace JC2D