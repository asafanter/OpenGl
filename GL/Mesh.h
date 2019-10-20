#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>


#include "GL_types.h"
#include "Vertex.h"
#include "Texture.h"

namespace GL {

class Mesh
{
public:

    enum class RotationAxis
    {
        X,
        Y,
        Z
    };

    Mesh();
    Mesh &setVertices(const std::vector<Vertex> &vertices) {_vertices = vertices; return *this;}
    Mesh &setIndices(const std::vector<uint32> &indices) {_indices = indices; return *this;}
    Mesh &setTexture(const Texture &texture) {_texture = texture; return *this;}
    Mesh &rotate(const real32 &angle_deg, const Mesh::RotationAxis &axis);
    Mesh &rotateX(const real32 &angle_deg);
    Mesh &rotateY(const real32 &angle_deg);
    Mesh &rotateZ(const real32 &angle_deg);
    Mesh &scale(const real64 &x_scale, const real64 &y_scale, const real64 &z_scale);
    Mesh &scaleX(const real64 &factor);
    Mesh &scaleY(const real64 &factor);
    Mesh &scaleZ(const real64 &factor);
    Mesh &translate(const real64 &x_offset, const real64 &y_offset, const real64 &z_offset);
    Mesh &translateX(const real64 &offset);
    Mesh &translateY(const real64 &offset);
    Mesh &translateZ(const real64 &offset);
    Mesh &setup();
    void remove();
    Mesh &draw();

private: //members
    std::vector<Vertex> _vertices;
    std::vector<uint32> _indices;
    Texture _texture;
    uint32 _vao;
    uint32 _vbo;
    uint32 _ebo;
    glm::mat4 _model;
};

} //namespace GL



#endif // MESH_H
