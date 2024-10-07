$NetBSD$

--- include/platform.hpp.orig	2024-10-06 12:13:54 UTC
+++ include/platform.hpp
@@ -35,6 +35,10 @@
 		#define OS_WINDOWS
 	#endif
 
+// FIXME: __GNUC__ is defined under clang as well, but using OS_LINUX
+// for all Unix variants encourages developers to assume linuxisms
+// where they won't work.  Maybe define OS_UNIX for portable code
+// and just use OS_LINUX for linux-specific code.
 #elif defined( __GNUC__ )
 
 	#if ! defined( OS_LINUX )
