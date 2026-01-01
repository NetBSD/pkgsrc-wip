$NetBSD$

cmake file copied from OpenVDB 8.1.0 distribution, with unknown cmake
function OPENVDB_GET_VERSION_DEFINE commented out.

Fixed boost 1.89 compatibility, which removed boost_system component.

--- cmake/modules/FindOpenVDB.cmake.orig	2025-11-06 09:19:38.000000000 +0000
+++ cmake/modules/FindOpenVDB.cmake
@@ -1,28 +1,5 @@
-# Copyright (c) DreamWorks Animation LLC
-#
-# All rights reserved. This software is distributed under the
-# Mozilla Public License 2.0 ( http://www.mozilla.org/MPL/2.0/ )
-#
-# Redistributions of source code must retain the above copyright
-# and license notice and the following restrictions and disclaimer.
-#
-# *     Neither the name of DreamWorks Animation nor the names of
-# its contributors may be used to endorse or promote products derived
-# from this software without specific prior written permission.
-#
-# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
-# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
-# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
-# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
-# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY INDIRECT, INCIDENTAL,
-# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
-# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
-# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
-# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
-# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
-# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-# IN NO EVENT SHALL THE COPYRIGHT HOLDERS' AND CONTRIBUTORS' AGGREGATE
-# LIABILITY FOR ALL CLAIMS REGARDLESS OF THEIR BASIS EXCEED US$250.00.
+# Copyright Contributors to the OpenVDB Project
+# SPDX-License-Identifier: MPL-2.0
 #
 #[=======================================================================[.rst:
 
@@ -37,7 +14,10 @@ Use this module by invoking find_package
     [version] [EXACT]      # Minimum or EXACT version
     [REQUIRED]             # Fail with error if OpenVDB is not found
     [COMPONENTS <libs>...] # OpenVDB libraries by their canonical name
-                           # e.g. "openvdb" for "libopenvdb"
+                           # e.g. "openvdb" for "libopenvdb",
+                           # "pyopenvdb" for the python plugin
+                           # "openvdb_ax" for the OpenVDB AX extension
+                           # "openvdb_houdini" for the houdini plugin
     )
 
 IMPORTED Targets
@@ -45,6 +25,14 @@ IMPORTED Targets
 
 ``OpenVDB::openvdb``
   The core openvdb library target.
+``OpenVDB::openvdb_je``
+  The core openvdb library target with jemalloc.
+``OpenVDB::pyopenvdb``
+  The openvdb python library target.
+``OpenVDB::openvdb_houdini``
+  The openvdb houdini library target.
+``OpenVDB::openvdb_ax``
+  The openvdb_ax library target.
 
 Result Variables
 ^^^^^^^^^^^^^^^^
@@ -63,14 +51,16 @@ This will define the following variables
   OpenVDB library directories.
 ``OpenVDB_DEFINITIONS``
   Definitions to use when compiling code that uses OpenVDB.
-``OpenVDB_{COMPONENT}_FOUND``
+``OpenVDB_${COMPONENT}_FOUND``
   True if the system has the named OpenVDB component.
 ``OpenVDB_USES_BLOSC``
   True if the OpenVDB Library has been built with blosc support
+``OpenVDB_USES_ZLIB``
+  True if the OpenVDB Library has been built with zlib support
 ``OpenVDB_USES_LOG4CPLUS``
   True if the OpenVDB Library has been built with log4cplus support
-``OpenVDB_USES_EXR``
-  True if the OpenVDB Library has been built with openexr support
+``OpenVDB_USES_IMATH_HALF``
+  True if the OpenVDB Library has been built with Imath half support
 ``OpenVDB_ABI``
   Set if this module was able to determine the ABI number the located
   OpenVDB Library was built against. Unset otherwise.
@@ -82,7 +72,9 @@ The following cache variables may also b
 
 ``OpenVDB_INCLUDE_DIR``
   The directory containing ``openvdb/version.h``.
-``OpenVDB_{COMPONENT}_LIBRARY``
+``OpenVDB_${COMPONENT}_INCLUDE_DIR``
+  Individual component include directories for OpenVDB
+``OpenVDB_${COMPONENT}_LIBRARY``
   Individual component libraries for OpenVDB
 
 Hints
@@ -91,55 +83,30 @@ Hints
 Instead of explicitly setting the cache variables, the following variables
 may be provided to tell this module where to look.
 
-``OPENVDB_ROOT``
+``OpenVDB_ROOT``
   Preferred installation prefix.
 ``OPENVDB_INCLUDEDIR``
   Preferred include directory e.g. <prefix>/include
 ``OPENVDB_LIBRARYDIR``
   Preferred library directory e.g. <prefix>/lib
+``OPENVDB_${COMPONENT}_ROOT``
+  Preferred installation prefix of a specific component.
+``OPENVDB_${COMPONENT}_INCLUDEDIR``
+  Preferred include directory of a specific component e.g. <prefix>/include
+``OPENVDB_${COMPONENT}_LIBRARYDIR``
+  Preferred library directory of a specific component e.g. <prefix>/lib
 ``SYSTEM_LIBRARY_PATHS``
-  Paths appended to all include and lib searches.
+  Global list of library paths intended to be searched by and find_xxx call
+``OPENVDB_USE_STATIC_LIBS``
+  Only search for static openvdb libraries
+``DISABLE_CMAKE_SEARCH_PATHS``
+  Disable CMakes default search paths for find_xxx calls in this module
 
 #]=======================================================================]
 
-# If an explicit openvdb module path was specified, that will be used
-if (OPENVDB_FIND_MODULE_PATH)
-  set(_module_path_bak ${CMAKE_MODULE_PATH})
-  set(CMAKE_MODULE_PATH ${OPENVDB_FIND_MODULE_PATH})
-  find_package(
-    OpenVDB ${OpenVDB_FIND_VERSION} QUIET
-    COMPONENTS
-      ${OpenVDB_FIND_COMPONENTS}
-  )
+cmake_minimum_required(VERSION 3.12)
+include(GNUInstallDirs)
 
-  set(CMAKE_MODULE_PATH ${_module_path_bak})
-  if (OpenVDB_FOUND)
-    return()
-  endif ()
-
-  if (NOT OpenVDB_FIND_QUIETLY)
-    message(STATUS "Using bundled find module for OpenVDB")
-  endif ()
-endif ()
-# ###########################################################################
-
-cmake_minimum_required(VERSION 3.3)
-# Monitoring <PackageName>_ROOT variables
-if(POLICY CMP0074)
-  cmake_policy(SET CMP0074 NEW)
-endif()
-
-if(OpenVDB_FIND_QUIETLY)
-  set (_quiet "QUIET")
-else()
-  set (_quiet "")
-endif()
-
-if(OpenVDB_FIND_REQUIRED)
-  set (_required "REQUIRED")
-else()
-  set (_required "")
-endif()
 
 # Include utility functions for version information
 include(${CMAKE_CURRENT_LIST_DIR}/OpenVDBUtils.cmake)
