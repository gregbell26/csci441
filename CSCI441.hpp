/**
 * @file CSCI441.hpp
 * @brief Includes all CSCI 441 class helper files
 * @author Dr. Jeffrey Paone
 *
 * @copyright MIT License Copyright (c) 2017 Dr. Jeffrey Paone
 *
 * These functions, classes, and constants help minimize common
 * code that needs to be written.
 *
 * @warning This header file depends upon GLAD (or alternatively GLEW)
 * @warning This header file depends upon GLFW
 * @warning This header file depends upon glm
 * @warning This header file depends upon stb_image
 *
 */

/*! \mainpage
 *
 * \section download_sec Download
 *
 * Download the latest version from the \htmlonly <a rel="noreferrer" href="https://github.com/jpaoneMines/csci441" target="_blank">CSCI441 GitHub Repo</a> \endhtmlonly
 *
 * \section revision_sec Documentation
 *
 * View the \htmlonly <a href="md__r_e_a_d_m_e.html">README</a> \endhtmlonly
 *
 * View the \htmlonly <a href="md__c_h_a_n_g_e_l_o_g.html">Revision History</a> \endhtmlonly
 */

#ifndef CSCI441_CSCI441_HPP
#define CSCI441_CSCI441_HPP

#include "ArcballCam.hpp"           // arcball cam implementation
#include "Camera.hpp"               // abstract Camera class
#include "ComputeShaderProgram.hpp" // helper class to compile and use compute shaders
#include "FixedCam.hpp"             // static fixed camera implementation
#include "FramebufferUtils.hpp"     // to query common FBO information
#include "FreeCam.hpp"              // free cam implementation
#include "HUDCamera.hpp"            // heads up display implementation
#include "materials.hpp"            // predefined material properties
#include "MD5Camera.hpp"            // MD5 camera implementation
#include "MD5Model.hpp"             // MD5 mesh and anim implementation
#include "ModelLoader.hpp"          // to load OBJ, OFF, PLY, STL files
#include "objects.hpp"              // include 3D objects (cube, cylinder, cone, torus, sphere, disk, teapot)
#include "OpenGL3DEngine.hpp"       // to create a concrete 3D Rendering engine
#include "OpenGLEngine.hpp"         // to create a concrete Rendering engine
#include "OpenGLUtils.hpp"          // to query OpenGL features
#include "OrthographicCamera.hpp"   // to create a camera with an orthographic projection
#include "PerspectiveCamera.hpp"    // to create a camera with a perspective projection
#include "ShaderProgram.hpp"        // helper class to compile and use shaders
#include "ShaderProgramPipeline.hpp"// helper class to compile and use shader program pipelines
#include "ShaderUtils.hpp"          // helper functions to work with shader programs
#include "SimpleShader.hpp"         // default shader programs for 2D and 3D applications
#include "TextureUtils.hpp"         // helper functions for registering textures
#include "UniformBufferObject.hpp"  // helper class to use UBOs

#endif // CSCI441_CSCI441_HPP
