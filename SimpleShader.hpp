/** @file SimpleShader.hpp
 * @brief Sets up a default Gouraud Shader with vertex position and color inputs
 * @author Dr. Jeffrey Paone
 *
 * @copyright MIT License Copyright (c) 2020 Dr. Jeffrey Paone
 *
 *	These functions, classes, and constants help minimize common
 *	code that needs to be written.
 *
 *	@warning NOTE: This header file will only work with OpenGL 4.1
 *	@warning NOTE: This header file depends upon glm
 *	@warning NOTE: This header file depends upon GLEW
 */

#ifndef CSCI441_SIMPLE_SHADER_HPP
#define CSCI441_SIMPLE_SHADER_HPP

#include <GL/glew.h>

#include <glm/glm.hpp>

#include <string>
#include <vector>

#include "objects.hpp"
#include "ShaderUtils.hpp"

//**********************************************************************************

namespace CSCI441 {

    /**
     * @namespace SimpleShader2
     * @brief Abstracts the process of working with a 2D shader program
     */
    namespace SimpleShader2 {
        /**
         * @brief turns on Flat Shading
         * @warning must call prior to setupSimpleShader
         */
        [[maybe_unused]] void enableFlatShading();
        /**
         * @brief turns on Smooth Shading
         * @warning must call prior to setupSimpleShader
         */
        [[maybe_unused]] void enableSmoothShading();

        /**
         * @brief Registers a simple Gouraud shader for 2-Dimensional drawing
         */
        [[maybe_unused]] void setupSimpleShader();

        /**
         * @brief registers the associated vertex locations and colors with the GPU
         * @param VERTEX_POINTS vector of vertex (x,y) locations
         * @param VERTEX_COLORS vector of vertex (r,g,b) colors
         * @returns generated Vertex Array Object Descriptor (vaod)
         */
        [[maybe_unused]] GLuint registerVertexArray(const std::vector<glm::vec2>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_COLORS);
        /**
         * @brief Updates GL_ARRAY_BUFFER for the corresponding VAO
         * @brief Copies the data for the vertex positions and colors from CPU RAM to the GPU for the already registered
         * VAO.  The data is copied in to the GL_ARRAY_BUFFER VBO for this VAO.  When function completes, the passed
         * VAO is currently bound.
         * @warning Requires that the same number of vertex points, or less, are passed as when the VAO was registered
         * @param VAOD Vertex Array Object Descriptor
         * @param VERTEX_POINTS vector of vertex (x,y) locations
         * @param VERTEX_COLORS vector of vertex (r,g,b) colors
         */
        [[maybe_unused]] void updateVertexArray(GLuint VAOD, const std::vector<glm::vec2>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_COLORS);

