$NetBSD: patch-Duplo.cpp,v 1.1 2013/01/29 12:49:33 jihbed Exp $

--- Duplo.cpp.orig	2013-01-29 12:43:18.000000000 +0000
+++ Duplo.cpp	2013-01-29 12:43:36.000000000 +0000
@@ -18,6 +18,7 @@
 
 #include <fstream>
 #include <time.h>
+#include <string.h>
 
 #include "SourceFile.h"
 #include "SourceLine.h"
