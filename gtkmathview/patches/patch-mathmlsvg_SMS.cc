$NetBSD: patch-mathmlsvg_SMS.cc,v 1.2 2015/02/11 12:03:53 nros Exp $
* strcpy needs cstring
--- mathmlsvg/SMS.cc.orig	2007-08-17 10:02:46.000000000 +0000
+++ mathmlsvg/SMS.cc
@@ -19,6 +19,7 @@
 #include <config.h>
 
 #include <sstream>
+#include <cstring>
 #include "defs.h"
 #include "AbstractLogger.hh"
 #include "ValueConversion.hh"
