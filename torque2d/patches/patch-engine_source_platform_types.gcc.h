$NetBSD$

--- engine/source/platform/types.gcc.h.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platform/types.gcc.h
@@ -91,6 +91,13 @@ typedef unsigned long long  U64;
 #  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
 #  include "platform/types.posix.h"
 
+#elif defined(__NetBSD__)
+#  define TORQUE_OS_STRING "NetBSD"
+#  define TORQUE_OS_NETBSD
+#  define TORQUE_SUPPORTS_NASM
+#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
+#  include "platform/types.posix.h"
+
 #elif defined(TORQUE_OS_IOS)
 	#ifndef TORQUE_OS_IOS
 		#define TORQUE_OS_IOS
