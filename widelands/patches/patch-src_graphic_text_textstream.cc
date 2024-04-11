$NetBSD$

Replace isspace() on NetBSD, else it breaks UTF-8 handling.

--- src/graphic/text/textstream.cc.orig	2024-04-11 05:38:21.326518028 +0000
+++ src/graphic/text/textstream.cc
@@ -21,6 +21,15 @@
 #include "base/string.h"
 #include "graphic/text/rt_errors_impl.h"
 
+#ifdef __NetBSD__
+static int isspace_override(int c) {
+	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
+		return 1;
+	return 0;
+}
+#define isspace(c) isspace_override(c)
+#endif
+
 namespace RT {
 
 struct EndOfTextImpl : public EndOfText {
