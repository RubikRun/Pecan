#version 450 core

layout (location = 0) in vec3 vao_position;
layout (location = 1) in vec3 vao_color;
layout (location = 2) in vec3 vao_normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 vs_color;
out vec3 vs_fragPos;
out vec3 vs_normal;

void main()
{
    vs_color = vao_color;
    vs_fragPos = vec3(u_model * vec4(vao_position, 1.0));
    vs_normal = mat3(transpose(inverse(u_model))) * vao_normal;

    gl_Position = u_projection * u_view * u_model * vec4(vao_position, 1.0f);
}