$NetBSD: patch-src_i915__hwmc.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/i915_hwmc.c.orig	2009-04-08 23:59:48.000000000 +0000
+++ src/i915_hwmc.c
@@ -32,7 +32,6 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "xf86PciInfo.h"
 #include "xf86Pci.h"
