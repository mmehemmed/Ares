#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "window.h"
#include "renderer.h"
#include <stdio.h>

 extern GLFWwindow* window;

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

    initializeRenderer();
    loadModelData(vertices,3);

    if (!window) {
        fprintf(stderr, "Window creation failed\n");
        return -1;
    }
    printf("Window sucsesfully created");

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        prepareRenderer();
        render(3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    cleanShaderData();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
