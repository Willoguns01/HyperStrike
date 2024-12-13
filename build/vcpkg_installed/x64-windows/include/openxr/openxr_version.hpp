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
#ifndef OPENXR_VERSION_HPP_
#define OPENXR_VERSION_HPP_
/**
 * @file
 * @brief Contains a type-safe C++ projection of the OpenXR packed version type.
 * @ingroup wrappers
 */

#include <openxr/openxr.h>

#ifdef OPENXR_HPP_DOXYGEN
#include <openxr/openxr_platform.h>
#endif

#include <string>































#if !defined(OPENXR_HPP_INLINE)
#if defined(__clang___)
#if __has_attribute(always_inline)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#else
#define OPENXR_HPP_INLINE inline
#endif
#elif defined(__GNUC__)
#define OPENXR_HPP_INLINE __attribute__((always_inline)) __inline__
#elif defined(_MSC_VER)
#define OPENXR_HPP_INLINE inline
#else
#define OPENXR_HPP_INLINE inline
#endif
#endif  // !OPENXR_HPP_INLINE

#if !defined(OPENXR_HPP_CONSTEXPR)
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define OPENXR_HPP_CONSTEXPR
#else
#define OPENXR_HPP_CONSTEXPR constexpr
#endif
#endif  // !OPENXR_HPP_CONSTEXPR

#if !defined(OPENXR_HPP_SWITCH_CONSTEXPR)
//! @todo set this to constexpr in c++14
#define OPENXR_HPP_SWITCH_CONSTEXPR
#endif  // !OPENXR_HPP_SWITCH_CONSTEXPR































#if !defined(OPENXR_HPP_NAMESPACE)
#define OPENXR_HPP_NAMESPACE xr
#endif  // !OPENXR_HPP_NAMESPACE
namespace OPENXR_HPP_NAMESPACE {
/*!
 * @brief XrVersion wrapper class
 * 
 * @see <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XrVersion>
 * 
 * @xrentity{XrVersion}
 * @ingroup wrappers
 */
class Version  {
   public:

    /*!
     * @name Constructors, assignment, and conversions
     * @{
     */
    //! Default constructor.
    OPENXR_HPP_CONSTEXPR Version () noexcept = default;

    //! Explicit constructor from raw XrVersion value
    OPENXR_HPP_CONSTEXPR explicit Version (XrVersion v) noexcept : val_(v) {}

//! Constructor from version components
Version(uint16_t major_, uint16_t minor_, uint32_t patch_) noexcept {
    major(major_);
    minor(minor_);
    patch(patch_);
}

    //! @}
/*!
 * @name Raw XrVersion manipulation
 * @{
 */
    //! Gets the raw XrVersion value.
    OPENXR_HPP_CONSTEXPR XrVersion get() const noexcept {
        return val_;
    }
/*!
 * @brief Clears this value, then returns the address of the raw XrVersion value,
 * for use in creation/assignment.
 */
    XrVersion *put(bool clear = true) noexcept {
        if (clear) val_ = {};
        return &val_;
    }
    //! @}

/*!
 * @brief Get the major component.
 * 
 * @see <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_VERSION_MAJOR>
 * 
 * @xrentity{XR_VERSION_MAJOR}
 */
OPENXR_HPP_CONSTEXPR uint16_t major() const noexcept
{
    return static_cast<uint16_t>(val_ >> 48);
}

//! Set the major component: 16 bits.
void major(uint16_t val) noexcept
{
    // blank the top 16 bits
    val_ &= 0x0000ffffffffffff;
    val_ |= uint64_t(val) << 48;
}


/*!
 * @brief Get the minor component.
 * 
 * @see <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_VERSION_MINOR>
 * 
 * @xrentity{XR_VERSION_MINOR}
 */
OPENXR_HPP_CONSTEXPR uint16_t minor() const noexcept
{
    return static_cast<uint16_t>((val_ >> 32) & 0xffff);
}
//! Set the minor component: 16 bits.
void minor(uint16_t val) noexcept
{
    // blank the correct 16 bits
    val_ &= 0xffff0000ffffffff;
    val_ |= uint64_t(val) << 32;
}

/*!
 * @brief Get the patch component.
 * 
 * @see <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_VERSION_PATCH>
 * 
 * @xrentity{XR_VERSION_PATCH}
 */
OPENXR_HPP_CONSTEXPR uint32_t patch() const noexcept
{
    return static_cast<uint32_t>(val_ & 0xffffffff);
}
//! Set the patch component: 32 bits.
void patch(uint32_t val) noexcept
{
    // blank the least-significant 32 bits
    val_ &= 0xffffffff00000000;
    val_ |= val;
}


/*!
 * @brief Get the current version of OpenXR, based on the header.
 * 
 * @see <https://www.khronos.org/registry/OpenXR/specs/1.0/html/xrspec.html#XR_CURRENT_API_VERSION>
 * 
 * @xrentity{XR_CURRENT_API_VERSION}
 */
static OPENXR_HPP_CONSTEXPR Version current() noexcept
{
    return Version{XR_CURRENT_API_VERSION};
}
   private:
    XrVersion val_{};
};

