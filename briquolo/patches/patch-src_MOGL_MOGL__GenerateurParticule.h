$NetBSD: patch-src_MOGL_MOGL__GenerateurParticule.h,v 1.1 2012/06/13 22:54:58 othyro Exp $

Needs time_t type.

--- src/MOGL/MOGL_GenerateurParticule.h.orig	2006-03-07 20:31:24.000000000 +0000
+++ src/MOGL/MOGL_GenerateurParticule.h
@@ -23,6 +23,7 @@
 #define MOGL_GENERATEURPARTICULE
 
 #include <list>
+#include <sys/types.h>
 #include <sys/timeb.h>
 
 
