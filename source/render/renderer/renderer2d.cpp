/* Created by David Klostermann on 09.08.2017. */

#include "renderer2d.h"

namespace AM{
    VBO<glm::vec3, 3> Renderer2D::m_plane2D;
    VBO<glm::vec2, 2> Renderer2D::m_plane2D_uv;
    glm::mat4 Renderer2D::m_projection;
    Shader* Renderer2D::m_texture2Dshader;
    Window* Renderer2D::m_window;
}

void AM::Renderer2D::addToBatch(AM::Texture *texture, AM::Transformation transformation) {
    m_batchTextures.push(texture);
    m_batchTransformations.push(transformation);
}

void AM::Renderer2D::render() {
    if(!m_plane2D.vboExists()){
        throwAmethystException( "Renderer is not initalized yet");
    }

    m_texture2Dshader->bind();

    m_plane2D.bind(0);
    m_plane2D_uv.bind(1);

    m_texture2Dshader->setUniform("projection", m_projection);

    while(m_batchTextures.size() > 0){
        m_texture2Dshader->setUniform("transformation", m_batchTransformations.top().getMatrix());
        m_batchTextures.top()->bind();

        m_batchTransformations.pop();
        m_batchTextures.pop();
        glDrawArrays(GL_TRIANGLES, 0, m_plane2D.getVerticeAmount());
    }
}
