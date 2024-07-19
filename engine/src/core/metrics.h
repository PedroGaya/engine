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
        inline double getUptimeSeconds() { return m_uptime; };

        void pushFrameTime(double frame_time);
        inline void setUptime(double uptime) { m_uptime = uptime; };

       private:
        bool m_enabled;

        unsigned int m_maxFrameTimes;
        std::vector<double> m_frameTimesMilliseconds;

        double m_uptime;
    };
}  // namespace JC2D