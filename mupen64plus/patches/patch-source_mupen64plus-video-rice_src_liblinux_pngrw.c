$NetBSD: patch-source_mupen64plus-video-rice_src_liblinux_pngrw.c,v 1.1 2013/07/06 23:00:15 othyro Exp $

Fixes incompatible implicit declaration of memcpy.

--- source/mupen64plus-video-rice/src/liblinux/pngrw.c.orig	2013-07-04 00:28:10.000000000 +0000
+++ source/mupen64plus-video-rice/src/liblinux/pngrw.c
@@ -29,6 +29,7 @@
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #ifdef _BMG_LIBPNG_STANDALONE
 #include "BMGLibPNG.h"
 #else
