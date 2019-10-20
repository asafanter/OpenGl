#version 330 core
in vec4 color;
out vec4 FragColor;
in vec2 texture_coords;

uniform sampler2D sampler;
uniform int is_texture_set;

void main()
{
    if(is_texture_set == 1)
    {
        FragColor = texture2D(sampler, texture_coords);
    }
    else
    {
        FragColor = color;
    }
};