        /**
         * @brief registers the associated vertex locations and colors with the GPU
         * @param NUM_POINTS number of points in each array
         * @param VERTEX_POINTS array of vertex (x,y) locations
         * @param VERTEX_COLORS array of vertex (r,g,b) colors
         * @returns generated Vertex Array Object Descriptor (vaod)
         */
        [[maybe_unused]] GLuint registerVertexArray(GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]);
        /**
         * @brief Updates GL_ARRAY_BUFFER for the corresponding VAO
         * @brief Copies the data for the vertex positions and colors from CPU RAM to the GPU for the already registered
         * VAO.  The data is copied in to the GL_ARRAY_BUFFER VBO for this VAO.  When function completes, the passed
         * VAO is currently bound.
         * @warning Requires that the same number of vertex points, or less, are passed as when the VAO was registered
         * @param VAOD Vertex Array Object Descriptor
         * @param NUM_POINTS number of points in each array
         * @param VERTEX_POINTS vector of vertex (x,y) locations
         * @param VERTEX_COLORS vector of vertex (r,g,b) colors
         */
        [[maybe_unused]] void updateVertexArray(GLuint VAOD, GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]);

        /**
         * @brief Sets the Projection Matrix
         * @param PROJECTION_MATRIX homogeneous projection matrix to set
         */
        [[maybe_unused]] void setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX);

        /**
         * @brief Pushes a transformation to the stack and updates our model matrix
         * @param TRANSFORMATION_MATRIX homogeneous transformation to stack on model matrix
         */
        [[maybe_unused]] void pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX);

        /**
         * @brief Pops the last transformation off the stack and updates our model matrix
         * by the inverse of the last transformation
         */
        [[maybe_unused]] void popTransformation();

        /**
         * @brief Sets the model matrix back to the identity matrix and clears the
         * transformation stack
         */
        [[maybe_unused]] void resetTransformationMatrix();

        /**
         * @brief loads associated VAO, drawing given primitive made up of corresponding number of vertices
         * @param PRIMITIVE_TYPE primitive type to use
         * @param VAOD VAO to load
         * @param VERTEX_COUNT number of vertices to draw
         */
        [[maybe_unused]] void draw(GLint PRIMITIVE_TYPE, GLuint VAOD, GLuint VERTEX_COUNT);
    }

    /**
     * @namespace SimpleShader3
     * @brief Abstracts the process of working with a 3D shader program
     */
    namespace SimpleShader3 {
        /**
         * @brief turns on Flat Shading
         * @warning must call prior to setupSimpleShader
         */
        [[maybe_unused]] void enableFlatShading();
        /**
         * @brief turns on Smooth Shading
         * @warning must call prior to setupSimpleShader
         */
        [[maybe_unused]] void enableSmoothShading();

        /**
         * @brief Registers a simple Gouraud Shader with Lambertian Illumination for 3-Dimensional drawing
         */
        [[maybe_unused]] void setupSimpleShader();

        /**
         * @brief registers the associated vertex locations and colors with the GPU
         * @param VERTEX_POINTS vector of vertex (x,y,z) locations in object space
         * @param VERTEX_NORMALS vector of vertex (x,y,z) normals in object space
         * @return generated Vertex Array Object Descriptor (vaod)
         */
        [[maybe_unused]] GLuint registerVertexArray(const std::vector<glm::vec3>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_NORMALS);

        /**
         * @brief Updates GL_ARRAY_BUFFER for the corresponding VAO
         * @brief Copies the data for the vertex positions and colors from CPU RAM to the GPU for the already registered
         * VAO.  The data is copied in to the GL_ARRAY_BUFFER VBO for this VAO.  When function completes, the passed
         * VAO is currently bound.
         * @warning Requires that the same number of vertex points, or less, are passed as when the VAO was registered
         * @param VAOD Vertex Array Object Descriptor
         * @param VERTEX_POINTS vector of vertex (x,y,z) locations in object space
         * @param VERTEX_NORMALS vector of vertex (x,y,z) normals in object space
         */
        [[maybe_unused]] void updateVertexArray(GLuint VAOD, const std::vector<glm::vec3>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_NORMALS);

        /**
         * @brief registers the associated vertex locations and colors with the GPU
         * @param NUM_POINTS number of points in each array
         * @param VERTEX_POINTS array of vertex (x,y,z) locations in object space
         * @param VERTEX_NORMALS array of vertex (x,y,z) normals in object space
         * @return generated Vertex Array Object Descriptor (vaod)
         */
        [[maybe_unused]] GLuint registerVertexArray(GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]);
        /**
         * @brief Updates GL_ARRAY_BUFFER for the corresponding VAO
         * @brief Copies the data for the vertex positions and colors from CPU RAM to the GPU for the already registered
         * VAO.  The data is copied in to the GL_ARRAY_BUFFER VBO for this VAO.  When function completes, the passed
         * VAO is currently bound.
         * @warning Requires that the same number of vertex points, or less, are passed as when the VAO was registered
         * @param VAOD Vertex Array Object Descriptor
         * @param NUM_POINTS number of points in each array
         * @param VERTEX_POINTS array of vertex (x,y,z) locations in object space
         * @param VERTEX_NORMALS array of vertex (x,y,z) normals in object space
         */
        [[maybe_unused]] void updateVertexArray(GLuint VAOD, GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]);

        /**
         * @brief Sets the Projection Matrix
         * @param PROJECTION_MATRIX homogeneous projection matrix to set
         */
        [[maybe_unused]] void setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX);
        /**
         * @brief Sets the View Matrix
         * @param VIEW_MATRIX homogeneous view matrix to set
         */
        [[maybe_unused]] void setViewMatrix(const glm::mat4& VIEW_MATRIX);

        /**
         * @brief sets position of single global light in world space
         * @param LIGHT_POSITION position of light in world space
         */
        [[maybe_unused]] void setLightPosition(const glm::vec3& LIGHT_POSITION);
        /**
         * @brief sets color of single global light
         * @param LIGHT_COLOR light color in RGB space
         */
        [[maybe_unused]] void setLightColor(const glm::vec3& LIGHT_COLOR);
        /**
         * @brief sets current diffuse material color to apply to object
         * @param MATERIAL_COLOR diffuse material color in RGB space
         */
        [[maybe_unused]] void setMaterialColor(const glm::vec3& MATERIAL_COLOR);

        /**
         * @brief Pushes a transformation to the stack and updates our model matrix
         * @param TRANSFORMATION_MATRIX transformation to stack on model matrix
         */
        [[maybe_unused]] void pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX);

        /**
         * @brief Pops the last transformation off the stack and updates our model matrix
         * by the inverse of the last transformation
         */
        [[maybe_unused]] void popTransformation();

        /**
         * @brief Sets the model matrix back to the identity matrix and clears the
         * transformation stack
         */
        [[maybe_unused]] void resetTransformationMatrix();

        /**
         * @brief turns on lighting and applies Phong Illumination to fragment
         * @warning must call after to setupSimpleShader
         */
        [[maybe_unused]] void enableLighting();
        /**
         * @brief turns off lighting and applies material color to fragment
         * @warning must call after to setupSimpleShader
         */
        [[maybe_unused]] void disableLighting();

        /**
         * @brief loads associated VAO, drawing given primitive made up of corresponding number of vertices
         * @param PRIMITIVE_TYPE primitive type to use
         * @param VAOD VAO to load
         * @param VERTEX_COUNT number of vertices to draw
         */
        [[maybe_unused]] void draw(GLint PRIMITIVE_TYPE, GLuint VAOD, GLuint VERTEX_COUNT);
    }
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// Internal implementations

