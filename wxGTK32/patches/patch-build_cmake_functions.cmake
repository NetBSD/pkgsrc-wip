$NetBSD$

Disable pre-compiled headers, don't generally work.

--- build/cmake/functions.cmake.orig	2022-07-06 14:19:50.000000000 +0000
+++ build/cmake/functions.cmake
@@ -436,7 +436,6 @@ macro(wx_add_library name)
             RUNTIME DESTINATION "${runtime_dir}${GEN_EXPR_DIR}${wxPLATFORM_LIB_DIR}"
             BUNDLE DESTINATION Applications/wxWidgets
             )
-        wx_target_enable_precomp(${name} "${wxSOURCE_DIR}/include/wx/wxprec.h")
     endif()
 endmacro()
 
@@ -865,7 +864,6 @@ function(wx_add name group)
         set(APP_FOLDER ${group})
     endif()
     wx_set_common_target_properties(${target_name})
-    wx_target_enable_precomp(${target_name} "${wxSOURCE_DIR}/include/wx/wxprec.h")
     set_target_properties(${target_name} PROPERTIES
         FOLDER ${APP_FOLDER}
         )
