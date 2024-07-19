#include "../defines.h"
#include "../jc2dpch.h"

namespace JC2D {
    class JC2D_API Metrics {
       public:
        Metrics()
            : m_enabled(true),
              m_maxFrameTimes(1000) {};
        virtual ~Metrics() = default;

        inline bool isEnabled() { return m_enabled; }

        double getAverageFPS();
        double getAverageDeltaTimeMilliseconds();

        void pushFrameTime(double frame_time);

       private:
        bool m_enabled;

        unsigned int m_maxFrameTimes;
        std::vector<double> m_frameTimesMilliseconds;
    };
}  // namespace JC2D