$NetBSD: patch-libgcc_crtstuff.c,v 1.2 2014/05/29 07:11:47 keckhardt Exp $

--- libgcc/crtstuff.c.orig	2014-05-21 11:08:58.000000000 +0000
+++ libgcc/crtstuff.c
@@ -80,7 +80,8 @@ call_ ## FUNC (void)					\
 #endif
 
 #if defined(TARGET_DL_ITERATE_PHDR) && \
-   (defined(__DragonFly__) || defined(__FreeBSD__))
+   (defined(__DragonFly__) || defined(__FreeBSD__)) \
+   (defined(__NetBSD__) || defined(__OpenBSD__))
 #define BSD_DL_ITERATE_PHDR_AVAILABLE
 #endif
  
