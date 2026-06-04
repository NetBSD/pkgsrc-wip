$NetBSD$

[Swift GTK] Undefined Success
https://bugs.webkit.org/show_bug.cgi?id=314395

Reviewed by Adrian Perez de Castro.

The X11 header defines Success. This causes difficulty when this header is
transitively included in some Swift/C++ import scenarios, since the definition
of Success causes problems interpreting the 'Success' case of other enums
across the codebase. Undefine Success since we don't currently need it.

Additional ones in
https://github.com/WebKit/WebKit/pull/64743

--- Source/WebCore/platform/graphics/x11/XErrorTrapper.h.orig	2026-05-17 18:13:35.817512800 +0000
+++ Source/WebCore/platform/graphics/x11/XErrorTrapper.h
@@ -27,8 +27,20 @@
 
 #if PLATFORM(X11)
 #include <X11/Xlib.h>
+#ifdef Above
+#undef Above
+#endif
+#ifdef Always
+#undef Always
+#endif
+#ifdef Below
+#undef Below
+#endif
 #ifdef Success
 #undef Success
+#endif
+#ifdef True
+#undef True
 #endif
 #include <wtf/Vector.h>
 
