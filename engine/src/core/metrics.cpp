#include "../jc2dpch.h"

#include "./metrics.h"

namespace JC2D {
    double Metrics::getAverageDeltaTimeMilliseconds() {
        int size = m_frameTimesMilliseconds.size();
        if (size > 0) {
            return 1000 * std::reduce(m_frameTimesMilliseconds.begin(), m_frameTimesMilliseconds.end(), 0.0) / size;
        } else {
            return 0;
        }
    };

    double Metrics::getAverageFPS() {
        auto sum = std::reduce(m_frameTimesMilliseconds.begin(), m_frameTimesMilliseconds.end(), 0.0);
        if (sum > 0) {
            return m_frameTimesMilliseconds.size() / sum;
        } else {
            return 0;
        }
    };

    void Metrics::pushFrameTime(double frame_time) {
        if (m_frameTimesMilliseconds.size() < m_maxFrameTimes) {
            m_frameTimesMilliseconds.push_back(frame_time);
        } else {
            m_frameTimesMilliseconds.erase(m_frameTimesMilliseconds.begin());
            m_frameTimesMilliseconds.push_back(frame_time);
        }
    }
}  // namespace JC2D