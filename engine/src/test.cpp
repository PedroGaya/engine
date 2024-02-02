#include <glad/glad.h>
#include <stb_image/stb_image.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <libpng16/png.h>
#include <AL/al.h>
#include <entt/entt.hpp>

#include <stdio.h>

void print_int(int num) {
    printf("Number is: %i\n", num);
}

void foo() {
    glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
    glm::mat4 Model = glm::mat4(1.0);
    Model[3] = glm::vec4(1.0, 1.0, 0.0, 1.0);
    glm::vec4 Transformed = Model * Position;
    printf("what?\n");
}