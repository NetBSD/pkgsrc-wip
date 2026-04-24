$NetBSD$

Undefine X11 macros that conflict with enum values.
X11/X.h defines Below=1 and Above=0, which breaks ReflectionDirection enum.
Must be in this file directly due to #pragma once preventing re-inclusion
of RenderStyleConstants.h after X11 headers are included.

--- Source/WebCore/style/values/non-standard/StyleWebKitBoxReflect.h.orig	2026-02-23 14:40:55.954298000 +0000
+++ Source/WebCore/style/values/non-standard/StyleWebKitBoxReflect.h
@@ -29,6 +29,12 @@
 #include <WebCore/StyleLengthWrapper.h>
 #include <WebCore/StyleMaskBorder.h>
 
+// X11/X.h defines Below=1 and Above=0, conflicting with ReflectionDirection enum
+#ifdef Below
+#undef Below
+#undef Above
+#endif
+
 namespace WebCore {
 namespace Style {
 
