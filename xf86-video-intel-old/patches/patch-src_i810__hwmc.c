$NetBSD: patch-src_i810__hwmc.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i810_hwmc.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i810_hwmc.c
@@ -42,7 +42,6 @@ THE USE OR OTHER DEALINGS IN THE SOFTWAR
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "xf86PciInfo.h"
 #include "xf86Pci.h"
