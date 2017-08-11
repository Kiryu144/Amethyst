/* Created by David Klostermann on 29.07.2017. */
#ifndef AMETHYST_RENDERER2D_H
#define AMETHYST_RENDERER2D_H

#include "util/queue.h"
#include "compiled/shaders.h"
#include "opengl/texture.h"
#include "math/transformation/transformation.h"
#include "util/util.h"
#include "opengl/vbo.h"
#include "opengl/shader.h"
#include "view/window.h"

#include <stack>

#define AM_RENDERER_NOT_INITIALIZED 1

namespace AM{

class Renderer2D {
private:
    static VBO<glm::vec3, 3> m_plane2D;
    static VBO<glm::vec2, 2> m_plane2D_uv;
    static Shader* m_texture2Dshader;
    static Window* m_window;
    static glm::mat4 m_projection;


    std::stack<Texture*> m_batchTextures;
    std::stack<Transformation> m_batchTransformations;
public:
    static void init(Window* window){
        m_window = window;
        m_plane2D.upload(AM::plane);
        m_plane2D_uv.upload(AM::plane_uv);

        m_projection = glm::ortho(0.0f, m_window->getSize().x , m_window->getSize().y, 0.0f);

        m_texture2Dshader = new Shader(compiled::shader::texture2D_vert, compiled::shader::texture2D_frag, SHADER_CODE);
    }

    void addToBatch(Texture* texture, Transformation transformation);

    void render();
};

}

#endif
