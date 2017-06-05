$NetBSD$

* Use pkgsrc lua interpreter instead of builtin one
* Change awesomerc.lua with awesomerc.lua.in since pkgsrc does not allow cmake
  out-of-source building

--- awesomeConfig.cmake.orig	2017-03-18 09:49:46.000000000 +0000
+++ awesomeConfig.cmake
@@ -394,7 +394,7 @@ file(MAKE_DIRECTORY ${BUILD_DIR}/script_
 
 add_custom_command(
         OUTPUT ${BUILD_DIR}/docs/06-appearance.md
-        COMMAND lua ${SOURCE_DIR}/docs/06-appearance.md.lua
+        COMMAND ${LUA_EXECUTABLE} ${SOURCE_DIR}/docs/06-appearance.md.lua
         ${BUILD_DIR}/docs/06-appearance.md
         DEPENDS lgi-check
 )
@@ -402,15 +402,15 @@ add_custom_command(
 add_custom_command(
         OUTPUT ${BUILD_DIR}/awesomerc.lua ${BUILD_DIR}/docs/05-awesomerc.md
             ${BUILD_DIR}/script_files/rc.lua
-        COMMAND lua ${SOURCE_DIR}/docs/05-awesomerc.md.lua
-        ${BUILD_DIR}/docs/05-awesomerc.md ${SOURCE_DIR}/awesomerc.lua
+        COMMAND ${LUA_EXECUTABLE} ${SOURCE_DIR}/docs/05-awesomerc.md.lua
+        ${BUILD_DIR}/docs/05-awesomerc.md ${SOURCE_DIR}/awesomerc.lua.in
         ${BUILD_DIR}/awesomerc.lua
         ${BUILD_DIR}/script_files/rc.lua
 )
 
 add_custom_command(
         OUTPUT ${BUILD_DIR}/script_files/theme.lua
-        COMMAND lua ${SOURCE_DIR}/docs/sample_theme.lua ${BUILD_DIR}/script_files/
+        COMMAND ${LUA_EXECUTABLE} ${SOURCE_DIR}/docs/sample_theme.lua ${BUILD_DIR}/script_files/
 )
 
 # Create a target for the auto-generated awesomerc.lua and other files
@@ -418,12 +418,12 @@ add_custom_target(generate_awesomerc DEP
     ${BUILD_DIR}/awesomerc.lua
     ${BUILD_DIR}/script_files/theme.lua
     ${BUILD_DIR}/script_files/rc.lua
-    ${SOURCE_DIR}/awesomerc.lua
+    ${SOURCE_DIR}/awesomerc.lua.in
     ${BUILD_DIR}/docs/06-appearance.md
     ${SOURCE_DIR}/docs/05-awesomerc.md.lua
     ${SOURCE_DIR}/docs/sample_theme.lua
     ${SOURCE_DIR}/docs/sample_files.lua
-    ${SOURCE_DIR}/awesomerc.lua
+    ${SOURCE_DIR}/awesomerc.lua.in
 )
 
 
