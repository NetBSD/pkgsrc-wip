$NetBSD$

--- src/rxkad/fcrypt.c.orig	2018-05-07 18:33:27.000000000 +0000
+++ src/rxkad/fcrypt.c
@@ -16,7 +16,6 @@
 #include <afs/param.h>
 #include <afs/stds.h>
 
-#define DEBUG 0
 #ifdef KERNEL
 #ifndef UKERNEL
 #if defined(AFS_AIX_ENV) || defined(AFS_AUX_ENV) || defined(AFS_SUN5_ENV)
