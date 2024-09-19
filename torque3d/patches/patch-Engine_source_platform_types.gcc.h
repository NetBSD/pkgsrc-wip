$NetBSD$

--- Engine/source/platform/types.gcc.h.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/source/platform/types.gcc.h
@@ -99,6 +99,13 @@ typedef unsigned long  U64;
 #  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
 #  include "platform/types.posix.h"
 
+#elif defined(__NetBSD__)
+#  define TORQUE_OS_STRING "NetBSD"
+#  define TORQUE_OS_NETBSD
+#  define TORQUE_SUPPORTS_NASM
+#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
+#  include "platform/types.posix.h"
+
 #elif defined(__APPLE__)
 #  define TORQUE_OS_STRING "MacOS X"
 #  define TORQUE_OS_MAC
@@ -176,4 +183,3 @@ typedef unsigned long  U64;
 #endif
 
 #endif // INCLUDED_TYPES_GCC_H
-
