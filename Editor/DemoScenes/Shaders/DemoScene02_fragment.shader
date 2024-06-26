#version 450 core

in vec3 vs_color;
in vec3 vs_fragPos;
in vec3 vs_normal;

out vec4 color;

uniform vec3 u_lightDir;
uniform vec3 u_lightColor;
uniform float u_lightIntensity;

void main()
{
    // Normalize inputs
    vec3 norm = normalize(vs_normal);
    vec3 lightDir = normalize(-u_lightDir);

    // Diffuse shading
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffColor = diff * u_lightColor;

    // Final color
    vec3 result = (diffColor + vec3(0.1)) * vs_color; // Adding ambient lighting
    color = vec4(result, 1.0);
}