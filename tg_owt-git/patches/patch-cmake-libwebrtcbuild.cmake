$NetBSD$

--- cmake/libwebrtcbuild.cmake.orig	2021-02-03 11:42:41.000000000 +0000
+++ cmake/libwebrtcbuild.cmake
@@ -4,7 +4,6 @@ add_library(tg_owt::libwebrtcbuild ALIAS
 target_link_libraries(libwebrtcbuild
 INTERFACE
     tg_owt::libabsl
-    tg_owt::libyuv
 )
 
 target_compile_definitions(libwebrtcbuild
@@ -34,6 +33,11 @@ elseif (APPLE)
         WEBRTC_POSIX
         WEBRTC_MAC
     )
+elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD|NetBSD|DragonFly")
+    target_compile_definitions(libwebrtcbuild
+    INTERFACE
+        WEBRTC_POSIX
+    )
 else()
     target_compile_definitions(libwebrtcbuild
     INTERFACE
