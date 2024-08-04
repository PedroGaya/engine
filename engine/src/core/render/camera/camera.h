#pragma once

#include "../../defines.h"
#include "../../../jc2dpch.h"

namespace JC2D {
    class JC2D_API Camera {
        Camera(float left, float right, float bottom, float top);

        inline void setPositon(const glm::vec3& pos) {
            m_position = pos;
            update();
        }
        inline glm::vec3 getPositon() { return m_position; }

        inline void setRotation(float rotation) {
            m_rotation = rotation;
            update();
        }
        inline float getRotation() { return m_rotation; };

        inline const glm::mat4 getProjectionMatrix() { return m_projectionMatrix; };
        inline const glm::mat4 getViewMatrix() { return m_viewMatrix; };

       private:
        void update();

       private:
        glm::vec3 m_position;
        float m_rotation = 0.0;

        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionViewMatrix;
    };
}  // namespace JC2D