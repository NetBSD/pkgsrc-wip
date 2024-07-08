$NetBSD$

Fix headers.

--- src/m_strings.h.orig	2024-07-04 06:00:57.000000000 +0000
+++ src/m_strings.h
@@ -23,7 +23,9 @@
 
 #include "PrintfMacros.h"
 
-#include <string.h>
+#include <cstdarg>
+#include <cstdio>
+#include <cstring>
 
 #include <ostream>
 #include <string>
