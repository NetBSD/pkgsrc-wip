$NetBSD$

--- gum/gumdefs.h.orig	2018-03-12 19:53:33.000000000 +0000
+++ gum/gumdefs.h
@@ -65,7 +65,8 @@ enum _GumOS
   GUM_OS_LINUX,
   GUM_OS_IOS,
   GUM_OS_ANDROID,
-  GUM_OS_QNX
+  GUM_OS_QNX,
+  GUM_OS_NETBSD
 };
 
 enum _GumCallingConvention
