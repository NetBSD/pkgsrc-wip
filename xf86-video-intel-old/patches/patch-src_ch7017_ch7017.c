$NetBSD: patch-src_ch7017_ch7017.c,v 1.3 2013/05/29 13:59:38 makoto Exp $

--- src/ch7017/ch7017.c.orig	2009-04-08 23:59:47.000000000 +0000
+++ src/ch7017/ch7017.c
@@ -34,7 +34,6 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "miscstruct.h"
 #include "xf86i2c.h"
