R"(
#version 330

layout(location = 0) in vec3 in_vertice;
layout(location = 1) in vec2 in_uv;

out vec3 fragment;
out vec2 uv;

uniform mat4 transformation;
uniform mat4 projection;

void main() {
    gl_Position = projection * transformation * vec4(in_vertice, 1);

    fragment = in_vertice;
    uv = vec2(in_uv.x, in_uv.y);
}


)"