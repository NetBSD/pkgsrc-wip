$NetBSD: patch-src_util_timer.cc,v 1.1 2013/01/20 22:12:46 othyro Exp $

Needs strlen.

--- src/util/timer.cc.orig	2008-01-20 05:28:15.000000000 +0000
+++ src/util/timer.cc
@@ -12,6 +12,7 @@
  *	   apr 2007: even simpler
  */
 
+#include <string.h>
 #include "autoconf.h"
 #include "util/timer.h"
 #include "debug.h"
