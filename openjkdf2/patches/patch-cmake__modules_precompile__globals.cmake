$NetBSD$

* Use the correct "cog" command.

--- cmake_modules/precompile_globals.cmake.orig	2023-06-09 06:59:18.000000000 +0000
+++ cmake_modules/precompile_globals.cmake
@@ -8,13 +8,13 @@ list(APPEND SOURCE_FILES ${GLOBALS_C})
 # All of our pre-build steps
 add_custom_command(
     OUTPUT ${GLOBALS_C}
-    COMMAND cog -d -D symbols_fpath="${SYMBOLS_FILE}" -D project_root="${PROJECT_SOURCE_DIR}" -o ${GLOBALS_C} ${GLOBALS_C_COG}
+    COMMAND cog-${PYVERSSUFFIX} -d -D symbols_fpath="${SYMBOLS_FILE}" -D project_root="${PROJECT_SOURCE_DIR}" -o ${GLOBALS_C} ${GLOBALS_C_COG}
     DEPENDS ${SYMBOLS_FILE} ${GLOBALS_C_COG} ${GLOBALS_H} ${PROJECT_SOURCE_DIR}/resource/shaders/default_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/default_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/menu_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/menu_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/texfbo_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/texfbo_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/blur_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/blur_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ssao_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ssao_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ssao_mix_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ssao_mix_v.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ui_f.glsl ${PROJECT_SOURCE_DIR}/resource/shaders/ui_v.glsl ${PROJECT_SOURCE_DIR}/resource/ssl/cacert.pem ${PROJECT_SOURCE_DIR}/resource/ui/openjkdf2.uni  ${PROJECT_SOURCE_DIR}/resource/ui/openjkdf2_i8n.uni
 )
 
 add_custom_command(
     OUTPUT ${GLOBALS_H}
-    COMMAND cog -d -D symbols_fpath="${SYMBOLS_FILE}" -D project_root="${PROJECT_SOURCE_DIR}" -o ${GLOBALS_H} ${GLOBALS_H_COG}
+    COMMAND cog-${PYVERSSUFFIX} -d -D symbols_fpath="${SYMBOLS_FILE}" -D project_root="${PROJECT_SOURCE_DIR}" -o ${GLOBALS_H} ${GLOBALS_H_COG}
     DEPENDS ${SYMBOLS_FILE} ${GLOBALS_H_COG}
 )
 
@@ -22,4 +22,4 @@ add_custom_command(
     PRE_BUILD
     OUTPUT ${BIN_NAME}
     DEPENDS ${GLOBALS_C} ${GLOBALS_H}
-)
\ No newline at end of file
+)
