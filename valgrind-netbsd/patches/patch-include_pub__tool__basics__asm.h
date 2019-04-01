$NetBSD$

--- include/pub_tool_basics_asm.h.orig	2018-05-05 07:42:22.000000000 +0000
+++ include/pub_tool_basics_asm.h
@@ -48,7 +48,7 @@
 
 #define VGAPPEND(str1,str2) str1##str2
  
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
 #  define VG_(str)    VGAPPEND( vgPlain_,          str)
 #  define ML_(str)    VGAPPEND( vgModuleLocal_,    str)
 #elif defined(VGO_darwin)
