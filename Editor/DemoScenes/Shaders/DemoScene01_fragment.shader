#version 450 core

in vec4 vs_color;
out vec4 fs_color;

void main(void)
{
	fs_color = vs_color;
}