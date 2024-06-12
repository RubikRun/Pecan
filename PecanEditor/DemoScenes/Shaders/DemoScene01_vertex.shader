#version 450 core

layout (location = 0) in vec4 attr_offset;
layout (location = 1) in vec4 attr_color;

out vec4 vs_color;

void main(void)
{
	const vec4 vertices[3] = vec4[3](
		vec4(0.5, -0.5, 0.5, 1.0),
		vec4(-0.5, -0.5, 0.5, 1.0),
		vec4(0.5, 0.5, 0.5, 1.0)
	);
	gl_Position = vertices[gl_VertexID] + attr_offset;
	vs_color = attr_color;
}