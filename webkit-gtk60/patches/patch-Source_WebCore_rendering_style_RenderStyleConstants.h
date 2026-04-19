$NetBSD$

Undefine X11 macros that conflict with enum values.
X11/X.h defines Below=1 and Above=0, which breaks ReflectionDirection enum.

--- Source/WebCore/rendering/style/RenderStyleConstants.h.orig	2026-04-19 05:54:19.072594406 +0000
+++ Source/WebCore/rendering/style/RenderStyleConstants.h
@@ -33,6 +33,12 @@
 #include <wtf/EnumSet.h>
 #include <wtf/EnumTraits.h>
 
+// X11/X.h defines these as numeric constants, conflicting with our enum values
+#ifdef Below
+#undef Below
+#undef Above
+#endif
+
 namespace WTF {
 class TextStream;
 }