namespace CSCI441_INTERNAL {
    namespace SimpleShader2 {
        void enableFlatShading();
        void enableSmoothShading();
        void setupSimpleShader();
        GLuint registerVertexArray(GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]);
        void updateVertexArray(GLuint VAOD, GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]);
        void setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX);
        void pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX);
        void popTransformation();
        void resetTransformationMatrix();
        void draw(GLint PRIMITIVE_TYPE, GLuint VAOD, GLuint VERTEX_COUNT);

        inline GLboolean smoothShading = true;
        inline GLint shaderProgramHandle = -1;
        inline GLint modelLocation = -1;
        inline GLint viewLocation = -1;
        inline GLint projectionLocation = -1;
        inline GLint vertexLocation = -1;
        inline GLint colorLocation = -1;

        inline std::vector<glm::mat4> transformationStack;
        inline glm::mat4 modelMatrix(1.0f);
    }

    namespace SimpleShader3 {
        void enableFlatShading();
        void enableSmoothShading();
        void setupSimpleShader();
        GLuint registerVertexArray(GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]);
        void updateVertexArray(GLuint VAOD, GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]);
        void setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX);
        void setViewMatrix(const glm::mat4& VIEW_MATRIX);
        void setLightPosition(const glm::vec3& LIGHT_POSITION);
        void setLightColor(const glm::vec3& LIGHT_COLOR);
        void setMaterialColor(const glm::vec3& MATERIAL_COLOR);
        void pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX);
        void popTransformation();
        void resetTransformationMatrix();
        void setNormalMatrix();
        void enableLighting();
        void disableLighting();
        void draw(GLint PRIMITIVE_TYPE, GLuint VAOD, GLuint VERTEX_COUNT);

        inline GLboolean smoothShading = true;
        inline GLint shaderProgramHandle = -1;
        inline GLint modelLocation = -1;
        inline GLint viewLocation = -1;
        inline GLint projectionLocation = -1;
        inline GLint normalMtxLocation = -1;
        inline GLint lightPositionLocation = -1;
        inline GLint lightColorLocation = -1;
        inline GLint materialLocation = -1;
        inline GLint vertexLocation = -1;
        inline GLint normalLocation = -1;
        inline GLint useLightingLocation = -1;

        inline std::vector<glm::mat4> transformationStack;
        inline glm::mat4 modelMatrix(1.0f);
        inline glm::mat4 viewMatrix(1.0f);
    }
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// Outward facing function implementations

