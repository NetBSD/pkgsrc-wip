$NetBSD$

--- src/DialogInputValue.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ src/DialogInputValue.cpp
@@ -26,6 +26,22 @@ along with this program.  If not, see <h
 
 #include "ui_DialogInputValue.h"
 
+#if !defined(LONG_LONG_MIN)
+#define LONG_LONG_MIN LLONG_MIN
+#endif
+
+#if !defined(LONG_LONG_MAX)
+#define LONG_LONG_MAX LLONG_MAX
+#endif
+
+#if !defined(ULONG_LONG_MIN)
+#define ULONG_LONG_MIN ULLONG_MIN
+#endif
+
+#if !defined(ULONG_LONG_MAX)
+#define ULONG_LONG_MAX ULLONG_MAX
+#endif
+
 //------------------------------------------------------------------------------
 // Name: DialogInputValue
 // Desc:
