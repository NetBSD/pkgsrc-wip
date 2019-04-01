$NetBSD$

--- include/pub_tool_vkiscnums_asm.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_vkiscnums_asm.h
@@ -66,6 +66,9 @@
 #elif defined(VGP_x86_solaris) || (VGP_amd64_solaris)
 #  include "vki/vki-scnums-solaris.h"
 
+#elif defined(VGP_amd64_netbsd)
+#  include "vki/vki-scnums-netbsd.h"
+
 #else
 #  error Unknown platform
 #endif
