#include <glad/glad.h>
#include <glfw3.h>

#include "GL.h"
#include "Window.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Program.h"
#include "VAO.h"
#include "Vertex.h"
#include "Attribute.h"
#include "Texture.h"


#include <iostream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }


    GL::Vertex v1(-0.9f, -0.9f, 0.0f, GL::Color::GREEN);
    GL::Vertex v2(0.9f, -0.9f, 0.0f, GL::Color::RED);
    GL::Vertex v3(0.0f, 0.9f, 0.0f, GL::Color::BLUE);
    v1.setTextureCoords(-1.0f, -1.0f);
    v2.setTextureCoords(1.0f, -1.0f);
    v3.setTextureCoords(0.0f, 1.0f);

    GL::Vertex v4(-0.7f, 0.0f, 0.0f, GL::Color::BLUE);
    GL::Vertex v5(-0.3f, 0.0f, 0.0f, GL::Color::GREEN);
    GL::Vertex v6(-0.7f, 0.2f, 0.0f, GL::Color::BLUE);
    GL::Vertex v7(-0.3f, 0.2f, 0.0f, GL::Color::RED);

    std::vector<GL::Vertex> vertices1 = {v1, v2, v3};
    std::vector<GL::Vertex> vertices2 = {v4, v5, v6, v7};

    GL::GL gl;

    GL::Window window(800, 600, "asaf anter", GL::Color::BLACK);

    gl.attachWindow(window);

    GL::Program program;
    GL::VertexShader v_s;
    GL::FragmentShader f_s;

    v_s.setSource("Vertex.vsh");
    f_s.setSource("Fragment.fsh");

    v_s.compile();
    f_s.compile();

    program.attachShader(v_s).attachShader(f_s);
    program.link();

    GL::VAO vao1;

    GL::Texture texture;
    texture.setImage("C:/Users/asafanter/Desktop/wall.jpg");

    GL::Attribute pos_atr(0, 0);
    GL::Attribute color_atr(1, 12);
    GL::Attribute texture_atr(2, 28);

    vao1.addAttribute(pos_atr).addAttribute(color_atr).addAttribute(texture_atr);
    vao1.setVertices(vertices1);

    vao1.setPremitive(GL::Premitive::TRIANGLES);


    gl.addVAO(vao1);


    gl.run(program);

    return 0;
}

