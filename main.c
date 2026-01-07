#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.h"
#include "renderer.h"
#include <stdio.h>


 float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    createWindow();

    if (!window) {
        fprintf(stderr, "Window creation failed\n");
        return -1;
    }
    printf("Window sucsesfully created");


    generate(vertices,3);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        prepare();
        render(vertices,3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    cleanShaderData();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
