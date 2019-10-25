#include <glad/glad.h>
#include <glfw3.h>

#include "GL.h"
#include "Window.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "Program.h"
#include "ColoredVertex.h"
#include "TexturedVertex.h"
#include "Texture.h"
#include "ColoredBuffer.h"
#include "TexturedBuffer.h"

#include <iostream>
#include <string>
#include <chrono>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main()
{

/*****************colored cube*************************************************/

//    //front side
//    GL::ColoredVertex v1(-0.5f, 0.5f, 0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v2(0.5f, 0.5f, 0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v3(-0.5f, -0.5f, 0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v4(0.5f, -0.5f, 0.5f, GL::Color::GREEN); // bottom right

//    //right side
//    GL::ColoredVertex v5(0.5f, 0.5f, 0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v6(0.5f, 0.5f, -0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v7(0.5f, -0.5f, 0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v8(0.5f, -0.5f, -0.5f, GL::Color::GREEN); // bottom right

//    //left side
//    GL::ColoredVertex v9(-0.5f, 0.5f, -0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v10(-0.5f, 0.5f, 0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v11(-0.5f, -0.5f, -0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v12(-0.5f, -0.5f, 0.5f, GL::Color::GREEN); // bottom right

//    //back side
//    GL::ColoredVertex v13(-0.5f, -0.5f, -0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v14(0.5f, -0.5f, -0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v15(-0.5f, 0.5f, -0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v16(0.5f, 0.5f, -0.5f, GL::Color::GREEN); // bottom right

//    //top side
//    GL::ColoredVertex v17(-0.5f, 0.5f, -0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v18(0.5f, 0.5f, -0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v19(-0.5f, 0.5f, 0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v20(0.5f, 0.5f, 0.5f, GL::Color::GREEN); // bottom right

//    //down side
//    GL::ColoredVertex v21(-0.5f, -0.5f, 0.5f, GL::Color::YELLOW); // top left
//    GL::ColoredVertex v22(0.5f, -0.5f, 0.5f, GL::Color::RED); //top right
//    GL::ColoredVertex v23(-0.5f, -0.5f, -0.5f, GL::Color::BLUE); //bottom left
//    GL::ColoredVertex v24(0.5f, -0.5f, -0.5f, GL::Color::GREEN); // bottom right

//    std::vector<GL::ColoredVertex> vertices = {v1, v2, v3, v4,
//                                        v5, v6, v7, v8,
//                                        v9, v10, v11, v12,
//                                        v13, v14, v15, v16,
//                                        v17, v18, v19, v20,
//                                        v21, v22, v23, v24};

//    GL::ColoredBuffer buffer;


/*****************textured cube*************************************************/

    //front side
    GL::TexturedVertex v1(-0.5f, 0.5f, 0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v2(0.5f, 0.5f, 0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v3(-0.5f, -0.5f, 0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v4(0.5f, -0.5f, 0.5f, 1.0f, 0.0f); // bottom right

    //right side
    GL::TexturedVertex v5(0.5f, 0.5f, 0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v6(0.5f, 0.5f, -0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v7(0.5f, -0.5f, 0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v8(0.5f, -0.5f, -0.5f, 1.0f, 0.0f); // bottom right

    //left side
    GL::TexturedVertex v9(-0.5f, 0.5f, -0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v10(-0.5f, 0.5f, 0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v11(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v12(-0.5f, -0.5f, 0.5f, 1.0f, 0.0f); // bottom right

    //back side
    GL::TexturedVertex v13(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v14(0.5f, -0.5f, -0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v15(-0.5f, 0.5f, -0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v16(0.5f, 0.5f, -0.5f, 1.0f, 0.0f); // bottom right

    //top side
    GL::TexturedVertex v17(-0.5f, 0.5f, -0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v18(0.5f, 0.5f, -0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v19(-0.5f, 0.5f, 0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v20(0.5f, 0.5f, 0.5f, 1.0f, 0.0f); // bottom right

    //down side
    GL::TexturedVertex v21(-0.5f, -0.5f, 0.5f, 0.0f, 1.0f); // top left
    GL::TexturedVertex v22(0.5f, -0.5f, 0.5f, 1.0f, 1.0f); //top right
    GL::TexturedVertex v23(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f); //bottom left
    GL::TexturedVertex v24(0.5f, -0.5f, -0.5f, 1.0f, 0.0f); // bottom right

    std::vector<GL::TexturedVertex> vertices = {v1, v2, v3, v4,
                                        v5, v6, v7, v8,
                                        v9, v10, v11, v12,
                                        v13, v14, v15, v16,
                                        v17, v18, v19, v20,
                                        v21, v22, v23, v24};





/*********************************************************************************/

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


    GL::ColoredBuffer point_cloud_buffer;
    std::vector<GL::ColoredVertex> point_cloud_vertices;

    for(int32 r_id = 0; r_id < 3; r_id++)
    {
        real32 r = 0.3f + 0.1f * r_id;
        for(int32 v_id = 0; v_id < 100; v_id++)
        {
            real32 v = 1.8f * v_id;
            for(int32 h_id = 0; h_id < 100; h_id++)
            {
                real32 h = 7.2f * h_id;
                real32 x = REAL32(REAL64(r) * sin(REAL64(h) * M_PI / 180.0) * cos(REAL64(v) * M_PI / 180.0));
                real32 y = REAL32(REAL64(r) * sin(REAL64(h) * M_PI / 180.0) * sin(REAL64(v) * M_PI / 180.0));
                real32 z = REAL32(REAL64(r) * cos(REAL64(h) * M_PI / 180.0));
                GL::ColoredVertex cv(x, y , z, GL::Color(GL::Color::BLUE));

                point_cloud_vertices.emplace_back(cv);
            }
        }
    }

    std::vector<uint32> point_cloud_indices;
    for(int i = 0; i < 30000; i++)
    {
        point_cloud_indices.emplace_back(i);
    }

    point_cloud_buffer.setVertices(point_cloud_vertices);

    GL::Mesh point_cloud;
    point_cloud.setPrimitive(GL::Mesh::Premitive::POINTS);
    gl.setPointSize(3);
    point_cloud.setIndices(point_cloud_indices);

    point_cloud.setupBuffer(point_cloud_buffer);

    GL::TexturedBuffer buffer;
    buffer.setVertices(vertices);

    GL::Texture texture;
    texture.setImage("C:/Users/asafanter/Desktop/wall.jpg");
    buffer.setTexture(texture);


    GL::Mesh cube;
    cube.setIndices({0, 2, 3, 0, 1, 3,
                     4, 6, 7, 4, 5, 7,
                     8, 10, 11, 8, 9, 11,
                     12, 14, 15, 12, 13, 15,
                     16, 18, 19, 16, 17, 19,
                     20, 22, 23, 20, 21, 23
                     });

    cube.setupBuffer(buffer);


    gl.addMesh(point_cloud);


    gl.run(program);

    return 0;
}






