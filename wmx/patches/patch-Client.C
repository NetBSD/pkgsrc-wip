$NetBSD: patch-Client.C,v 1.2 2015/03/06 12:25:20 ishit Exp $

--- Client.C.orig	2014-11-16 19:34:19.000000000 +0000
+++ Client.C
@@ -6,9 +6,7 @@
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
 
-#if I18N
 #include <X11/Xmu/Atoms.h>
-#endif
 
 // needed this to be able to use CARD32
 #include <X11/Xmd.h>
