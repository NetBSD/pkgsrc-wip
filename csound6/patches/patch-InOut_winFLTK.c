$NetBSD$

Add NetBSD and DragonFlyBSD support.

--- InOut/winFLTK.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ InOut/winFLTK.c
@@ -29,7 +29,7 @@
 #include <stdio.h>
 #include "cwindow.h"
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <X11/Xlib.h>
 #endif
 
@@ -83,7 +83,7 @@ PUBLIC int csoundModuleInit(CSOUND *csou
     fltkFlags = getFLTKFlagsPtr(csound);
     if (((*fltkFlags) & 2) == 0 &&
         !(oparms.graphsoff || oparms.postscript)) {
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       Display *dpy = XOpenDisplay(NULL);
       if (dpy != NULL) {
         XCloseDisplay(dpy);
@@ -104,7 +104,7 @@ PUBLIC int csoundModuleInit(CSOUND *csou
           csound->Message(csound, "graph init...\n");
 
         }
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       }
 #endif
     }
