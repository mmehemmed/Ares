// window.c
#include "window.h"
#include "glad/glad.h"
#include <stdio.h>


GLFWwindow* window = NULL;  // define it once here


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    //
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void createWindow() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);


    window = glfwCreateWindow(1600, 900, "Minecraft", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return;
    }


    glfwSetWindowAspectRatio(window,16,9);
    glfwSetKeyCallback(window,key_callback);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    glfwSwapInterval(1);
    glViewport(0, 0, 1600, 900);
}