[[maybe_unused]]
inline void CSCI441::SimpleShader2::enableFlatShading() {
    CSCI441_INTERNAL::SimpleShader2::enableFlatShading();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::enableSmoothShading() {
    CSCI441_INTERNAL::SimpleShader2::enableSmoothShading();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::setupSimpleShader() {
    CSCI441_INTERNAL::SimpleShader2::setupSimpleShader();
}

[[maybe_unused]]
inline GLuint CSCI441::SimpleShader2::registerVertexArray(const std::vector<glm::vec2>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_COLORS) {
    return CSCI441_INTERNAL::SimpleShader2::registerVertexArray(VERTEX_POINTS.size(), &VERTEX_POINTS[0], &VERTEX_COLORS[0]);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::updateVertexArray(const GLuint VAOD, const std::vector<glm::vec2>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_COLORS) {
    CSCI441_INTERNAL::SimpleShader2::updateVertexArray(VAOD, VERTEX_POINTS.size(), &VERTEX_POINTS[0], &VERTEX_COLORS[0]);
}

[[maybe_unused]]
inline GLuint CSCI441::SimpleShader2::registerVertexArray(const GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]) {
    return CSCI441_INTERNAL::SimpleShader2::registerVertexArray(NUM_POINTS, VERTEX_POINTS, VERTEX_COLORS);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::updateVertexArray(const GLuint VAOD, const GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]) {
    CSCI441_INTERNAL::SimpleShader2::updateVertexArray(VAOD, NUM_POINTS, VERTEX_POINTS, VERTEX_COLORS);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX) {
    CSCI441_INTERNAL::SimpleShader2::setProjectionMatrix(PROJECTION_MATRIX);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX) {
    CSCI441_INTERNAL::SimpleShader2::pushTransformation(TRANSFORMATION_MATRIX);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::popTransformation() {
    CSCI441_INTERNAL::SimpleShader2::popTransformation();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::resetTransformationMatrix() {
    CSCI441_INTERNAL::SimpleShader2::resetTransformationMatrix();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader2::draw(const GLint PRIMITIVE_TYPE, const GLuint VAOD, const GLuint VERTEX_COUNT) {
    CSCI441_INTERNAL::SimpleShader2::draw(PRIMITIVE_TYPE, VAOD, VERTEX_COUNT);
}

//---------------------------------------------------------------------------------------------------------------------

[[maybe_unused]]
inline void CSCI441::SimpleShader3::enableFlatShading() {
    CSCI441_INTERNAL::SimpleShader3::enableFlatShading();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::enableSmoothShading() {
    CSCI441_INTERNAL::SimpleShader3::enableSmoothShading();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setupSimpleShader() {
    CSCI441_INTERNAL::SimpleShader3::setupSimpleShader();
}

[[maybe_unused]]
inline GLuint CSCI441::SimpleShader3::registerVertexArray(const std::vector<glm::vec3>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_NORMALS) {
    return CSCI441_INTERNAL::SimpleShader3::registerVertexArray(VERTEX_POINTS.size(), &VERTEX_POINTS[0], &VERTEX_NORMALS[0]);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::updateVertexArray(const GLuint VAOD, const std::vector<glm::vec3>& VERTEX_POINTS, const std::vector<glm::vec3>& VERTEX_NORMALS) {
    CSCI441_INTERNAL::SimpleShader3::updateVertexArray(VAOD, VERTEX_POINTS.size(), &VERTEX_POINTS[0], &VERTEX_NORMALS[0]);
}

[[maybe_unused]]
inline GLuint CSCI441::SimpleShader3::registerVertexArray(const GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]) {
    return CSCI441_INTERNAL::SimpleShader3::registerVertexArray(NUM_POINTS, VERTEX_POINTS, VERTEX_NORMALS);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::updateVertexArray(const GLuint VAOD, const GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]) {
    CSCI441_INTERNAL::SimpleShader3::updateVertexArray(VAOD, NUM_POINTS, VERTEX_POINTS, VERTEX_NORMALS);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX) {
    CSCI441_INTERNAL::SimpleShader3::setProjectionMatrix(PROJECTION_MATRIX);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setViewMatrix(const glm::mat4& VIEW_MATRIX) {
    CSCI441_INTERNAL::SimpleShader3::setViewMatrix(VIEW_MATRIX);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setLightPosition(const glm::vec3& LIGHT_POSITION) {
    CSCI441_INTERNAL::SimpleShader3::setLightPosition(LIGHT_POSITION);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setLightColor(const glm::vec3& LIGHT_COLOR) {
    CSCI441_INTERNAL::SimpleShader3::setLightColor(LIGHT_COLOR);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::setMaterialColor(const glm::vec3& MATERIAL_COLOR) {
    CSCI441_INTERNAL::SimpleShader3::setMaterialColor(MATERIAL_COLOR);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX) {
    CSCI441_INTERNAL::SimpleShader3::pushTransformation(TRANSFORMATION_MATRIX);
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::popTransformation() {
    CSCI441_INTERNAL::SimpleShader3::popTransformation();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::resetTransformationMatrix() {
    CSCI441_INTERNAL::SimpleShader3::resetTransformationMatrix();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::enableLighting() {
    CSCI441_INTERNAL::SimpleShader3::enableLighting();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::disableLighting() {
    CSCI441_INTERNAL::SimpleShader3::disableLighting();
}

[[maybe_unused]]
inline void CSCI441::SimpleShader3::draw(const GLint PRIMITIVE_TYPE, const GLuint VAOD, const GLuint VERTEX_COUNT) {
    CSCI441_INTERNAL::SimpleShader3::draw(PRIMITIVE_TYPE, VAOD, VERTEX_COUNT);
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// Inward facing function implementations

inline void CSCI441_INTERNAL::SimpleShader2::enableFlatShading() {
    smoothShading = false;
}
inline void CSCI441_INTERNAL::SimpleShader2::enableSmoothShading() {
    smoothShading = true;
}

inline void CSCI441_INTERNAL::SimpleShader2::setupSimpleShader() {
    std::string vertex_shader_src = "#version 410 core\n \
                                    \n \
                                    uniform mat4 model;\n \
                                    uniform mat4 view;\n \
                                    uniform mat4 projection;\n \
                                    \n \
                                    layout(location=0) in vec2 vPos;\n \
                                    layout(location=1) in vec3 vColor;\n \
                                    \n \
                                    layout(location=0) ";
    vertex_shader_src += (smoothShading ? "" : "flat ");
    vertex_shader_src += "out vec4 fragColor;\n \
                                    \n \
                                    void main() {\n \
                                        gl_Position = projection * view * model * vec4(vPos, 0.0, 1.0);\n \
                                        fragColor = vec4(vColor, 1.0);\n \
                                    }";
    const char* vertexShaders[1] = { vertex_shader_src.c_str() };

    std::string fragment_shader_src = "#version 410 core\n \
                                      \n \
                                      layout(location=0) ";
    fragment_shader_src += (smoothShading ? "" : "flat ");
    fragment_shader_src += " in vec4 fragColor;\n \
                                      \n \
                                      layout(location=0) out vec4 fragColorOut;\n \
                                      \n \
                                      void main() {\n \
                                          fragColorOut = fragColor;\n \
                                      }";
    const char* fragmentShaders[1] = { fragment_shader_src.c_str() };

    printf( "[INFO]: /--------------------------------------------------------\\\n" );

    GLuint vertexShaderHandle = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource(vertexShaderHandle, 1, vertexShaders, nullptr);
    glCompileShader(vertexShaderHandle);
    ShaderUtils::printShaderLog(vertexShaderHandle);

    GLuint fragmentShaderHandle = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource(fragmentShaderHandle, 1, fragmentShaders, nullptr);
    glCompileShader(fragmentShaderHandle);
    ShaderUtils::printShaderLog(fragmentShaderHandle);

    shaderProgramHandle = glCreateProgram();
    glAttachShader(shaderProgramHandle, vertexShaderHandle);
    glAttachShader(shaderProgramHandle, fragmentShaderHandle);
    glLinkProgram(shaderProgramHandle);
    ShaderUtils::printProgramLog(shaderProgramHandle);

    glDetachShader(shaderProgramHandle, vertexShaderHandle);
    glDeleteShader(vertexShaderHandle);

    glDetachShader(shaderProgramHandle, fragmentShaderHandle);
    glDeleteShader(fragmentShaderHandle);

    ShaderUtils::printShaderProgramInfo(shaderProgramHandle, true, false, false, false, true, false, true);

    modelLocation       = glGetUniformLocation(shaderProgramHandle, "model");
    viewLocation        = glGetUniformLocation(shaderProgramHandle, "view");
    projectionLocation  = glGetUniformLocation(shaderProgramHandle, "projection");

    vertexLocation      = glGetAttribLocation(shaderProgramHandle, "vPos");
    colorLocation       = glGetAttribLocation(shaderProgramHandle, "vColor");

    glUseProgram(shaderProgramHandle);

    glm::mat4 identity(1.0f);
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &identity[0][0]);
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &identity[0][0]);
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &identity[0][0]);

    transformationStack.emplace_back(identity);
}

inline GLuint CSCI441_INTERNAL::SimpleShader2::registerVertexArray(const GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]) {
    GLuint vaod;
    glGenVertexArrays(1, &vaod);
    glBindVertexArray(vaod);

    GLuint vbod;
    glGenBuffers(1, &vbod);
    glBindBuffer(GL_ARRAY_BUFFER, vbod);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*2 + sizeof(GLfloat)*NUM_POINTS*3, nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*NUM_POINTS*2, VERTEX_POINTS);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*2, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_COLORS);

    glEnableVertexAttribArray(vertexLocation);
    glVertexAttribPointer(vertexLocation, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(colorLocation);
    glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*NUM_POINTS*2));

    return vaod;
}

inline void CSCI441_INTERNAL::SimpleShader2::updateVertexArray(const GLuint VAOD, const GLuint NUM_POINTS, const glm::vec2 VERTEX_POINTS[], const glm::vec3 VERTEX_COLORS[]) {
    glBindVertexArray(VAOD);
    glBindBuffer(GL_ARRAY_BUFFER, VAOD);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*NUM_POINTS*2, VERTEX_POINTS);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*2, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_COLORS);
}

inline void CSCI441_INTERNAL::SimpleShader2::setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX) {
    glUseProgram(shaderProgramHandle);
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &PROJECTION_MATRIX[0][0]);
}

inline void CSCI441_INTERNAL::SimpleShader2::pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX) {
    glUseProgram(shaderProgramHandle);
    transformationStack.emplace_back(TRANSFORMATION_MATRIX);

    modelMatrix *= TRANSFORMATION_MATRIX;
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &modelMatrix[0][0]);
}

inline void CSCI441_INTERNAL::SimpleShader2::popTransformation() {
    // ensure there is a transformation stack to pop off
    // never let the original identity matrix pop off
    if( transformationStack.size() > 1 ) {
        glUseProgram(shaderProgramHandle);
        glm::mat4 lastTransformation = transformationStack.back();
        transformationStack.pop_back();

        modelMatrix = glm::mat4(1.0f);
        for( auto tMtx : transformationStack ) {
            modelMatrix *= tMtx;
        }
        glUniformMatrix4fv( modelLocation, 1, GL_FALSE, &modelMatrix[0][0] );
    }
}

inline void CSCI441_INTERNAL::SimpleShader2::resetTransformationMatrix() {
    modelMatrix = glm::mat4(1.0f);
    transformationStack.clear();
    transformationStack.emplace_back(modelMatrix);
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &modelMatrix[0][0]);
}

inline void CSCI441_INTERNAL::SimpleShader2::draw(const GLint PRIMITIVE_TYPE, const GLuint VAOD, const GLuint VERTEX_COUNT) {
    glUseProgram(shaderProgramHandle);
    glBindVertexArray(VAOD);
    glDrawArrays(PRIMITIVE_TYPE, 0, VERTEX_COUNT);
}

//---------------------------------------------------------------------------------------------------------------------

inline void CSCI441_INTERNAL::SimpleShader3::enableFlatShading() {
    smoothShading = false;
}
inline void CSCI441_INTERNAL::SimpleShader3::enableSmoothShading() {
    smoothShading = true;
}

inline void CSCI441_INTERNAL::SimpleShader3::setupSimpleShader() {
    std::string vertex_shader_src = "#version 410 core\n \
                                    \n \
                                    uniform mat4 model;\n \
                                    uniform mat4 view;\n \
                                    uniform mat4 projection;\n \
                                    uniform mat3 normalMtx;\n \
                                    uniform vec3 lightColor;\n \
                                    uniform vec3 lightPosition;\n \
                                    uniform vec3 materialColor;\n \
                                    \n \
                                    layout(location=0) in vec3 vPos;\n \
                                    layout(location=2) in vec3 vNormal;\n \
                                    \n \
                                    layout(location=0) ";
    vertex_shader_src += (smoothShading ? "" : "flat ");
    vertex_shader_src += "out vec4 fragColor;\n \
                                    \n \
                                    void main() {\n \
                                        gl_Position = projection * view * model * vec4(vPos, 1.0);\n \
                                        \n \
                                        vec3 vertexEye = (view * model * vec4(vPos, 1.0)).xyz;\n \
                                        vec3 lightEye = (view * vec4(lightPosition, 1.0)).xyz;\n \
                                        vec3 lightVec = normalize( lightEye - vertexEye );\n \
                                        vec3 normalVec = normalize( normalMtx * vNormal );\n \
                                        float sDotN = max(dot(lightVec, normalVec), 0.0);\n \
                                        vec3 diffColor = lightColor * materialColor * sDotN;\n \
                                        vec3 ambColor = materialColor * 0.3;\
                                        vec3 color = diffColor + ambColor;\n \
                                        fragColor = vec4(color, 1.0);\n \
                                    }";
    const char* vertexShaders[1] = { vertex_shader_src.c_str() };

    std::string fragment_shader_src = "#version 410 core\n \
                                      \n \
                                      uniform vec3 materialColor;\n \
                                      uniform int useLighting;\n \
                                      \n \
                                      layout(location=0) ";
    fragment_shader_src += (smoothShading ? "" : "flat ");
    fragment_shader_src += " in vec4 fragColor;\n \
                                      \n \
                                      layout(location=0) out vec4 fragColorOut;\n \
                                      \n \
                                      void main() {\n \
                                          if(useLighting == 1) {\n \
                                              fragColorOut = fragColor;\n \
                                          } else {\n \
                                              fragColorOut = vec4(materialColor, 1.0f);\n \
                                          }\n \
                                      }";
    const char* fragmentShaders[1] = { fragment_shader_src.c_str() };

    printf( "[INFO]: /--------------------------------------------------------\\\n" );

    GLuint vertexShaderHandle = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource(vertexShaderHandle, 1, vertexShaders, nullptr);
    glCompileShader(vertexShaderHandle);
    ShaderUtils::printShaderLog(vertexShaderHandle);

    GLuint fragmentShaderHandle = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource(fragmentShaderHandle, 1, fragmentShaders, nullptr);
    glCompileShader(fragmentShaderHandle);
    ShaderUtils::printShaderLog(fragmentShaderHandle);

    shaderProgramHandle = glCreateProgram();
    glAttachShader(shaderProgramHandle, vertexShaderHandle);
    glAttachShader(shaderProgramHandle, fragmentShaderHandle);
    glLinkProgram(shaderProgramHandle);
    ShaderUtils::printProgramLog(shaderProgramHandle);

    glDetachShader(shaderProgramHandle, vertexShaderHandle);
    glDeleteShader(vertexShaderHandle);

    glDetachShader(shaderProgramHandle, fragmentShaderHandle);
    glDeleteShader(fragmentShaderHandle);

    ShaderUtils::printShaderProgramInfo(shaderProgramHandle, true, false, false, false, true, false, true);

    modelLocation       = glGetUniformLocation(shaderProgramHandle, "model");
    viewLocation        = glGetUniformLocation(shaderProgramHandle, "view");
    projectionLocation  = glGetUniformLocation(shaderProgramHandle, "projection");
    normalMtxLocation   = glGetUniformLocation(shaderProgramHandle, "normalMtx");
    lightPositionLocation=glGetUniformLocation(shaderProgramHandle, "lightPosition");
    lightColorLocation  = glGetUniformLocation(shaderProgramHandle, "lightColor");
    materialLocation    = glGetUniformLocation(shaderProgramHandle, "materialColor");
    useLightingLocation = glGetUniformLocation(shaderProgramHandle, "useLighting");

    vertexLocation      = glGetAttribLocation(shaderProgramHandle, "vPos");
    normalLocation      = glGetAttribLocation(shaderProgramHandle, "vNormal");

    glUseProgram(shaderProgramHandle);

    glm::mat4 identity(1.0f);
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &identity[0][0]);
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &identity[0][0]);
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &identity[0][0]);

    transformationStack.emplace_back(identity);

    glm::vec3 white(1.0f, 1.0f, 1.0f);
    glUniform3fv(lightColorLocation, 1, &white[0]);
    glUniform3fv(materialLocation, 1, &white[0]);

    glm::vec3 origin(0.0f, 0.0f, 0.0f);
    glUniform3fv(lightPositionLocation, 1, &origin[0]);

    glUniform1i(useLightingLocation, 1);

    CSCI441::setVertexAttributeLocations(vertexLocation, normalLocation);
}

