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


        real32 r = 0.5f;
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


    point_cloud_buffer.setVertices(point_cloud_vertices);

    GL::Mesh point_cloud;
    point_cloud.setPrimitive(GL::Mesh::Premitive::POINTS);
    gl.setPointSize(3);

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

    GL::ColoredVertex as1(0.0f, 0.0f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as2(0.2f, 0.0f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as3(0.0f, 0.0f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as4(0.0f, 0.2f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as5(0.0f, 0.0f, 0.0f, GL::Color(GL::Color::BLUE));
    GL::ColoredVertex as6(0.0f, 0.0f, 0.2f, GL::Color(GL::Color::BLUE));

    GL::ColoredVertex as7(0.2f, 0.0f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as8(0.17f, 0.03f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as9(0.2f, 0.0f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as10(0.17f, -0.03f, 0.0f, GL::Color(GL::Color::RED));
    GL::ColoredVertex as11(0.0f, 0.2f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as12(-0.03f, 0.17f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as13(0.0f, 0.2f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as14(0.03f, 0.17f, 0.0f, GL::Color(GL::Color::GREEN));
    GL::ColoredVertex as15(0.0f, 0.0f, 0.2f, GL::Color(GL::Color::BLUE));
    GL::ColoredVertex as16(-0.03f, 0.0f, 0.17f, GL::Color(GL::Color::BLUE));
    GL::ColoredVertex as17(0.0f, 0.0f, 0.2f, GL::Color(GL::Color::BLUE));
    GL::ColoredVertex as18(0.03f, 0.0f, 0.17f, GL::Color(GL::Color::BLUE));

    std::vector<GL::ColoredVertex> axis_system_vertices = {as1, as2, as3, as4, as5, as6,
                                                          as7, as8, as9, as10, as11, as12,
                                                          as13, as14, as15, as16, as17, as18};
    GL::ColoredBuffer axis_system_buffer;
    axis_system_buffer.setVertices(axis_system_vertices);

    GL::Mesh axis_system;
    axis_system.setStatic(true);
    axis_system.setPrimitive(GL::Mesh::Premitive::LINES);
    axis_system.setupBuffer(axis_system_buffer);



    GL::Mesh surface;
    surface.setPrimitive(GL::Mesh::Premitive::LINES);

    std::vector<GL::ColoredVertex> surface_vertices;
    for(int i = 0; i < 21; i++)
    {
        real32 c = 40.0f/255.0f;
        GL::ColoredVertex v1(-1.0f + (1.0f/10.0f) * i, -1.0f, 0.0f, GL::Color(c, c, c, 1.0f));
        GL::ColoredVertex v2(-1.0f + (1.0f/10.0f) * i, 1.0f, 0.0f, GL::Color(c, c, c, 1.0f));
        surface_vertices.emplace_back(v1);
        surface_vertices.emplace_back(v2);

        GL::ColoredVertex v3(-1.0f, -1.0f + (1.0f/10.0f) * i, 0.0f, GL::Color(c, c, c, 1.0f));
        GL::ColoredVertex v4(1.0f, -1.0f + (1.0f/10.0f) * i, 0.0f, GL::Color(c, c, c, 1.0f));
        surface_vertices.emplace_back(v3);
        surface_vertices.emplace_back(v4);
    }

    GL::ColoredBuffer surface_buffer;
    surface_buffer.setVertices(surface_vertices);

    surface.setupBuffer(surface_buffer);

    gl.addMesh(axis_system).addMesh(surface).addMesh(point_cloud);


    gl.run(program);

    return 0;
}






