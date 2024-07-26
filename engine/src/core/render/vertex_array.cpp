#include "./vertex_array.h"

namespace JC2D {
    VertexArray::VertexArray() {
        glCreateVertexArrays(1, &m_id);
    };
    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_id);
    };

    void VertexArray::bind() {
        glBindVertexArray(m_id);
    };
    void VertexArray::unbind() {
        glBindVertexArray(0);
    };

    void VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
        glBindVertexArray(m_id);

        vertexBuffer->bind();
        auto layout = vertexBuffer->getLayout();

        int index = 0;
        for (auto& element : layout) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index,
                element.count(),
                JC2D_FLOAT,
                element.normalized,
                layout.getStride(),
                (const void*)element.offset);
            index++;
        }

        m_vertexBuffers.push_back(vertexBuffer);
    };
    void VertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
        glBindVertexArray(m_id);
        indexBuffer->bind();

        m_indexBuffer = indexBuffer;
    };

}  // namespace JC2D