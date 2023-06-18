$NetBSD$

* Use the pkgsrc libraries instead of compiling 3rd party sources.

--- cmake_modules/config_platform_deps.cmake.orig	2023-06-16 02:36:07.000000000 +0000
+++ cmake_modules/config_platform_deps.cmake
@@ -16,7 +16,7 @@ if(TARGET_USE_CURL)
         CURL_STATICLIB
     )
 
-    if(TARGET_LINUX)
+    if(TARGET_LINUX OR TARGET_PKGSRC)
         # Linux can just use the package manager version of libcurl, yay
         add_definitions(-DPLATFORM_CURL)
     else()
@@ -44,12 +44,18 @@ if(DEBUG_QOL_CHEATS)
     add_definitions(-DDEBUG_QOL_CHEATS)
 endif()
 
+if(NOT TARGET_PKGSRC) # use pkgsrc GLUT
+
 find_package(GLUT)
 if(NOT FreeGLUT_FOUND OR CMAKE_CROSSCOMPILING)
     message(STATUS "Going to build “FreeGLUT 3.4.0” from Git module")
     include(build_freeglut)
 endif()
 
+endif() # use pkgsrc GLUT
+
+if(NOT TARGET_PKGSRC) # use pkgsrc GLEW
+
 set(GLEW_USE_STATIC_LIBS TRUE)
 find_package(GLEW 2.2.0)
 if((NOT GLEW_FOUND OR CMAKE_CROSSCOMPILING) AND NOT PLAT_WASM)
@@ -57,20 +63,29 @@ if((NOT GLEW_FOUND OR CMAKE_CROSSCOMPILI
     include(build_glew)
 endif()
 
+endif() # use pkgsrc GLEW
+
 if (NOT TARGET_USE_BASICSOCKETS AND NOT TARGET_USE_GAMENETWORKINGSOCKETS)
     set(TARGET_USE_NOSOCKETS TRUE)
 endif()
 
+if(NOT TARGET_PKGSRC) # use pkgsrc zlib
 
 message(STATUS "Going to build “zlib 1.2.13” from Git module")
 include(build_zlib)
 
+endif() # use pkgsrc zlib
+
+if(NOT TARGET_PKGSRC) # use pkgsrc physfs
+
 if(TARGET_USE_PHYSFS)
     message(STATUS "Going to build “PhysFS 3.2.0” from Git module")
     include(build_physfs)
     add_compile_definitions(PLATFORM_PHYSFS)
 endif()
 
+endif() # use pkgsrc physfs
+
 if(TARGET_USE_GAMENETWORKINGSOCKETS)
     set(PROTOBUF_DEPENDS ZLIB_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})
     set(PROTOBUF_BUILD_PROTOC_BINARIES TRUE)
@@ -120,9 +135,13 @@ if(TARGET_USE_NOSOCKETS AND NOT TARGET_H
     add_definitions(-DPLATFORM_NOSOCKETS)
 endif()
 
+if(NOT TARGET_PKGSRC) # use pkgsrc libpng
+
 message(STATUS "Going to build “libpng 1.6.39” from Git module")
 include(build_libpng)
 
+endif() # use pkgsrc libpng
+
 if(TARGET_USE_LIBSMACKER)
     list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/external/libsmacker/smacker.c ${PROJECT_SOURCE_DIR}/src/external/libsmacker/smk_bitstream.c ${PROJECT_SOURCE_DIR}/src/external/libsmacker/smk_hufftree.c)
 endif()
@@ -131,8 +150,10 @@ if(TARGET_USE_LIBSMUSHER)
     list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/external/libsmusher/src/smush.c ${PROJECT_SOURCE_DIR}/src/external/libsmusher/src/codec48.c)
 endif()
 
+if(NOT TARGET_PKGSRC) # use pkgsrc SDL2
+
 # Build SDL2 from sources (n/a for WASM)
-if(TARGET_USE_SDL2 AND NOT PLAT_WASM)
+if(TARGET_USE_SDL2 AND NOT PLAT_WASM AND NOT PLAT_PKGSRC)
     message(STATUS "Going to build “SDL 2.26.5” from Git module")
     include(build_sdl)
 
@@ -142,6 +163,8 @@ if(TARGET_USE_SDL2 AND NOT PLAT_WASM)
     endif()
 endif()
 
+endif() # use pkgsrc SDL2
+
 # SDL2 Platform/
 if(TARGET_USE_SDL2)
     file(GLOB TARGET_SDL2_SRCS ${PROJECT_SOURCE_DIR}/src/Platform/SDL2/*.c)
@@ -157,6 +180,8 @@ if(TARGET_USE_OPENGL)
     list(APPEND SOURCE_FILES ${TARGET_GL_CPP_SRCS})
 endif()
 
+if(NOT TARGET_PKGSRC) # use pkgsrc openAL
+
 if(TARGET_USE_OPENAL AND NOT PLAT_WASM)
     #find_package(OpenAL 1.23.1)
     if(NOT OPENAL_FOUND)
@@ -168,6 +193,8 @@ else()
     add_compile_definitions(STDSOUND_NULL)
 endif()
 
+endif() # use pkgsrc openAL
+
 if(TARGET_USE_D3D)
     file(GLOB TARGET_D3D_SRCS ${PROJECT_SOURCE_DIR}/src/Platform/D3D/*.c)
     list(APPEND SOURCE_FILES ${TARGET_D3D_SRCS})
@@ -180,7 +207,7 @@ if(TARGET_POSIX)
     add_definitions(-DPLATFORM_POSIX)
 endif()
 
-if(TARGET_LINUX)
+if(TARGET_LINUX OR TARGET_PKGSRC)
     list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/external/nativefiledialog-extended/nfd_gtk.cpp)
 
     add_definitions(-DLINUX)
@@ -203,6 +230,12 @@ if(TARGET_WASM)
     add_definitions(-DLINUX)
 endif()
 
+if(TARGET_PKGSRC)
+    add_definitions(-DLINUX)
+    add_definitions(-DPLATFORM_LINUX)
+    add_definitions(-DPLATFORM_NO_CACERT_BLOB)
+endif()
+
 if(TARGET_CAN_JKGM)
     add_definitions(-DTARGET_CAN_JKGM)
 endif()
