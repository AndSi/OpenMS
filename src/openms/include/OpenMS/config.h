// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// ==========================================================================
//
// IMPORTANT:
// This is config.h / config.h.in
// Please do ONLY change config.h.in, as config.h is automagically
// created by CMAKE from config.h.in
//
// Use appropriate options to configure instead of changing config.h.
// Changes made in config.h will be lost as soon as you call CMAKE again.
//
// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2012.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Chris Bielow $
// $Authors: $
// --------------------------------------------------------------------------

#ifndef OPENMS_CONFIG_H
#define OPENMS_CONFIG_H

// Here are some global configuration flags for OpenMS

// The path to the directory where OpenMS data is installed
#define OPENMS_DATA_PATH "/home/walzer/OpenMS/share/OpenMS"

// The path to the directory where OpenMS doc is installed
#define OPENMS_DOC_PATH "/home/walzer/OpenMS/doc"

// The directory where OpenMS is build
#define OPENMS_SOURCE_PATH "/home/walzer/OpenMS/src/openms"

// The directory where the OpenMS sources are located
#define OPENMS_BINARY_PATH "/home/walzer/OpenMS/src/openms"

// Define compiler specifics (used in VERY few places only)
// Microsoft Visual Studio .NET, 2005, 2008
/* #undef OPENMS_COMPILER_MSVC */
// GNU g++
#define OPENMS_COMPILER_GXX

// __PRETTY_FUNCTION__ is a GNU G++ extension.  It is used in exceptions to indicate their origin.
#ifndef OPENMS_COMPILER_GXX
#define __PRETTY_FUNCTION__ "<unknown>"
#endif


// OPENMS_ASSERTIONS enables some debugging methods within some OpenMS classes
#ifdef OPENMS_COMPILER_MSVC
// we define this using NDEBUG on MSVC as there are multiple build types simultaneously in the Solution file,
// thus setting one value will not fit them all
#	ifndef NDEBUG // hopefully defined automatically by MS-compiler in Debug Mode
#		define OPENMS_ASSERTIONS
#	endif
#else // linux & Co (only one build type at a time)
#  if (0)
#    define OPENMS_ASSERTIONS
#  endif
#endif


// let Cmake decide if we are using Windows (i.e. if windows.h is available).
//   GCC and MSVC have pre-defined macros for this as well but using -ansi in GCC will disable those, thus asking the compiler is fragile
#ifndef WIN32  //avoid warning of redefinition
/* #undef WIN32 */
#endif

#ifdef WIN32   //should be true on: MinGW (32bit + 64bit) & MSVS compiler
#define OPENMS_WINDOWSPLATFORM 1
#endif

// are we building a shared lib?
#define BUILD_SHARED_LIBS

#ifdef OPENMS_WINDOWSPLATFORM
# ifdef BUILD_SHARED_LIBS
#  if defined OpenMS_EXPORTS  //automatically defined by CMake when building OpenMS dll
#    define OPENMS_DLLAPI  __declspec( dllexport )
#  else
#    define OPENMS_DLLAPI  __declspec( dllimport )
#  endif
#  if defined OpenMS_GUI_EXPORTS  //automatically defined by CMake when building OpenMS-GUI dll
#    define OPENMS_GUI_DLLAPI  __declspec( dllexport )
#  else
#    define OPENMS_GUI_DLLAPI  __declspec( dllimport )
#  endif
# endif
#endif
#ifndef OPENMS_DLLAPI //leave empty when not building DLL
# define OPENMS_DLLAPI
#endif
#ifndef OPENMS_GUI_DLLAPI //leave empty when not building DLL
# define OPENMS_GUI_DLLAPI
#endif


/* #undef OPENMS_BIG_ENDIAN */

// Define on 64 bit architectures
#define OPENMS_64BIT_ARCHITECTURE

#define OPENMS_INT32_TYPE int32_t
#define OPENMS_INT64_TYPE int64_t
#define OPENMS_BYTE_TYPE uint8_t
#define OPENMS_UINT64_TYPE uint64_t
//#define OPENMS_SIZE_T_SIGNED 


// if you ever want to do abs() or floor() on this type in VC then use _abs64() and include <stdlib.h> (no kidding!)
#define PointerSizeInt int64_t
#define PointerSizeUInt uint64_t

#define OPENMS_HAS_UNISTD_H
/* #undef OPENMS_HAS_PROCESS_H */
#define OPENMS_HAS_STDINT_H

#define OPENMS_HAS_TIME_H
#define OPENMS_HAS_SYS_TYPES_H
#define OPENMS_HAS_SYS_TIMES_H
#define OPENMS_HAS_SYS_TIME_H

#define OPENMS_HAS_KILL
#define OPENMS_HAS_SYSCONF

// is libc++ or has stream bug
/* #undef OPENMS_HAS_STREAM_EXTRACTION_BUG */

// library versions
#define OPENMS_LIBSVM_VERSION 3.1.2
#define OPENMS_LIBSVM_VERSION_MAJOR 3
#define OPENMS_LIBSVM_VERSION_MINOR 1

#define OPENMS_BOOST_VERSION_MAJOR 1
#define OPENMS_BOOST_VERSION_MINOR 52
#define OPENMS_BOOST_VERSION_SUBMINOR 0
#define OPENMS_BOOST_VERSION 105200

#define COINOR_SOLVER 0

#define OPENMS_GLPK_VERSION 4.46
#define OPENMS_GLPK_VERSION_MAJOR 4
#define OPENMS_GLPK_VERSION_MINOR 46

// class & TOPP tests
#define DB_PLUGIN "QMYSQL"

#ifdef _OPENMP
  #define IF_MASTERTHREAD if (omp_get_thread_num() ==0)
#else
  #define IF_MASTERTHREAD
#endif

/* #undef WITH_CRAWDAD */

#endif // OPENMS_CONFIG_H
