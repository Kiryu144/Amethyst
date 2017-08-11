/* Created by David Klostermann on 21.07.2017. */
#ifndef AMETHYST_SHADERS_H
#define AMETHYST_SHADERS_H

#include <string>

namespace AM{
namespace compiled{
namespace shader{

std::string texture2D_vert =
#include "compiled/shaders/texture2d.vert"
;

std::string texture2D_frag =
#include "compiled/shaders/texture2d.frag"
;

}
}
}

#endif
