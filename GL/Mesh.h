#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>


#include "GL_types.h"
#include "ColoredVertex.h"
#include "Texture.h"
#include "Program.h"
#include "Buffer.h"

namespace GL {

class Mesh
{
public:

    Mesh();
    Mesh &setupBuffer(const Buffer &buffer);
    Mesh &setIndices(const std::vector<uint32> &indices) {_indices = indices; return *this;}
    Mesh &rotate(const real64 &x_deg, const real64 &y_deg, const real64 &z_deg);
    Mesh &rotateX(const real64 &angle_deg);
    Mesh &rotateY(const real64 &angle_deg);
    Mesh &rotateZ(const real64 &angle_deg);
    Mesh &scale(const real64 &x_scale, const real64 &y_scale, const real64 &z_scale);
    Mesh &scaleX(const real64 &factor);
    Mesh &scaleY(const real64 &factor);
    Mesh &scaleZ(const real64 &factor);
    Mesh &translate(const real64 &x_offset, const real64 &y_offset, const real64 &z_offset);
    Mesh &translateX(const real64 &offset);
    Mesh &translateY(const real64 &offset);
    Mesh &translateZ(const real64 &offset);
    Mesh &setPosition(const real64 &x, const real64 &y, const real64 &z);
    Mesh &setup();
    void remove();
    Mesh &draw(const Program &program);

private: //methods
    bool isSetupForDrawing() const;
    Mesh &trySetTexture();

private: //members
    std::vector<uint32> _indices;
    uint32 _vao;
    uint32 _vbo;
    uint32 _ebo;
    glm::mat4 _model;
    bool _is_setup;
    bool _is_textured;
};

} //namespace GL



#endif // MESH_H
