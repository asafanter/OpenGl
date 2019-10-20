#version 330 core
layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec2 in_texture_coords;

out vec4 color;
out vec2 texture_coords;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   gl_Position = projection * view * model * vec4(in_pos, 1.0);
   color = in_color;
   texture_coords = in_texture_coords;
};
