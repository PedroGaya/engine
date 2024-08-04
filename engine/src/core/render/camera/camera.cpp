#include "./camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace JC2D {
    Camera::Camera(float left, float right, float bottom, float top)
        : m_projectionMatrix(glm::ortho(left, right, bottom, top)),
          m_viewMatrix(1.0f) {
        m_projectionViewMatrix = m_projectionMatrix * m_viewMatrix;
    }

    void Camera::update() {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
                              glm::rotate(glm::mat4(1.0f), m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));

        m_viewMatrix = glm::inverse(transform);
        m_projectionViewMatrix = m_projectionMatrix * m_viewMatrix;
    }
}  // namespace JC2D