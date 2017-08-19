cmake_minimum_required(VERSION 3.7)
project(Amethyst)

set(CMAKE_CXX_STANDARD 14)


include_directories(${PROJECT_SOURCE_DIR}/source/)
include_directories(${PROJECT_SOURCE_DIR}/external/include)
include_directories(${PROJECT_SOURCE_DIR}/external/include/FREETYPE/)

link_directories(${PROJECT_SOURCE_DIR}/external/lib/GLEW/)
link_directories(${PROJECT_SOURCE_DIR}/external/lib/GLFW/)
link_directories(${PROJECT_SOURCE_DIR}/external/lib/FREETYPE/)

set(SOURCE_FILES
    source/opengl/shader.cpp
    source/opengl/shader.h
    source/opengl/vbo.h
    source/amethyst
    source/util/fastfileio.h
    source/util/amethystexception.h
    source/mesh/meshgenerator.h
    source/view/window.cpp
    source/view/window.h
    source/util/logger.h
    source/mesh/mesh.h
    source/opengl/framebuffer.cpp
    source/opengl/framebuffer.h
    source/opengl/texture.cpp
    source/opengl/texture.h
    source/view/camera.cpp
    source/view/camera.h
    source/math/transformation/position.cpp
    source/math/transformation/position.h
    source/math/transformation/rotation.cpp
    source/math/transformation/rotation.h
    source/math/transformation/scale.cpp
    source/math/transformation/scale.h
    source/math/transformation/transformation.cpp
    source/math/transformation/transformation.h
    source/io/wavefrontparser.h
    source/io/wavefrontparser.cpp
    source/util/stringedit.h
    source/io/keyboard.cpp
    source/io/keyboard.h
    source/view/debugcamera.cpp
    source/view/debugcamera.h
    source/math/time.cpp
    source/math/time.h
    source/math/transformation/transformationcomponent.cpp
    source/math/transformation/transformationcomponent.h
    source/math/boundingbox.cpp
    source/math/boundingbox.h
    source/util/util.h
    source/util/queue.h
    source/engine.h
    source/render/renderstructs.h
        source/compiled/shaders.h source/render/renderer/renderer2d.h source/render/renderer/renderer2d.cpp source/opengl/pixelfield.cpp source/opengl/pixelfield.h source/util/scheduler.cpp source/util/scheduler.h source/util/runnable.cpp source/util/runnable.h source/callbacks/callbackmanager.cpp source/callbacks/callbackmanager.h source/gui/text/charset.cpp source/gui/text/charset.h source/gui/text/text.cpp source/gui/text/text.h source/profiler/profiler.cpp source/profiler/profiler.h source/gui/button/button.cpp source/gui/button/button.h source/math/boundingbox2d.cpp source/math/boundingbox2d.h)


add_library(Amethyst SHARED ${SOURCE_FILES})

target_link_libraries(Amethyst glew32 glfw3 gdi32 opengl32 freetype)