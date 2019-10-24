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

    //front side
    GL::Vertex v1(-0.5f, 0.5f, 0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v2(0.5f, 0.5f, 0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v3(-0.5f, -0.5f, 0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v4(0.5f, -0.5f, 0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right

    //right side
    GL::Vertex v5(0.5f, 0.5f, 0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v6(0.5f, 0.5f, -0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v7(0.5f, -0.5f, 0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v8(0.5f, -0.5f, -0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right

    //left side
    GL::Vertex v9(-0.5f, 0.5f, -0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v10(-0.5f, 0.5f, 0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v11(-0.5f, -0.5f, -0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v12(-0.5f, -0.5f, 0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right

    //back side
    GL::Vertex v13(-0.5f, -0.5f, -0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v14(0.5f, -0.5f, -0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v15(-0.5f, 0.5f, -0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v16(0.5f, 0.5f, -0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right

    //top side
    GL::Vertex v17(-0.5f, 0.5f, -0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v18(0.5f, 0.5f, -0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v19(-0.5f, 0.5f, 0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v20(0.5f, 0.5f, 0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right

    //down side
    GL::Vertex v21(-0.5f, -0.5f, 0.5f, GL::Color::YELLOW, 0.0f, 1.0f); // top left
    GL::Vertex v22(0.5f, -0.5f, 0.5f, GL::Color::RED, 1.0f, 1.0f); //top right
    GL::Vertex v23(-0.5f, -0.5f, -0.5f, GL::Color::BLUE, 0.0f, 0.0f); //bottom left
    GL::Vertex v24(0.5f, -0.5f, -0.5f, GL::Color::GREEN, 1.0f, 0.0f); // bottom right


    std::vector<GL::Vertex> vertices = {v1, v2, v3, v4,
                                        v5, v6, v7, v8,
                                        v9, v10, v11, v12,
                                        v13, v14, v15, v16,
                                        v17, v18, v19, v20,
                                        v21, v22, v23, v24};

    GL::GL gl;

    GL::Window window(800, 600, "asaf anter", GL::Color::BLACK);
//    window.maximize();

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

    GL::Mesh cube;
    cube.setTexture(texture);
    cube.setVertices(vertices);
    cube.setIndices({0, 2, 3, 0, 1, 3,
                     4, 6, 7, 4, 5, 7,
                     8, 10, 11, 8, 9, 11,
                     12, 14, 15, 12, 13, 15,
                     16, 18, 19, 16, 17, 19,
                     20, 22, 23, 20, 21, 23
                     });
    cube.setup();

    gl.addMesh(cube);


    gl.run(program);

    return 0;
}






