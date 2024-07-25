#include "./shader.h"
#include "../../logger/logger.h"

namespace JC2D {
    void Shader::compileShader(std::string path, GLenum shaderType) {
        std::string sourceCode;
        std::ifstream file;

        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            file.open(path);
            std::stringstream fileStream;
            fileStream << file.rdbuf();
            file.close();
            sourceCode = fileStream.str();
        } catch (std::ifstream::failure e) {
            JC2D_CORE_ERROR("IO error when reading from file {0}, msg: {1}", path, e.what());
        }
        const char* shaderCode = sourceCode.c_str();

        unsigned int id;
        int success;
        char infoLog[512];

        id = glCreateShader(shaderType);
        glShaderSource(id, 1, &shaderCode, nullptr);
        glCompileShader(id);

        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, 512, nullptr, infoLog);
            JC2D_CORE_ERROR("Failed to compile shader: {0}", infoLog);
        } else {
            m_shaders.push_back(id);
        };
    };

    unsigned int Shader::createProgram() {
        int success;
        char infoLog[512];

        m_id = glCreateProgram();
        for (unsigned int shader : m_shaders) {
            glAttachShader(m_id, shader);
        }
        glLinkProgram(m_id);

        glGetProgramiv(m_id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
            JC2D_CORE_ERROR("Failed to link shader program {0}: {1}", m_name, infoLog);
            return success;
        } else {
            for (unsigned int shader : m_shaders) {
                glDeleteShader(shader);
            }
            m_shaders.clear();
            return m_id;
        }
    }
}  // namespace JC2D