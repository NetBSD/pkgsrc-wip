$NetBSD: patch-lang_LangPrimSource_PyrSched.cpp,v 1.1 2014/09/06 22:22:36 thomasklausner Exp $

Add missing header for strerror().

--- lang/LangPrimSource/PyrSched.cpp.orig	2013-11-27 12:54:02.000000000 +0000
+++ lang/LangPrimSource/PyrSched.cpp
@@ -29,6 +29,7 @@
 #endif
 #include <stdarg.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include <limits>
 
