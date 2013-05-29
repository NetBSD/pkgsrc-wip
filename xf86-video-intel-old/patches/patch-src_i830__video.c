$NetBSD: patch-src_i830__video.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i830_video.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830_video.c
@@ -57,7 +57,6 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "xf86PciInfo.h"
 #include "xf86Pci.h"
