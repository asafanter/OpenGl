#include <glad/glad.h>
#include <glfw3.h>

#include "GL.h"
#include "Window.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Program.h"
#include "Vertex.h"
#include "Texture.h"

#include <iostream>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{
    GL::Vertex v1(-0.9f, -0.9f, 0.0f, GL::Color::GREEN);
    GL::Vertex v2(0.9f, -0.9f, 0.0f, GL::Color::RED);
    GL::Vertex v3(0.0f, 0.9f, 0.0f, GL::Color::BLUE);
    v1.setTextureCoords(0.0f, 0.0f);
    v2.setTextureCoords(1.0f, 0.0f);
    v3.setTextureCoords(0.0f, 1.0f);

    GL::Vertex v4(0.5f, 0.5f, 0.0f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v5(0.5f, -0.5f, 0.0f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right
    GL::Vertex v6(-0.5f, -0.5f, 0.0f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v7(-0.5f, 0.5f, 0.0f, GL::Color::BLUE, 0.0f, 1.0f); // top left

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

    GL::Texture texture;
    texture.setImage("C:/Users/asafanter/Desktop/wall.jpg");

    GL::Mesh quad;
    quad.setTexture(texture);
    quad.setVertices(vertices2);
    quad.setIndices({0, 1, 3, 1, 2, 3});
    quad.setup();

//    GL::Mesh tri;
//    tri.setTexture(texture);
//    tri.setVertices(vertices1);
//    tri.setIndices({0, 1, 2});
//    tri.setup();

    gl.addMesh(quad);

    gl.setPointSize(5);
    gl.run(program);

    return 0;
}






