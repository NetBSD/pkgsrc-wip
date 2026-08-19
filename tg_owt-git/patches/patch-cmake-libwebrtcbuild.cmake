$NetBSD$

Define WEBRTC_NETBSD for NetBSD builds (same as FreeBSD/OpenBSD).

--- cmake/libwebrtcbuild.cmake.orig
+++ cmake/libwebrtcbuild.cmake
@@ -106,6 +106,11 @@
         INTERFACE
             WEBRTC_OPENBSD
         )
+    elseif (CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
+        target_compile_definitions(libwebrtcbuild
+        INTERFACE
+            WEBRTC_NETBSD
+        )
     endif()
 endif()
 
