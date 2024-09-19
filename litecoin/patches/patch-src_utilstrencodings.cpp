$NetBSD$

--- src/utilstrencodings.cpp.orig	2015-06-15 08:51:30.000000000 +0000
+++ src/utilstrencodings.cpp
@@ -12,6 +12,11 @@
 #include <errno.h>
 #include <limits>
 
+#if defined __FreeBSD__
+#include <stdlib.h>
+#include <stdio.h>
+#endif
+
 using namespace std;
 
 string SanitizeString(const string& str)
