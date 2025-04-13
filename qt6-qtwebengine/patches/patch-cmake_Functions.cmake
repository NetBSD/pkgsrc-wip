$NetBSD$

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- cmake/Functions.cmake.orig	2024-11-21 04:36:37.000000000 +0000
+++ cmake/Functions.cmake
@@ -416,7 +416,7 @@ function(add_linker_options target build
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
     set(ldir_rsp "${buildDir}/${ninjaTarget}_ldir.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX OR ANDROID)
+    if(UNIX OR ANDROID)
          get_gn_arch(cpu ${TEST_architecture_arch})
          if(CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm" AND ${config} STREQUAL "Debug")
              target_link_options(${cmakeTarget} PRIVATE "LINKER:--long-plt")
@@ -672,6 +672,10 @@ function(get_gn_os result)
         set(${result} "win" PARENT_SCOPE)
     elseif(LINUX)
         set(${result} "linux" PARENT_SCOPE)
+    elseif(OPENBSD)
+        set(${result} "linux" PARENT_SCOPE)
+    elseif(NETBSD)
+        set(${result} "linux" PARENT_SCOPE)
     elseif(MACOS)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
@@ -895,7 +899,7 @@ macro(append_compiler_linker_sdk_setup)
     extend_gn_list(gnArgArg ARGS is_clang CONDITION CLANG)
     extend_gn_list(gnArgArg ARGS is_mingw CONDITION MINGW)
     extend_gn_list(gnArgArg ARGS is_msvc CONDITION MSVC)
-    extend_gn_list(gnArgArg ARGS is_gcc CONDITION LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
+    extend_gn_list(gnArgArg ARGS is_gcc CONDITION UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 
     if(CLANG)
         if(MACOS)
@@ -1331,7 +1335,7 @@ endfunction()
 
 function(check_for_ulimit)
     message("-- Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimitOutput
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimitOutput}")
@@ -1340,7 +1344,7 @@ function(check_for_ulimit)
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(" -- Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
