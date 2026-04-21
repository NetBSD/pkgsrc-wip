$NetBSD$

Install libraries on all platforms.

--- cmake-proxies/cmake-modules/AudacityFunctions.cmake.orig	2026-04-21 08:01:54.004132443 +0000
+++ cmake-proxies/cmake-modules/AudacityFunctions.cmake
@@ -515,11 +515,9 @@ function( audacity_module_fn NAME SOURCE
             FOLDER "modules" # for IDE organization
       )
 
-      if( NOT CMAKE_SYSTEM_NAME MATCHES "Windows|Darwin" )
          set_target_property_all(${TARGET} INSTALL_RPATH "$ORIGIN:$ORIGIN/..")
          set_target_property_all(${TARGET} BUILD_RPATH "$ORIGIN:$ORIGIN/..")
          install( TARGETS ${TARGET} OPTIONAL DESTINATION ${_MODDIR} )
-      endif()
 
       fix_bundle( ${TARGET} )
    else()
@@ -530,11 +528,9 @@ function( audacity_module_fn NAME SOURCE
             FOLDER "libraries" # for IDE organization
       )
 
-      if( NOT CMAKE_SYSTEM_NAME MATCHES "Windows|Darwin" )
          set_target_property_all(${TARGET} INSTALL_RPATH "$ORIGIN")
          set_target_property_all(${TARGET} BUILD_RPATH "$ORIGIN")
          install(TARGETS ${TARGET} DESTINATION ${_PKGLIB} )
-      endif()
    endif()
 
    export_symbol_define( export_symbol "${TARGET}" )
@@ -832,9 +828,7 @@ function(make_interface_library
 endfunction()
 
 function(fix_bundle target_name)
-   if (NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
       return()
-   endif()
 
    add_custom_command(
       TARGET ${target_name}
