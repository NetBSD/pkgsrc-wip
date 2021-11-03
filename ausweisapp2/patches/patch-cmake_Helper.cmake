$NetBSD$

Don't build a .app just because we're on macOS.

--- cmake/Helper.cmake.orig	2021-03-31 09:24:50.000000000 +0000
+++ cmake/Helper.cmake
@@ -289,6 +289,10 @@ if(APPLE AND NOT IOS)
 	set(MAC true)
 endif()
 
+if(FALSE AND MAC)
+	set(MACAPP true)
+endif()
+
 if(UNIX AND NOT ANDROID AND NOT APPLE AND NOT CYGWIN AND NOT BSD)
 	set(LINUX true)
 endif()
