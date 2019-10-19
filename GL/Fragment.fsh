#version 330 core
in vec4 color;
out vec4 FragColor;
in vec2 texture_coords;

uniform sampler2D sampler;

void main()
{
   FragColor = texture2D(sampler, texture_coords);
};