@@ -149,8 +116,17 @@ mark_as_advanced(
   OpenVDB_LIBRARY
 )
 
+set(_FIND_OPENVDB_ADDITIONAL_OPTIONS "")
+if(DISABLE_CMAKE_SEARCH_PATHS)
+  set(_FIND_OPENVDB_ADDITIONAL_OPTIONS NO_DEFAULT_PATH)
+endif()
+
 set(_OPENVDB_COMPONENT_LIST
   openvdb
+  openvdb_je
+  pyopenvdb
+  openvdb_ax
+  openvdb_houdini
 )
 
 if(OpenVDB_FIND_COMPONENTS)
@@ -171,16 +147,65 @@ if(OpenVDB_FIND_COMPONENTS)
   endif()
 else()
   set(OPENVDB_COMPONENTS_PROVIDED FALSE)
-  set(OpenVDB_FIND_COMPONENTS ${_OPENVDB_COMPONENT_LIST})
+  set(OpenVDB_FIND_COMPONENTS openvdb)
 endif()
 
-# Append OPENVDB_ROOT or $ENV{OPENVDB_ROOT} if set (prioritize the direct cmake var)
-set(_OPENVDB_ROOT_SEARCH_DIR "")
+# always make sure openvdb is picked up as a component i.e.
+# find_package(OpenVDB COMPONENTS pyopenvdb) results in both
+# openvdb and pyopenvdb targets. Also make sure it appears
+# first in the component lists.
+list(INSERT OpenVDB_FIND_COMPONENTS 0 openvdb)
+list(REMOVE_DUPLICATES OpenVDB_FIND_COMPONENTS)
+
+# Set _OPENVDB_ROOT based on a user provided root var. Xxx_ROOT and ENV{Xxx_ROOT}
+# are prioritised over the legacy capitalized XXX_ROOT variables for matching
+# CMake 3.12 behaviour
+# @todo  deprecate -D and ENV OPENVDB_ROOT from CMake 3.12
+if(OpenVDB_ROOT)
+  set(_OPENVDB_ROOT ${OpenVDB_ROOT})
+elseif(DEFINED ENV{OpenVDB_ROOT})
+  set(_OPENVDB_ROOT $ENV{OpenVDB_ROOT})
+elseif(OPENVDB_ROOT)
+  set(_OPENVDB_ROOT ${OPENVDB_ROOT})
+elseif(DEFINED ENV{OPENVDB_ROOT})
+  set(_OPENVDB_ROOT $ENV{OPENVDB_ROOT})
+endif()
 
 # Additionally try and use pkconfig to find OpenVDB
+if(USE_PKGCONFIG)
+  if(NOT DEFINED PKG_CONFIG_FOUND)
+    find_package(PkgConfig)
+  endif()
+  pkg_check_modules(PC_OpenVDB QUIET OpenVDB)
+endif()
+
+# This CMake module supports being called from external packages AND from
+# within the OpenVDB repository for building openvdb components with the
+# core library build disabled. Determine where we are being called from:
+#
+# (repo structure = <root>/cmake/FindOpenVDB.cmake)
+# (inst structure = <root>/lib/cmake/OpenVDB/FindOpenVDB.cmake)
 