inline GLuint CSCI441_INTERNAL::SimpleShader3::registerVertexArray(const GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]) {
    GLuint vaod;
    glGenVertexArrays(1, &vaod);
    glBindVertexArray(vaod);

    GLuint vbod;
    glGenBuffers(1, &vbod);
    glBindBuffer(GL_ARRAY_BUFFER, vbod);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*3 + sizeof(GLfloat)*NUM_POINTS*3, nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_POINTS);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*3, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_NORMALS);

    glEnableVertexAttribArray(vertexLocation);
    glVertexAttribPointer(vertexLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(normalLocation);
    glVertexAttribPointer(normalLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*NUM_POINTS*2));

    return vaod;
}

inline void CSCI441_INTERNAL::SimpleShader3::updateVertexArray(const GLuint VAOD, const GLuint NUM_POINTS, const glm::vec3 VERTEX_POINTS[], const glm::vec3 VERTEX_NORMALS[]) {
    glBindVertexArray(VAOD);
    glBindBuffer(GL_ARRAY_BUFFER, VAOD);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_POINTS);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*NUM_POINTS*3, sizeof(GLfloat)*NUM_POINTS*3, VERTEX_NORMALS);
}

inline void CSCI441_INTERNAL::SimpleShader3::setProjectionMatrix(const glm::mat4& PROJECTION_MATRIX) {
    glUseProgram(shaderProgramHandle);
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &PROJECTION_MATRIX[0][0]);
}

