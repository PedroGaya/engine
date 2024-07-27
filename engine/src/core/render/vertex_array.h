#include "./buffers.h"

namespace JC2D {
    class JC2D_API VertexArray {
       public:
        static std::shared_ptr<VertexArray> create();
        virtual ~VertexArray();

        virtual void bind();
        virtual void unbind();

        virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
        virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

        inline std::vector<std::shared_ptr<VertexBuffer>> getVertexBuffers() const { return m_vertexBuffers; }
        inline std::shared_ptr<IndexBuffer> getIndexBuffer() const { return m_indexBuffer; }

       private:
        VertexArray();
        uint32_t m_id;

        std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
    };
}  // namespace JC2D