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


#include <iostream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    GL::Vertex v1(0.0f, 0.0f, 0.0f, GL::Color::RED);
    GL::Vertex v2(0.5f, 0.0f, 0.0f, GL::Color::RED);
    GL::Vertex v3(0.0f, 0.5f, 0.0f, GL::Color::RED);

    GL::Vertex v4(-0.7f, 0.0f, 0.0f, GL::Color::BLUE);
    GL::Vertex v5(-0.3f, 0.0f, 0.0f, GL::Color::BLUE);
    GL::Vertex v6(-0.7f, 0.2f, 0.0f, GL::Color::BLUE);
    GL::Vertex v7(-0.3f, 0.2f, 0.0f, GL::Color::BLUE);

    std::vector<GL::Vertex> vertices1 = {v1, v2, v3};
    std::vector<GL::Vertex> vertices2 = {v4, v5, v6, v7};


    GL::Window window(800, 600, "anter");
    window.setBackgroundColor(GL::Color::BLACK);

    GL::VertexShader v_shader;
    v_shader.setSource("Vertex.vsh");

    GL::FragmentShader f_shader;
    f_shader.setSource("Fragment.fsh");

    GL::GL gl;
    gl.attachWindow(window);
    gl.compileShader(v_shader).compileShader(f_shader);

    GL::Program program;
    program.attachShader(v_shader).attachShader(f_shader);

    gl.linkProgram(program);

    GL::VAO vao1;
    GL::VBO vbo1;

    GL::VAO vao2;
    GL::VBO vbo2;

    vao1.setPremitive(GL::VAO::Premitive::TRIANGLES);
    vao2.setPremitive(GL::VAO::Premitive::LINES);

    vbo1.setVertices(vertices1);
    vbo2.setVertices(vertices2);

    GL::Attribute pos_atr(0, 0);
    GL::Attribute color_atr(1, 12);

    vbo1.addAttribute(pos_atr);
    vbo1.addAttribute(color_atr);

    vbo2.addAttribute(pos_atr);
    vbo2.addAttribute(color_atr);

    gl.bindVAO(vao1);
    gl.bindVBO(vbo1);

    gl.bindVAO(vao2);
    gl.bindVBO(vbo2);

    gl.addVAO(vao1);
    gl.addVAO(vao2);

    gl.run(program);

    return 0;
}

