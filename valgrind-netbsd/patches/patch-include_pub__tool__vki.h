$NetBSD$

--- include/pub_tool_vki.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_vki.h
@@ -52,6 +52,8 @@
 #  include "vki/vki-darwin.h"
 #elif defined(VGO_solaris)
 #  include "vki/vki-solaris.h"
+#elif defined(VGO_netbsd)
+#  include "vki/vki-netbsd.h"
 #else
 #  error Unknown Plat/OS
 #endif