inline void CSCI441_INTERNAL::SimpleShader3::setViewMatrix(const glm::mat4& VIEW_MATRIX) {
    glUseProgram(shaderProgramHandle);
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &VIEW_MATRIX[0][0]);

    viewMatrix = VIEW_MATRIX;
    setNormalMatrix();
}

inline void CSCI441_INTERNAL::SimpleShader3::setLightPosition(const glm::vec3& LIGHT_POSITION) {
    glUseProgram(shaderProgramHandle);
    glUniform3fv(lightPositionLocation, 1, &LIGHT_POSITION[0]);
}

inline void CSCI441_INTERNAL::SimpleShader3::setLightColor(const glm::vec3& LIGHT_COLOR) {
    glUseProgram(shaderProgramHandle);
    glUniform3fv(lightColorLocation, 1, &LIGHT_COLOR[0]);
}

inline void CSCI441_INTERNAL::SimpleShader3::setMaterialColor(const glm::vec3& MATERIAL_COLOR) {
    glUseProgram(shaderProgramHandle);
    glUniform3fv(materialLocation, 1, &MATERIAL_COLOR[0]);
}

inline void CSCI441_INTERNAL::SimpleShader3::pushTransformation(const glm::mat4& TRANSFORMATION_MATRIX) {
    glUseProgram(shaderProgramHandle);
    transformationStack.emplace_back(TRANSFORMATION_MATRIX);

    modelMatrix *= TRANSFORMATION_MATRIX;
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &modelMatrix[0][0]);

    setNormalMatrix();
}

