$NetBSD$

--- Telegram/cmake/lib_tgvoip.cmake.orig	2021-02-27 21:54:57.279016770 +0000
+++ Telegram/cmake/lib_tgvoip.cmake
@@ -179,7 +179,7 @@ if (NOT TGVOIP_FOUND)
         desktop-app::external_opus
     )
 
-    if (LINUX)
+    if (LINUX AND NOT (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD|NetBSD|DragonFly"))
         find_package(PkgConfig REQUIRED)
         find_package(ALSA REQUIRED)
         pkg_check_modules(PULSE REQUIRED libpulse)
