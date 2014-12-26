$NetBSD: patch-mathmlsvg_SMS.cc,v 1.1 2014/12/26 21:16:29 nros Exp $
* strcpy needs string.h
--- mathmlsvg/SMS.cc.orig	2007-08-17 10:02:46.000000000 +0000
+++ mathmlsvg/SMS.cc
@@ -19,6 +19,7 @@
 #include <config.h>
 
 #include <sstream>
+#include <string.h>
 #include "defs.h"
 #include "AbstractLogger.hh"
 #include "ValueConversion.hh"
