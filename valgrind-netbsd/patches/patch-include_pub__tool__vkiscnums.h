$NetBSD$

--- include/pub_tool_vkiscnums.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_vkiscnums.h
@@ -46,6 +46,11 @@ extern const HChar *VG_(sysnum_string) (
 // Macro provided for backward compatibility purposes.
 #define VG_SYSNUM_STRING(sysnum) VG_(sysnum_string)(sysnum)
 
+#if defined(VGO_netbsd)
+   // See the NetBSD-specific case in pub_tool_vkiscnums_asm.h for an
+   // explanation of why we include this here rather than there.
+#  include "vki/vki-scnums-netbsd.h"
+#endif
 
 #endif   // __PUB_TOOL_VKISCNUMS_H
 
