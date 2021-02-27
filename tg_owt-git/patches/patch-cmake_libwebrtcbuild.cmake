$NetBSD$

--- cmake/libwebrtcbuild.cmake.orig	2021-02-25 16:19:56.688047871 +0000
+++ cmake/libwebrtcbuild.cmake
@@ -34,6 +34,11 @@ elseif (APPLE)
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
