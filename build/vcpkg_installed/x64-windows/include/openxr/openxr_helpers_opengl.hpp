// *********** THIS FILE IS GENERATED - DO NOT EDIT ***********
//     See cpp_generator.py for modifications
// ************************************************************
































/*
** Copyright (c) 2017-2023 The Khronos Group Inc.
** Copyright (c) 2019-2023 Collabora, Ltd.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** ---- Exceptions to the Apache 2.0 License: ----
**
** As an exception, if you use this Software to generate code and portions of
** this Software are embedded into the generated code as a result, you may
** redistribute such product without providing attribution as would otherwise
** be required by Sections 4(a), 4(b) and 4(d) of the License.
**
** In addition, if you combine or link code generated by this Software with
** software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
** ("`Combined Software`") and if a court of competent jurisdiction determines
** that the patent provision (Section 3), the indemnity provision (Section 9)
** or other Section of the License conflicts with the conditions of the
** applicable GPL or LGPL license, you may retroactively and prospectively
** choose to deem waived or otherwise exclude such Section(s) of the License,
** but only in their entirety and only with respect to the Combined Software.
**
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/
#ifndef OPENXR_HELPERS_OPENGL_HPP_
#define OPENXR_HELPERS_OPENGL_HPP_
/**
 * @file
 * @brief Contains a helper function specific to OpenGL/OpenGL ES.
 *
 * @see xr::getOpenGLVersion, xr::Version
 * @ingroup utilities
 */

#include "openxr_version.hpp"
































#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif  // !OPENXR_HPP_NAMESPACE
namespace OPENXR_HPP_NAMESPACE {

#if (defined(GL_MAJOR_VERSION) && defined(GL_MINOR_VERSION)) || defined(OPENXR_HPP_DOXYGEN)
/**
 * @brief Get the OpenGL major and minor version as a packed Version type.
 *
 * @return Version
 * @ingroup utilities
 */
OPENXR_HPP_INLINE Version getOpenGLVersion() noexcept {
    GLint major = 0;
    GLint minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    return Version{static_cast<uint16_t>(major), static_cast<uint16_t>(minor), 0};
}
#endif  // (defined(GL_MAJOR_VERSION) && defined(GL_MINOR_VERSION)) || defined(OPENXR_HPP_DOXYGEN)

}  // namespace OPENXR_HPP_NAMESPACE
































#endif  // ifndef OPENXR_HELPERS_OPENGL_HPP_

