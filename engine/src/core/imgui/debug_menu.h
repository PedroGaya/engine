#include "../../defines.h"

namespace JC2D {
    class JC2D_API DebugMenu {
       public:
        DebugMenu()
            : m_enabled(true) {};
        virtual ~DebugMenu() = default;

        static void renderApplicationInfo();

       private:
        bool m_enabled;
    };
}  // namespace JC2D