-find_package(PkgConfig ${_quiet} )
-pkg_check_modules(PC_OpenVDB QUIET OpenVDB)
+get_filename_component(_DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
+
+if(${_DIR_NAME} STREQUAL "cmake")
+  # Called from root repo for openvdb components
+elseif(${_DIR_NAME} STREQUAL "OpenVDB")
+  # Set the install variable to track directories if this is being called from
+  # an installed location and from another package. The expected installation
+  # directory structure is:
+  #  <root>/lib/cmake/OpenVDB/FindOpenVDB.cmake
+  #  <root>/include
+  #  <root>/bin
+  get_filename_component(_IMPORT_PREFIX ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
+  get_filename_component(_IMPORT_PREFIX ${_IMPORT_PREFIX} DIRECTORY)
+  get_filename_component(_IMPORT_PREFIX ${_IMPORT_PREFIX} DIRECTORY)
+  set(_OPENVDB_INSTALL ${_IMPORT_PREFIX})
+  list(APPEND _OPENVDB_ROOT ${_OPENVDB_INSTALL})
+endif()
+
+unset(_DIR_NAME)
+unset(_IMPORT_PREFIX)
 
 # ------------------------------------------------------------------------
 #  Search for OpenVDB include DIR
@@ -189,24 +214,89 @@ pkg_check_modules(PC_OpenVDB QUIET OpenV
 set(_OPENVDB_INCLUDE_SEARCH_DIRS "")
 list(APPEND _OPENVDB_INCLUDE_SEARCH_DIRS
   ${OPENVDB_INCLUDEDIR}
-  ${_OPENVDB_ROOT_SEARCH_DIR}
+  ${_OPENVDB_ROOT}
   ${PC_OpenVDB_INCLUDE_DIRS}
   ${SYSTEM_LIBRARY_PATHS}
 )
 
-# Look for a standard OpenVDB header file.
-find_path(OpenVDB_INCLUDE_DIR openvdb/version.h
-  PATHS ${_OPENVDB_INCLUDE_SEARCH_DIRS}
-  PATH_SUFFIXES include
-)
+foreach(COMPONENT ${OpenVDB_FIND_COMPONENTS})
+  # Add in extra component paths
+  set(_VDB_COMPONENT_SEARCH_DIRS ${_OPENVDB_INCLUDE_SEARCH_DIRS})
+  list(APPEND _VDB_COMPONENT_SEARCH_DIRS
+    ${OPENVDB_${COMPONENT}_ROOT}
+    ${OPENVDB_${COMPONENT}_INCLUDEDIR}
+  )
+  if(_VDB_COMPONENT_SEARCH_DIRS)
+    list(REMOVE_DUPLICATES _VDB_COMPONENT_SEARCH_DIRS)
+  endif()
+
+  # Look for a standard header files.
+  if(${COMPONENT} STREQUAL "openvdb")
+    # Look for a standard OpenVDB header file.
+    find_path(OpenVDB_${COMPONENT}_INCLUDE_DIR openvdb/version.h
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES
+        ${CMAKE_INSTALL_INCLUDEDIR}
+        include
+    )
+  elseif(${COMPONENT} STREQUAL "pyopenvdb")
+    find_path(OpenVDB_${COMPONENT}_INCLUDE_DIR pyopenvdb.h
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES
+        ${CMAKE_INSTALL_INCLUDEDIR}/openvdb/python
+        ${CMAKE_INSTALL_INCLUDEDIR}/openvdb
+        ${CMAKE_INSTALL_INCLUDEDIR}
+        include
+    )
+  elseif(${COMPONENT} STREQUAL "openvdb_ax")
+    # Look for a standard OpenVDB header file.
+    find_path(OpenVDB_${COMPONENT}_INCLUDE_DIR compiler/Compiler.h
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES
+        ${CMAKE_INSTALL_INCLUDEDIR}/openvdb/openvdb_ax
+        ${CMAKE_INSTALL_INCLUDEDIR}/openvdb_ax
+        ${CMAKE_INSTALL_INCLUDEDIR}
+        include
+    )
+  elseif(${COMPONENT} STREQUAL "openvdb_houdini")
+    # @note  Expects both houdini_utils and openvdb_houdini folders
+    #   to be located in the same place
+    find_path(OpenVDB_${COMPONENT}_INCLUDE_DIR openvdb_houdini/SOP_NodeVDB.h
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES
+        ${CMAKE_INSTALL_INCLUDEDIR}/openvdb
+        ${CMAKE_INSTALL_INCLUDEDIR}
+        include
+    )
+  endif()
+  unset(_VDB_COMPONENT_SEARCH_DIRS)
+endforeach()
+
+set(OpenVDB_INCLUDE_DIR ${OpenVDB_openvdb_INCLUDE_DIR}
+  CACHE PATH "The OpenVDB core include directory")
 
-OPENVDB_VERSION_FROM_HEADER("${OpenVDB_INCLUDE_DIR}/openvdb/version.h"
+set(_OPENVDB_VERSION_HEADER "${OpenVDB_INCLUDE_DIR}/openvdb/version.h")
+OPENVDB_VERSION_FROM_HEADER("${_OPENVDB_VERSION_HEADER}"
   VERSION OpenVDB_VERSION
   MAJOR   OpenVDB_MAJOR_VERSION
   MINOR   OpenVDB_MINOR_VERSION
   PATCH   OpenVDB_PATCH_VERSION
+  ABI     OpenVDB_ABI_FROM_HEADER # will be OpenVDB_MAJOR_VERSION prior to 8.1.0
 )
 
+if(OpenVDB_VERSION VERSION_LESS 8.1.0)
+  set(_OPENVDB_HAS_NEW_VERSION_HEADER FALSE)
+  # ABI gets computed later
+else()
+  set(_OPENVDB_HAS_NEW_VERSION_HEADER TRUE)
+  set(OpenVDB_ABI ${OpenVDB_ABI_FROM_HEADER})
+endif()
+unset(OpenVDB_ABI_FROM_HEADER)
+
 # ------------------------------------------------------------------------
 #  Search for OPENVDB lib DIR
 # ------------------------------------------------------------------------
@@ -217,81 +307,95 @@ set(_OPENVDB_LIBRARYDIR_SEARCH_DIRS "")
 
 list(APPEND _OPENVDB_LIBRARYDIR_SEARCH_DIRS
   ${OPENVDB_LIBRARYDIR}
-  ${_OPENVDB_ROOT_SEARCH_DIR}
+  ${_OPENVDB_ROOT}
   ${PC_OpenVDB_LIBRARY_DIRS}
   ${SYSTEM_LIBRARY_PATHS}
 )
 
-# Build suffix directories
+# Library suffix handling
+
+set(_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
 
-set(OPENVDB_PATH_SUFFIXES
+set(OPENVDB_PYTHON_PATH_SUFFIXES
+  ${CMAKE_INSTALL_LIBDIR}/python
+  ${CMAKE_INSTALL_LIBDIR}/python2.7
+  ${CMAKE_INSTALL_LIBDIR}/python3
+  lib64/python
+  lib64/python2.7
+  lib64/python3
+  lib/python
+  lib/python2.7
+  lib/python3
+)
+
+set(OPENVDB_LIB_PATH_SUFFIXES
+  ${CMAKE_INSTALL_LIBDIR}
   lib64
   lib
 )
 
+list(REMOVE_DUPLICATES OPENVDB_PYTHON_PATH_SUFFIXES)
+list(REMOVE_DUPLICATES OPENVDB_LIB_PATH_SUFFIXES)
+
 # Static library setup
-if(UNIX AND OPENVDB_USE_STATIC_LIBS)
-  set(_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
-  set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
+if(WIN32)
+  if(OPENVDB_USE_STATIC_LIBS)
+    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
+  endif()
+else()
+  if(OPENVDB_USE_STATIC_LIBS)
+    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
+  endif()
 endif()
 
 set(OpenVDB_LIB_COMPONENTS "")
-set(OpenVDB_DEBUG_SUFFIX "d" CACHE STRING "Suffix for the debug libraries")
-
-get_property(_is_multi GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
 
 foreach(COMPONENT ${OpenVDB_FIND_COMPONENTS})
   set(LIB_NAME ${COMPONENT})
 
-  find_library(OpenVDB_${COMPONENT}_LIBRARY_RELEASE ${LIB_NAME} lib${LIB_NAME}
-    PATHS ${_OPENVDB_LIBRARYDIR_SEARCH_DIRS}
-    PATH_SUFFIXES ${OPENVDB_PATH_SUFFIXES}
+  # Add in extra component paths
+  set(_VDB_COMPONENT_SEARCH_DIRS ${_OPENVDB_LIBRARYDIR_SEARCH_DIRS})
+  list(APPEND _VDB_COMPONENT_SEARCH_DIRS
+    ${OPENVDB_${COMPONENT}_ROOT}
+    ${OPENVDB_${COMPONENT}_LIBRARYDIR}
   )
 
-  find_library(OpenVDB_${COMPONENT}_LIBRARY_DEBUG ${LIB_NAME}${OpenVDB_DEBUG_SUFFIX} lib${LIB_NAME}${OpenVDB_DEBUG_SUFFIX}
-    PATHS ${_OPENVDB_LIBRARYDIR_SEARCH_DIRS}
-    PATH_SUFFIXES ${OPENVDB_PATH_SUFFIXES}
-  )
-
-  if (_is_multi)
-    list(APPEND OpenVDB_LIB_COMPONENTS ${OpenVDB_${COMPONENT}_LIBRARY_RELEASE})
-    if (OpenVDB_${COMPONENT}_LIBRARY_DEBUG)
-      list(APPEND OpenVDB_LIB_COMPONENTS ${OpenVDB_${COMPONENT}_LIBRARY_DEBUG})
-    endif ()
-
-    list(FIND CMAKE_CONFIGURATION_TYPES "Debug" _has_debug)
-    
-    if(OpenVDB_${COMPONENT}_LIBRARY_RELEASE AND (NOT MSVC OR _has_debug LESS 0 OR OpenVDB_${COMPONENT}_LIBRARY_DEBUG))
-      set(OpenVDB_${COMPONENT}_FOUND TRUE)
-    else()
-      set(OpenVDB_${COMPONENT}_FOUND FALSE)
-    endif()
-
-    set(OpenVDB_${COMPONENT}_LIBRARY ${OpenVDB_${COMPONENT}_LIBRARY_RELEASE})
-  else ()
-    string(TOUPPER "${CMAKE_BUILD_TYPE}" _BUILD_TYPE)
+  if(${COMPONENT} STREQUAL "pyopenvdb")
+    set(_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES})
+    set(CMAKE_FIND_LIBRARY_PREFIXES ";lib") # find non-prefixed
+    find_library(OpenVDB_${COMPONENT}_LIBRARY ${LIB_NAME}
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES ${OPENVDB_PYTHON_PATH_SUFFIXES}
+    )
+    set(CMAKE_FIND_LIBRARY_PREFIXES ${_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_PREFIXES})
+  elseif(${COMPONENT} STREQUAL "openvdb_je")
+    # alias to the result of openvdb which should be handled first
+    set(OpenVDB_${COMPONENT}_LIBRARY ${OpenVDB_openvdb_LIBRARY})
+  else()
+    find_library(OpenVDB_${COMPONENT}_LIBRARY ${LIB_NAME}
+      ${_FIND_OPENVDB_ADDITIONAL_OPTIONS}
+      PATHS ${_VDB_COMPONENT_SEARCH_DIRS}
+      PATH_SUFFIXES ${OPENVDB_LIB_PATH_SUFFIXES}
+    )
+  endif()
 
-    set(OpenVDB_${COMPONENT}_LIBRARY ${OpenVDB_${COMPONENT}_LIBRARY_${_BUILD_TYPE}})
+  list(APPEND OpenVDB_LIB_COMPONENTS ${OpenVDB_${COMPONENT}_LIBRARY})
+  if(OpenVDB_${COMPONENT}_LIBRARY)
+    set(OpenVDB_${COMPONENT}_FOUND TRUE)
+  else()
+    set(OpenVDB_${COMPONENT}_FOUND FALSE)
+  endif()
+  unset(_VDB_COMPONENT_SEARCH_DIRS)
+endforeach()
 
-    if (NOT OpenVDB_${COMPONENT}_LIBRARY)
-      set(OpenVDB_${COMPONENT}_LIBRARY ${OpenVDB_${COMPONENT}_LIBRARY_RELEASE})
-    endif ()
+unset(OPENVDB_PYTHON_PATH_SUFFIXES)
+unset(OPENVDB_LIB_PATH_SUFFIXES)
 
-    list(APPEND OpenVDB_LIB_COMPONENTS ${OpenVDB_${COMPONENT}_LIBRARY})
+# Reset library suffix
 
-    if(OpenVDB_${COMPONENT}_LIBRARY)
-      set(OpenVDB_${COMPONENT}_FOUND TRUE)
-    else()
-      set(OpenVDB_${COMPONENT}_FOUND FALSE)
-    endif()
-  endif ()
-
-endforeach()
-
-if(UNIX AND OPENVDB_USE_STATIC_LIBS)
-  set(CMAKE_FIND_LIBRARY_SUFFIXES ${_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES})
-  unset(_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES)
-endif()
+set(CMAKE_FIND_LIBRARY_SUFFIXES ${_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES})
+unset(_OPENVDB_ORIG_CMAKE_FIND_LIBRARY_SUFFIXES)
 
 # ------------------------------------------------------------------------
 #  Cache and set OPENVDB_FOUND
@@ -311,15 +415,25 @@ find_package_handle_standard_args(OpenVD
 #  Determine ABI number
 # ------------------------------------------------------------------------
 
-# Set the ABI number the library was built against. Uses vdb_print
-find_program(OPENVDB_PRINT vdb_print PATHS ${OpenVDB_INCLUDE_DIR} )
+# Set the ABI number the library was built against. The old system,
+# which didn't define the ABI in the build config, uses vdb_print
 
-OPENVDB_ABI_VERSION_FROM_PRINT(
-  "${OPENVDB_PRINT}"
-  ABI OpenVDB_ABI
-)
+if(NOT _OPENVDB_HAS_NEW_VERSION_HEADER)
+  if(_OPENVDB_INSTALL)
+    OPENVDB_ABI_VERSION_FROM_PRINT(
+      "${_OPENVDB_INSTALL}/bin/vdb_print"
+      ABI OpenVDB_ABI
+    )
+  else()
+    # Try and find vdb_print from the include path
+    OPENVDB_ABI_VERSION_FROM_PRINT(
+      "${OpenVDB_INCLUDE_DIR}/../bin/vdb_print"
+      ABI OpenVDB_ABI
+    )
+  endif()
+endif()
 
-if(NOT OpenVDB_FIND_QUIETLY)
+if(NOT OpenVDB_FIND_QUIET)
   if(NOT OpenVDB_ABI)
     message(WARNING "Unable to determine OpenVDB ABI version from OpenVDB "
       "installation. The library major version \"${OpenVDB_MAJOR_VERSION}\" "
@@ -332,166 +446,208 @@ if(NOT OpenVDB_FIND_QUIETLY)
 endif()
 
 # ------------------------------------------------------------------------
-#  Handle OpenVDB dependencies
+#  Handle OpenVDB dependencies and interface settings
 # ------------------------------------------------------------------------
 
+# Handle openvdb_houdini first to configure search paths
+
+if(openvdb_houdini IN_LIST OpenVDB_FIND_COMPONENTS)
+  include(OpenVDBHoudiniSetup)
+endif()
+
 # Add standard dependencies
 
-macro(just_fail msg)
-  set(OpenVDB_FOUND FALSE)
-  if(OpenVDB_FIND_REQUIRED)
-    message(FATAL_ERROR ${msg})
-  elseif(NOT OpenVDB_FIND_QUIETLY)
-    message(WARNING ${msg})
-  endif()
-  return()
-endmacro()
-
-find_package(IlmBase QUIET)
-if(NOT IlmBase_FOUND)
-  pkg_check_modules(IlmBase QUIET IlmBase)
-endif()
-if (IlmBase_FOUND AND NOT TARGET IlmBase::Half)
-  message(STATUS "Falling back to IlmBase found by pkg-config...")
-
-  find_library(IlmHalf_LIBRARY NAMES Half)
-  if(IlmHalf_LIBRARY-NOTFOUND OR NOT IlmBase_INCLUDE_DIRS)
-    just_fail("IlmBase::Half can not be found!")
-  endif()
-  
-  add_library(IlmBase::Half UNKNOWN IMPORTED)
-  set_target_properties(IlmBase::Half PROPERTIES
-    IMPORTED_LOCATION "${IlmHalf_LIBRARY}"
-    INTERFACE_INCLUDE_DIRECTORIES "${IlmBase_INCLUDE_DIRS}")
-elseif(NOT IlmBase_FOUND)
-  just_fail("IlmBase::Half can not be found!")
-endif()
-find_package(TBB ${_quiet} ${_required} COMPONENTS tbb)
-find_package(ZLIB ${_quiet} ${_required})
-find_package(Boost ${_quiet} ${_required} COMPONENTS iostreams system )
-
-# Use GetPrerequisites to see which libraries this OpenVDB lib has linked to
-# which we can query for optional deps. This basically runs ldd/otoll/objdump
-# etc to track deps. We could use a vdb_config binary tools here to improve
-# this process
-
-include(GetPrerequisites)
-
-set(_EXCLUDE_SYSTEM_PREREQUISITES 1)
-set(_RECURSE_PREREQUISITES 0)
-set(_OPENVDB_PREREQUISITE_LIST)
+find_package(TBB REQUIRED COMPONENTS tbb)
 
-if(NOT OPENVDB_USE_STATIC_LIBS)
-get_prerequisites(${OpenVDB_openvdb_LIBRARY}
-  _OPENVDB_PREREQUISITE_LIST
-  ${_EXCLUDE_SYSTEM_PREREQUISITES}
-  ${_RECURSE_PREREQUISITES}
-  ""
-  "${SYSTEM_LIBRARY_PATHS}"
-)
+if(NOT OPENVDB_USE_STATIC_LIBS AND NOT Boost_USE_STATIC_LIBS)
+  # @note  Both of these must be set for Boost 1.70 (VFX2020) to link against
+  #        boost shared libraries (more specifically libraries built with -fPIC).
+  #        http://boost.2283326.n4.nabble.com/CMake-config-scripts-broken-in-1-70-td4708957.html
+  #        https://github.com/boostorg/boost_install/commit/160c7cb2b2c720e74463865ef0454d4c4cd9ae7c
+  set(BUILD_SHARED_LIBS ON)
+  set(Boost_USE_STATIC_LIBS OFF)
+endif()
+
+find_package(Boost REQUIRED COMPONENTS iostreams)
+
+# Add deps for pyopenvdb
+# @todo track for numpy
+
+if(pyopenvdb IN_LIST OpenVDB_FIND_COMPONENTS)
+  find_package(PythonLibs REQUIRED)
+
+  # Boost python handling - try and find both python and pythonXx (version suffixed).
+  # Prioritize the version suffixed library, failing if neither exist.
+
+  find_package(Boost ${MINIMUM_BOOST_VERSION}
+    QUIET COMPONENTS python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}
+  )
+
+  if(TARGET Boost::python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
+    set(BOOST_PYTHON_LIB "python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}")
+    message(STATUS "Found boost_python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}")
+  else()
+    find_package(Boost ${MINIMUM_BOOST_VERSION} QUIET COMPONENTS python)
+    if(TARGET Boost::python)
+      set(BOOST_PYTHON_LIB "python")
+      message(STATUS "Found non-suffixed boost_python, assuming to be python version "
+        "\"${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}\" compatible"
+      )
+    else()
+      message(FATAL_ERROR "Unable to find boost_python or "
+        "boost_python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}."
+      )
+    endif()
+  endif()
 endif()
 
-unset(_EXCLUDE_SYSTEM_PREREQUISITES)
-unset(_RECURSE_PREREQUISITES)
+# Add deps for openvdb_ax
+
+if(openvdb_ax IN_LIST OpenVDB_FIND_COMPONENTS)
+  find_package(LLVM REQUIRED)
+  find_library(found_LLVM LLVM HINTS ${LLVM_LIBRARY_DIRS})
+
+  if(found_LLVM)
+    set(LLVM_LIBS "LLVM")
+  else()
+    llvm_map_components_to_libnames(_llvm_libs
+      native core executionengine support mcjit passes objcarcopts)
+    set(LLVM_LIBS "${_llvm_libs}")
+  endif()
+
+  if(NOT OpenVDB_FIND_QUIET)
+    message(STATUS "Found LLVM: ${LLVM_DIR} (found version \"${LLVM_PACKAGE_VERSION}\")")
+  endif()
+endif()
 
 # As the way we resolve optional libraries relies on library file names, use
 # the configuration options from the main CMakeLists.txt to allow users
 # to manually identify the requirements of OpenVDB builds if they know them.
-
 set(OpenVDB_USES_BLOSC ${USE_BLOSC})
+set(OpenVDB_USES_ZLIB ${USE_ZLIB})
 set(OpenVDB_USES_LOG4CPLUS ${USE_LOG4CPLUS})
-set(OpenVDB_USES_ILM ${USE_EXR})
-set(OpenVDB_USES_EXR ${USE_EXR})
+set(OpenVDB_USES_IMATH_HALF ${USE_IMATH_HALF})
+set(OpenVDB_DEFINITIONS)
 
-# Search for optional dependencies
+if(WIN32)
+  if(OPENVDB_USE_STATIC_LIBS)
+    list(APPEND OpenVDB_DEFINITIONS OPENVDB_STATICLIB)
+  else()
+    list(APPEND OpenVDB_DEFINITIONS OPENVDB_DLL)
+  endif()
+  # Newer version of OpenVDB define these in Platform.h, but they are also
+  # provided here to maintain backwards compatibility with header include
+  # others
+  list(APPEND OpenVDB_DEFINITIONS _WIN32)
+  list(APPEND OpenVDB_DEFINITIONS NOMINMAX)
+endif()
 
-foreach(PREREQUISITE ${_OPENVDB_PREREQUISITE_LIST})
-  set(_HAS_DEP)
-  get_filename_component(PREREQUISITE ${PREREQUISITE} NAME)
+if(OpenVDB_ABI)
+  # Newer version of OpenVDB defines this in version.h, but it is are also
+  # provided here to maintain backwards compatibility with header include
+  # others
+  list(APPEND OpenVDB_DEFINITIONS OPENVDB_ABI_VERSION_NUMBER=${OpenVDB_ABI})
+endif()
+
+# Configure deps
+
+if(_OPENVDB_HAS_NEW_VERSION_HEADER)
+  # OPENVDB_GET_VERSION_DEFINE(${_OPENVDB_VERSION_HEADER} "OPENVDB_USE_IMATH_HALF" OpenVDB_USES_IMATH_HALF)
+  # OPENVDB_GET_VERSION_DEFINE(${_OPENVDB_VERSION_HEADER} "OPENVDB_USE_BLOSC" OpenVDB_USES_BLOSC)
+  # OPENVDB_GET_VERSION_DEFINE(${_OPENVDB_VERSION_HEADER} "OPENVDB_USE_ZLIB" OpenVDB_USES_ZLIB)
+elseif(NOT OPENVDB_USE_STATIC_LIBS)
+  # Use GetPrerequisites to see which libraries this OpenVDB lib has linked to
+  # which we can query for optional deps. This basically runs ldd/otoll/objdump
+  # etc to track deps. We could use a vdb_config binary tools here to improve
+  # this process
+  include(GetPrerequisites)
+
+  set(_EXCLUDE_SYSTEM_PREREQUISITES 1)
+  set(_RECURSE_PREREQUISITES 0)
+  set(_OPENVDB_PREREQUISITE_LIST)
+
+  get_prerequisites(${OpenVDB_openvdb_LIBRARY}
+    _OPENVDB_PREREQUISITE_LIST
+    ${_EXCLUDE_SYSTEM_PREREQUISITES}
+    ${_RECURSE_PREREQUISITES}
+    ""
+    "${SYSTEM_LIBRARY_PATHS}"
+  )
 
-  string(FIND ${PREREQUISITE} "blosc" _HAS_DEP)
-  if(NOT ${_HAS_DEP} EQUAL -1)
-    set(OpenVDB_USES_BLOSC ON)
-  endif()
+  unset(_EXCLUDE_SYSTEM_PREREQUISITES)
+  unset(_RECURSE_PREREQUISITES)
 
-  string(FIND ${PREREQUISITE} "log4cplus" _HAS_DEP)
-  if(NOT ${_HAS_DEP} EQUAL -1)
-    set(OpenVDB_USES_LOG4CPLUS ON)
-  endif()
+  # Search for optional dependencies
+  foreach(PREREQUISITE ${_OPENVDB_PREREQUISITE_LIST})
+    set(_HAS_DEP)
+    get_filename_component(PREREQUISITE ${PREREQUISITE} NAME)
+
+    string(FIND ${PREREQUISITE} "blosc" _HAS_DEP)
+    if(NOT ${_HAS_DEP} EQUAL -1)
+      set(OpenVDB_USES_BLOSC ON)
+    endif()
 
-  string(FIND ${PREREQUISITE} "IlmImf" _HAS_DEP)
-  if(NOT ${_HAS_DEP} EQUAL -1)
-    set(OpenVDB_USES_ILM ON)
-  endif()
-endforeach()
+    string(FIND ${PREREQUISITE} "zlib" _HAS_DEP)
+    if(NOT ${_HAS_DEP} EQUAL -1)
+      set(OpenVDB_USES_ZLIB ON)
+    endif()
 
-unset(_OPENVDB_PREREQUISITE_LIST)
-unset(_HAS_DEP)
+    string(FIND ${PREREQUISITE} "log4cplus" _HAS_DEP)
+    if(NOT ${_HAS_DEP} EQUAL -1)
+      set(OpenVDB_USES_LOG4CPLUS ON)
+    endif()
 
-if(OpenVDB_USES_BLOSC)
-  find_package(Blosc QUIET)
-  if(NOT Blosc_FOUND OR NOT TARGET Blosc::blosc) 
-    message(STATUS "find_package could not find Blosc. Using fallback blosc search...")
-    find_path(Blosc_INCLUDE_DIR blosc.h)
-    find_library(Blosc_LIBRARY NAMES blosc)
-    if (Blosc_INCLUDE_DIR AND Blosc_LIBRARY)
-      set(Blosc_FOUND TRUE)
-      add_library(Blosc::blosc UNKNOWN IMPORTED)
-      set_target_properties(Blosc::blosc PROPERTIES 
-        IMPORTED_LOCATION "${Blosc_LIBRARY}"
-        INTERFACE_INCLUDE_DIRECTORIES ${Blosc_INCLUDE_DIR})
-    elseif()
-      just_fail("Blosc library can not be found!")
+    string(FIND ${PREREQUISITE} "Half" _HAS_DEP)
+    if(NOT ${_HAS_DEP} EQUAL -1)
+      set(OpenVDB_USES_IMATH_HALF ON)
     endif()
-  endif()
+  endforeach()
+
+  unset(_OPENVDB_PREREQUISITE_LIST)
 endif()
 
-if(OpenVDB_USES_LOG4CPLUS)
-  find_package(Log4cplus ${_quiet} ${_required})
+if(OpenVDB_USES_BLOSC)
+  find_package(Blosc REQUIRED)
+endif()
+
+if(OpenVDB_USES_ZLIB)
+  find_package(ZLIB REQUIRED)
 endif()
 
-if(OpenVDB_USES_ILM)
-  find_package(IlmBase ${_quiet} ${_required})
+if(OpenVDB_USES_LOG4CPLUS)
+  find_package(Log4cplus REQUIRED)
 endif()
 
-if(OpenVDB_USES_EXR)
-  find_package(OpenEXR ${_quiet} ${_required})
+if(OpenVDB_USES_IMATH_HALF)
+  find_package(IlmBase REQUIRED COMPONENTS Half)
+  if(WIN32)
+    # @note OPENVDB_OPENEXR_STATICLIB is old functionality and should be removed
+    if(OPENEXR_USE_STATIC_LIBS OR (${ILMBASE_LIB_TYPE} STREQUAL STATIC_LIBRARY))
+      list(APPEND OpenVDB_DEFINITIONS OPENVDB_OPENEXR_STATICLIB)
+    endif()
+  endif()
 endif()
 
 if(UNIX)
-  find_package(Threads ${_quiet} ${_required})
+  find_package(Threads REQUIRED)
 endif()
 
 # Set deps. Note that the order here is important. If we're building against
-# Houdini 17.5 we must include OpenEXR and IlmBase deps first to ensure the
-# users chosen namespaced headers are correctly prioritized. Otherwise other
-# include paths from shared installs (including houdini) may pull in the wrong
-# headers
+# Houdini 17.5 we must include IlmBase deps first to ensure the users chosen
+# namespaced headers are correctly prioritized. Otherwise other include paths
+# from shared installs (including houdini) may pull in the wrong headers
 
 set(_OPENVDB_VISIBLE_DEPENDENCIES
   Boost::iostreams
-  Boost::system
-  IlmBase::Half
 )
 
-set(_OPENVDB_DEFINITIONS)
-if(OpenVDB_ABI)
-  list(APPEND _OPENVDB_DEFINITIONS "-DOPENVDB_ABI_VERSION_NUMBER=${OpenVDB_ABI}")
-endif()
-
-if(OpenVDB_USES_EXR)
-  list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES
-    IlmBase::IlmThread
-    IlmBase::Iex
-    IlmBase::Imath
-    OpenEXR::IlmImf
-  )
-  list(APPEND _OPENVDB_DEFINITIONS "-DOPENVDB_TOOLS_RAYTRACER_USE_EXR")
+if(OpenVDB_USES_IMATH_HALF)
+  list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES IlmBase::Half)
 endif()
 
 if(OpenVDB_USES_LOG4CPLUS)
   list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES Log4cplus::log4cplus)
-  list(APPEND _OPENVDB_DEFINITIONS "-DOPENVDB_USE_LOG4CPLUS")
+  list(APPEND OpenVDB_DEFINITIONS OPENVDB_USE_LOG4CPLUS)
 endif()
 
 list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES
@@ -505,34 +661,26 @@ endif()
 
 set(_OPENVDB_HIDDEN_DEPENDENCIES)
 
-if(OpenVDB_USES_BLOSC)
-  if(OPENVDB_USE_STATIC_LIBS)
-    list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES $<LINK_ONLY:Blosc::blosc>)
-  else()
+if(NOT OPENVDB_USE_STATIC_LIBS)
+  if(OpenVDB_USES_BLOSC)
     list(APPEND _OPENVDB_HIDDEN_DEPENDENCIES Blosc::blosc)
   endif()
+  if(OpenVDB_USES_ZLIB)
+    list(APPEND _OPENVDB_HIDDEN_DEPENDENCIES ZLIB::ZLIB)
+  endif()
 endif()
 
-if(OPENVDB_USE_STATIC_LIBS)
-  list(APPEND _OPENVDB_VISIBLE_DEPENDENCIES $<LINK_ONLY:ZLIB::ZLIB>)
-else()
-  list(APPEND _OPENVDB_HIDDEN_DEPENDENCIES ZLIB::ZLIB)
+if(openvdb_je IN_LIST OpenVDB_FIND_COMPONENTS)
+  find_package(Jemalloc REQUIRED)
 endif()
 
 # ------------------------------------------------------------------------
-#  Configure imported target
+#  Configure imported targets
 # ------------------------------------------------------------------------
 
-set(OpenVDB_LIBRARIES
-  ${OpenVDB_LIB_COMPONENTS}
-)
+set(OpenVDB_LIBRARIES ${OpenVDB_LIB_COMPONENTS})
 set(OpenVDB_INCLUDE_DIRS ${OpenVDB_INCLUDE_DIR})
 
-set(OpenVDB_DEFINITIONS)
-list(APPEND OpenVDB_DEFINITIONS "${PC_OpenVDB_CFLAGS_OTHER}")
-list(APPEND OpenVDB_DEFINITIONS "${_OPENVDB_DEFINITIONS}")
-list(REMOVE_DUPLICATES OpenVDB_DEFINITIONS)
-
 set(OpenVDB_LIBRARY_DIRS "")
 foreach(LIB ${OpenVDB_LIB_COMPONENTS})
   get_filename_component(_OPENVDB_LIBDIR ${LIB} DIRECTORY)
@@ -540,49 +688,102 @@ foreach(LIB ${OpenVDB_LIB_COMPONENTS})
 endforeach()
 list(REMOVE_DUPLICATES OpenVDB_LIBRARY_DIRS)
 
-foreach(COMPONENT ${OpenVDB_FIND_COMPONENTS})
-  if(NOT TARGET OpenVDB::${COMPONENT})
-    if (${COMPONENT} STREQUAL openvdb)
-      include (${CMAKE_CURRENT_LIST_DIR}/CheckAtomic.cmake)
-      set(_LINK_LIBS ${_OPENVDB_VISIBLE_DEPENDENCIES} ${CMAKE_REQUIRED_LIBRARIES})
-    else ()
-      set(_LINK_LIBS _OPENVDB_VISIBLE_DEPENDENCIES)
-    endif ()
-
-    add_library(OpenVDB::${COMPONENT} UNKNOWN IMPORTED)
-    set_target_properties(OpenVDB::${COMPONENT} PROPERTIES
-      INTERFACE_COMPILE_OPTIONS "${OpenVDB_DEFINITIONS}"
-      INTERFACE_INCLUDE_DIRECTORIES "${OpenVDB_INCLUDE_DIR}"
-      IMPORTED_LINK_DEPENDENT_LIBRARIES "${_OPENVDB_HIDDEN_DEPENDENCIES}" # non visible deps
-      INTERFACE_LINK_LIBRARIES "${_LINK_LIBS}" # visible deps (headers)
-      INTERFACE_COMPILE_FEATURES cxx_std_11
-      IMPORTED_LOCATION "${OpenVDB_${COMPONENT}_LIBRARY}"
+# OpenVDB::openvdb
+
+if(NOT TARGET OpenVDB::openvdb)
+  set(OPENVDB_openvdb_LIB_TYPE UNKNOWN)
+  if(OPENVDB_USE_STATIC_LIBS)
+    set(OPENVDB_openvdb_LIB_TYPE STATIC)
+  elseif(UNIX)
+    get_filename_component(_OPENVDB_openvdb_EXT
+      ${OpenVDB_openvdb_LIBRARY} EXT)
+    if(_OPENVDB_openvdb_EXT STREQUAL ".a")
+      set(OPENVDB_openvdb_LIB_TYPE STATIC)
+    elseif(_OPENVDB_openvdb_EXT STREQUAL ".so" OR
+           _OPENVDB_openvdb_EXT STREQUAL ".dylib")
+      set(OPENVDB_openvdb_LIB_TYPE SHARED)
+    endif()
+  endif()
+
+  add_library(OpenVDB::openvdb ${OPENVDB_openvdb_LIB_TYPE} IMPORTED)
+  set_target_properties(OpenVDB::openvdb PROPERTIES
+    IMPORTED_LOCATION "${OpenVDB_openvdb_LIBRARY}"
+    INTERFACE_COMPILE_OPTIONS "${PC_OpenVDB_CFLAGS_OTHER}"
+    INTERFACE_COMPILE_DEFINITIONS "${OpenVDB_DEFINITIONS}"
+    INTERFACE_INCLUDE_DIRECTORIES "${OpenVDB_INCLUDE_DIR}"
+    IMPORTED_LINK_DEPENDENT_LIBRARIES "${_OPENVDB_HIDDEN_DEPENDENCIES}" # non visible deps
+    INTERFACE_LINK_LIBRARIES "${_OPENVDB_VISIBLE_DEPENDENCIES}" # visible deps (headers)
+    INTERFACE_COMPILE_FEATURES cxx_std_14
+  )
+endif()
+
+# OpenVDB::openvdb_je
+
+if(OpenVDB_openvdb_je_LIBRARY)
+  if(NOT TARGET OpenVDB::openvdb_je)
+    add_library(OpenVDB::openvdb_je INTERFACE IMPORTED)
+    target_link_libraries(OpenVDB::openvdb_je INTERFACE OpenVDB::openvdb)
+    target_link_libraries(OpenVDB::openvdb_je INTERFACE Jemalloc::jemalloc)
+  endif()
+endif()
+
+# OpenVDB::pyopenvdb
+
+if(OpenVDB_pyopenvdb_LIBRARY)
+  if(NOT TARGET OpenVDB::pyopenvdb)
+    add_library(OpenVDB::pyopenvdb MODULE IMPORTED)
+    set_target_properties(OpenVDB::pyopenvdb PROPERTIES
+      IMPORTED_LOCATION "${OpenVDB_pyopenvdb_LIBRARY}"
+      INTERFACE_INCLUDE_DIRECTORIES "${OpenVDB_pyopenvdb_INCLUDE_DIR};${PYTHON_INCLUDE_DIR}"
+      INTERFACE_LINK_LIBRARIES "OpenVDB::openvdb;Boost::${BOOST_PYTHON_LIB};${PYTHON_LIBRARIES}"
+      INTERFACE_COMPILE_FEATURES cxx_std_14
    )
+  endif()
+endif()
 
-   if (_is_multi)
-     set_target_properties(OpenVDB::${COMPONENT} PROPERTIES 
-       IMPORTED_LOCATION_RELEASE "${OpenVDB_${COMPONENT}_LIBRARY_RELEASE}"
-     )
-
-     if (MSVC OR OpenVDB_${COMPONENT}_LIBRARY_DEBUG)
-      set_target_properties(OpenVDB::${COMPONENT} PROPERTIES 
-        IMPORTED_LOCATION_DEBUG "${OpenVDB_${COMPONENT}_LIBRARY_DEBUG}"
-      ) 
-     endif ()
-   endif ()
-
-   if (OPENVDB_USE_STATIC_LIBS)
-    set_target_properties(OpenVDB::${COMPONENT} PROPERTIES
-      INTERFACE_COMPILE_DEFINITIONS "OPENVDB_STATICLIB;OPENVDB_OPENEXR_STATICLIB"
-    )
-   endif()
+# OpenVDB::openvdb_houdini
+
+if(OpenVDB_openvdb_houdini_LIBRARY)
+  if(NOT TARGET OpenVDB::openvdb_houdini)
+    add_library(OpenVDB::openvdb_houdini SHARED IMPORTED)
+    set_target_properties(OpenVDB::openvdb_houdini PROPERTIES
+      IMPORTED_LOCATION "${OpenVDB_openvdb_houdini_LIBRARY}"
+      INTERFACE_INCLUDE_DIRECTORIES "${OpenVDB_openvdb_houdini_INCLUDE_DIR}"
+      INTERFACE_LINK_LIBRARIES "OpenVDB::openvdb;Houdini"
+      INTERFACE_COMPILE_FEATURES cxx_std_14
+   )
   endif()
-endforeach()
+endif()
+
+# OpenVDB::openvdb_ax
+
+if(OpenVDB_openvdb_ax_LIBRARY)
+  set(OPENVDB_openvdb_ax_LIB_TYPE UNKNOWN)
+  if(OPENVDB_USE_STATIC_LIBS)
+    set(OPENVDB_openvdb_ax_LIB_TYPE STATIC)
+  elseif(UNIX)
+    get_filename_component(_OPENVDB_openvdb_ax_EXT
+      ${OpenVDB_openvdb_ax_LIBRARY} EXT)
+    if(_OPENVDB_openvdb_ax_EXT STREQUAL ".a")
+      set(OPENVDB_openvdb_ax_LIB_TYPE STATIC)
+    elseif(_OPENVDB_openvdb_ax_EXT STREQUAL ".so" OR
+           _OPENVDB_openvdb_ax_EXT STREQUAL ".dylib")
+      set(OPENVDB_openvdb_ax_LIB_TYPE SHARED)
+    endif()
+  endif()
+
 
-if(OpenVDB_FOUND AND NOT OpenVDB_FIND_QUIETLY)
-  message(STATUS "OpenVDB libraries: ${OpenVDB_LIBRARIES}")
+  if(NOT TARGET OpenVDB::openvdb_ax)
+    add_library(OpenVDB::openvdb_ax UNKNOWN IMPORTED)
+    set_target_properties(OpenVDB::openvdb_ax PROPERTIES
+      IMPORTED_LOCATION "${OpenVDB_openvdb_ax_LIBRARY}"
+      INTERFACE_INCLUDE_DIRECTORIES "${OpenVDB_openvdb_ax_INCLUDE_DIR}"
+      INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "${LLVM_INCLUDE_DIRS}"
+      INTERFACE_LINK_LIBRARIES "OpenVDB::openvdb;${LLVM_LIBS}"
+      INTERFACE_COMPILE_FEATURES cxx_std_14
+    )
+  endif()
 endif()
 
-unset(_OPENVDB_DEFINITIONS)
 unset(_OPENVDB_VISIBLE_DEPENDENCIES)
 unset(_OPENVDB_HIDDEN_DEPENDENCIES)
