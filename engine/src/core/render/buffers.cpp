#include "./buffers.h"

namespace JC2D {
    // Vertex Buffer

    std::shared_ptr<VertexBuffer> VertexBuffer::create(float* vertices, uint32_t size, BufferLayout layout) {
        return std::shared_ptr<VertexBuffer>(new VertexBuffer(vertices, size, layout));
    }
    VertexBuffer::VertexBuffer(float* vertices, uint32_t size, BufferLayout layout)
        : m_layout(layout), m_vertices(vertices) {
        glCreateBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    };
    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_id);
    };

    void VertexBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    };
    void VertexBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    };

    // Index Buffer

    std::shared_ptr<IndexBuffer> IndexBuffer::create(uint32_t* indices, uint32_t count) {
        return std::shared_ptr<IndexBuffer>(new IndexBuffer(indices, count));
    }
    IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t count)
        : m_count(count) {
        glCreateBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    };
    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_id);
    };

    void IndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    };
    void IndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };

}  // namespace JC2D