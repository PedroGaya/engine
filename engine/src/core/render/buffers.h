#include "../../defines.h"
#include "../../jc2dpch.h"

namespace JC2D {

#define JC2D_FLOAT 0x1406  // From OpenGL: GL_FLOAT

    enum class RenderDataType {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4
    };

    static uint32_t getRenderDataTypeSize(RenderDataType type) {
        switch (type) {
            case RenderDataType::Float:
                return 4;
            case RenderDataType::Float2:
                return 4 * 2;
            case RenderDataType::Float3:
                return 4 * 3;
            case RenderDataType::Float4:
                return 4 * 4;
        }
        return 0;
    }

    struct BufferElement {
        std::string name;
        RenderDataType type;
        uint32_t offset;
        uint32_t size;
        bool normalized;

        BufferElement(RenderDataType type, const std::string& name, bool normalized = false)
            : name(name), type(type), size(getRenderDataTypeSize(type)), offset(0), normalized(normalized) {}

        uint32_t count() const {
            switch (type) {
                case RenderDataType::Float:
                    return 1;
                case RenderDataType::Float2:
                    return 2;
                case RenderDataType::Float3:
                    return 3;
                case RenderDataType::Float4:
                    return 4;
            }
            return 0;
        }
    };

    class JC2D_API BufferLayout {
       public:
        BufferLayout(std::initializer_list<BufferElement> elements)
            : m_elements(elements) {
            calculateOffsetAndStride();
        };
        inline const std::vector<BufferElement>& getElements() const { return m_elements; }
        inline const uint32_t getStride() const { return m_stride; }

        std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
        std::vector<BufferElement>::iterator end() { return m_elements.end(); }

       private:
        void calculateOffsetAndStride() {
            uint32_t offset = 0;
            for (auto& element : m_elements) {
                element.offset = offset;
                offset += element.size;
                m_stride += element.size;
            }
        }

       private:
        std::vector<BufferElement> m_elements;
        uint32_t m_stride;
    };

    class JC2D_API VertexBuffer {
       public:
        static std::shared_ptr<VertexBuffer> create(float* vertices, uint32_t size, BufferLayout layout);
        virtual ~VertexBuffer();

        virtual void bind();
        virtual void unbind();

        inline void setLayout(const BufferLayout& layout) { m_layout = layout; }
        inline BufferLayout getLayout() const { return m_layout; }

       private:
        VertexBuffer(float* vertices, uint32_t size, BufferLayout layout);

        uint32_t m_id = 0;
        BufferLayout m_layout;
        float* m_vertices;
    };
    class JC2D_API IndexBuffer {
       public:
        static std::shared_ptr<IndexBuffer> create(uint32_t* indices, uint32_t count);
        virtual ~IndexBuffer();

        void bind();
        void unbind();

        inline uint32_t getCount() const { return m_count; }

       private:
        IndexBuffer(uint32_t* indices, uint32_t count);

        uint32_t m_id = 0;
        uint32_t m_count;
    };
}  // namespace JC2D