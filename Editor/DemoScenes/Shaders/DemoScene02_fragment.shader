#version 450 core

in vec3 vs_color;
in vec3 vs_fragPos;
in vec3 vs_normal;

out vec4 color;

uniform vec3 u_lightPos;
uniform vec3 u_lightColor;
uniform float u_lightIntensity;

void main()
{
    // Normalize inputs
    vec3 norm = normalize(vs_normal);
    vec3 lightDir = normalize(u_lightPos - vs_fragPos);

    // Diffuse shading
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffColor = diff * u_lightColor * u_lightIntensity;

    // Final color
    vec3 result = (diffColor + vec3(0.1) * u_lightColor) * vs_color; // Adding ambient lighting
    color = vec4(result, 1.0);
}