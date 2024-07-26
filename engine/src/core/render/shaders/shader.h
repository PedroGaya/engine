#include "../../../defines.h"
#include "../../../jc2dpch.h"

namespace JC2D {
    class JC2D_API Shader {
       public:
        Shader(std::string name) : m_name(name) {};
        inline ~Shader() { glDeleteProgram(m_id); };

        virtual void compileShader(std::string path, GLenum shaderType);
        virtual unsigned int createProgram();

        inline void use() { glUseProgram(m_id); }
        inline unsigned int getId() const { return m_id; }

        inline void setUniform4f(const std::string &name, float v1, float v2, float v3, float v4) const {
            glUniform4f(glGetUniformLocation(m_id, name.c_str()), v1, v2, v3, v4);
        };

       private:
        std::string m_name;
        std::vector<u_int32_t> m_shaders;
        unsigned int m_id;
    };
}  // namespace JC2D