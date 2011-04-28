$NetBSD: patch-base_third__party_symbolize_utilities.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/third_party/symbolize/utilities.h.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/third_party/symbolize/utilities.h
@@ -6,6 +6,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-typedef uint64_t uint64;
+#if __LP64__
+typedef unsigned long uint64;
+#else
+typedef unsigned long long uint64;
+#endif
 #define HAVE_SYMBOLIZE 1
 #define ATTRIBUTE_NOINLINE __attribute__ ((noinline))
