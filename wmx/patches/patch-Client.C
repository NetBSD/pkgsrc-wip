$NetBSD: patch-Client.C,v 1.1.1.1 2011/05/05 13:07:00 ishit Exp $

--- Client.C.orig	2009-01-09 11:18:03.000000000 +0000
+++ Client.C
@@ -6,9 +6,7 @@
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
 
-#if I18N
 #include <X11/Xmu/Atoms.h>
-#endif
 
 // needed this to be able to use CARD32
 #include <X11/Xmd.h>