 static_assert(sizeof(XrVersion) == sizeof(Version), "Original type and wrapper have different size!"); 

/*!
 * @brief Free function for getting the raw XrVersion from an Version value.
 * 
 * @found_by_adl
 * @see Version::get()
 * @relates Version
 * @ingroup utility_accessors
 */
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE XrVersion get(Version v) noexcept { return v.get(); }
/*!
 * @brief Free function for clearing (by default) and getting the address of the raw XrVersion from an Version value.
 * 
 * @found_by_adl
 * @see Version::put( )
 * @relates Version
 * @ingroup utility_accessors
 */
static OPENXR_HPP_INLINE XrVersion *put(Version &v, bool clear = true) noexcept { return v.put(clear); }
//! @brief `<` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Version lhs, Version rhs) noexcept {
    return lhs.get()<rhs.get();
}
//! @brief `>` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Version lhs, Version rhs) noexcept {
    return lhs.get()>rhs.get();
}
//! @brief `<=` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Version lhs, Version rhs) noexcept {
    return lhs.get()<=rhs.get();
}
//! @brief `>=` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Version lhs, Version rhs) noexcept {
    return lhs.get()>=rhs.get();
}
//! @brief `==` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Version lhs, Version rhs) noexcept {
    return lhs.get()==rhs.get();
}
//! @brief `!=` comparison between Version values.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Version lhs, Version rhs) noexcept {
    return lhs.get()!=rhs.get();
}
//! @brief `<` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()<rhs;
}
//! @brief `<` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<(XrVersion lhs, Version rhs) noexcept {
    return lhs<rhs.get();
}
//! @brief `>` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()>rhs;
}
//! @brief `>` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>(XrVersion lhs, Version rhs) noexcept {
    return lhs>rhs.get();
}
//! @brief `<=` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()<=rhs;
}
//! @brief `<=` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator<=(XrVersion lhs, Version rhs) noexcept {
    return lhs<=rhs.get();
}
//! @brief `>=` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()>=rhs;
}
//! @brief `>=` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator>=(XrVersion lhs, Version rhs) noexcept {
    return lhs>=rhs.get();
}
//! @brief `==` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()==rhs;
}
//! @brief `==` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator==(XrVersion lhs, Version rhs) noexcept {
    return lhs==rhs.get();
}
//! @brief `!=` comparison between Version and raw XrVersion.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(Version lhs, XrVersion rhs) noexcept {
    return lhs.get()!=rhs;
}
//! @brief `!=` comparison between raw XrVersion and Version.
//! @relates Version
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator!=(XrVersion lhs, Version rhs) noexcept {
    return lhs!=rhs.get();
}
/*!
 * @brief Format a version as a string.
 * @found_by_adl
 * @ingroup utility_accessors
 */
static inline std::string to_string(Version const& v)
{
    auto ret = std::to_string(v.major());
    ret += ".";
    ret += std::to_string(v.minor());
    ret += ".";
    ret += std::to_string(v.patch());
    return ret;
}
} // OPENXR_HPP_NAMESPACE
































#endif  // ifndef OPENXR_VERSION_HPP_

