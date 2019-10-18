#include <glad/glad.h>
#include <glfw3.h>

#include "GL.h"
#include "Window.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Program.h"
#include "VAO.h"
#include "VBO.h"
#include "Vertex.h"
#include "Attribute.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include <iostream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    int width, height, nrChannels;
    unsigned char *data = stbi_load("C:/Users/asafanter/Desktop/wall.jpg", &width, &height, &nrChannels, 0);

    GL::Vertex v1(0.0f, 0.0f, 0.0f, GL::Color::GREEN);
    GL::Vertex v2(0.5f, 0.0f, 0.0f, GL::Color::RED);
    GL::Vertex v3(0.0f, 0.5f, 0.0f, GL::Color::BLUE);

    GL::Vertex v4(-0.7f, 0.0f, 0.0f, GL::Color::BLUE);
    GL::Vertex v5(-0.3f, 0.0f, 0.0f, GL::Color::GREEN);
    GL::Vertex v6(-0.7f, 0.2f, 0.0f, GL::Color::BLUE);
    GL::Vertex v7(-0.3f, 0.2f, 0.0f, GL::Color::RED);

    std::vector<GL::Vertex> vertices1 = {v1, v2, v3};
    std::vector<GL::Vertex> vertices2 = {v4, v5, v6, v7};


    GL::GL gl;

    GL::Window window(800, 600, "asaf anter", GL::Color::WHITE);

    gl.attachWindow(window);

    GL::Program program;

    GL::VertexShader v_s;
    GL::FragmentShader f_s;

    v_s.setSource("Vertex.vsh");
    f_s.setSource("Fragment.fsh");

    gl.compileShader(v_s).compileShader(f_s);
    program.attachShader(v_s).attachShader(f_s);

    gl.linkProgram(program);

    GL::VAO vao;

    GL::VBO vbo;

    vbo.setVertices(vertices1);
    vao.setPremitive(GL::Premitive::TRIANGLES);

    GL::Attribute pos_atr(0, 0);
    GL::Attribute color_atr(1, 12);

    vbo.addAttribute(pos_atr).addAttribute(color_atr);

    vao.setVBO(vbo);

    gl.addVAO(vao);

    gl.setLineWidth(5);

    gl.run();

    return 0;
}

