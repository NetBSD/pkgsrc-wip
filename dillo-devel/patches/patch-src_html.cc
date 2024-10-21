$NetBSD$

Use static_assert only with compilers that support at least C++11.

--- src/html.cc.orig	2024-06-07 23:32:23.000000000 +0000
+++ src/html.cc
@@ -3555,8 +3555,13 @@ static const TagInfo Tags[] = {
 };
 #define NTAGS (sizeof(Tags)/sizeof(Tags[0]))
 
+#if (__cplusplus >= 201103L)
+// Requires C++11
 static_assert(NTAGS == HTML_NTAGS,
    "Mismatch between number of tags in Tags and HTML_NTAGS");
+#else
+# warning static_assert disabled (requires at least C++11)
+#endif
 
 /*
  * Compares tag from buffer ('/' or '>' or space-ended string) [p1]
