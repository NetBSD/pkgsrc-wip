$NetBSD: patch-src_i810__video.c,v 1.1 2013/05/25 13:09:48 thomasklausner Exp $

--- src/i810_video.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i810_video.c
@@ -42,7 +42,6 @@ THE USE OR OTHER DEALINGS IN THE SOFTWAR
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "xf86PciInfo.h"
 #include "xf86Pci.h"