inline void CSCI441_INTERNAL::SimpleShader3::popTransformation() {
    // ensure there is a transformation stack to pop off
    // never let the original identity matrix pop off
    if( transformationStack.size() > 1 ) {
        glUseProgram(shaderProgramHandle);
        glm::mat4 lastTransformation = transformationStack.back();
        transformationStack.pop_back();

        modelMatrix = glm::mat4(1.0f);
        for( auto tMtx : transformationStack ) {
            modelMatrix *= tMtx;
        }
        glUniformMatrix4fv( modelLocation, 1, GL_FALSE, &modelMatrix[0][0] );
    }
}

inline void CSCI441_INTERNAL::SimpleShader3::resetTransformationMatrix() {
    modelMatrix = glm::mat4(1.0f);
    transformationStack.clear();
    transformationStack.emplace_back(modelMatrix);
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    setNormalMatrix();
}

inline void CSCI441_INTERNAL::SimpleShader3::setNormalMatrix() {
    glUseProgram(shaderProgramHandle);
    glm::mat4 modelView = viewMatrix * modelMatrix;
    glm::mat3 normalMatrix = glm::mat3( glm::transpose( glm::inverse( modelView ) ) );
    glUniformMatrix3fv(normalMtxLocation, 1, GL_FALSE, &normalMatrix[0][0]);
}

inline void CSCI441_INTERNAL::SimpleShader3::enableLighting() {
    glUseProgram(shaderProgramHandle);
    glUniform1i(useLightingLocation, 1);
}

inline void CSCI441_INTERNAL::SimpleShader3::disableLighting() {
    glUseProgram(shaderProgramHandle);
    glUniform1i(useLightingLocation, 0);
}

inline void CSCI441_INTERNAL::SimpleShader3::draw(const GLint PRIMITIVE_TYPE, const GLuint VAOD, const GLuint VERTEX_COUNT) {
    glUseProgram(shaderProgramHandle);
    glBindVertexArray(VAOD);
    glDrawArrays(PRIMITIVE_TYPE, 0, VERTEX_COUNT);
}

#endif //__CSCI441_SIMPLE_SHADER_HPP__
