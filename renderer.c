#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "renderer.h"

const char *vertexShaderSource = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragShaderSource = 
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.2f, 0.2f, 1.0f);\n"
"}\0";

unsigned int vertexShader;
unsigned int fragmentShader;
unsigned int shaderProgram;
unsigned int VBO;
unsigned int VAO;

void createShaders(){
    int  success;
    char infoLog[512];

    //VERTEX SHADER  
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        fprintf(stderr,"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    }

    //FRAGMENT SHADER
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        fprintf(stderr,"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    }
}
void createShaderProgram(){
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
}
void cleanShaderData(){
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}






void loadModelData(float vertices[],int number_of_vertices){
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, number_of_vertices * 3 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
}

//    loadModelData(vertices,number_of_vertices);
void initializeRenderer(){
    glEnable(GL_DEPTH_TEST);
    createShaders();
    createShaderProgram();
} 

void prepareRenderer(){
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void render(int number_of_vertices){
    glBindVertexArray(VAO);
    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, number_of_vertices);
}