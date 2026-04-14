$NetBSD$

In file included from /usr/pkg/include/X11/Xlib.h:44,
                 from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebCore/platform/graphics/skia/PlatformDisplaySkia.cpp:42,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/WebCore/DerivedSources/unified-sources/UnifiedSource-3c72abbe-66.cpp:5:
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/SharedMemory.h:57:27: error: expected identifier before numeric constant
   57 | enum class MemoryLedger { None, Default, Network, Media, Graphics, Neural };
      |                           ^~~~


--- Source/WebCore/platform/SharedMemory.h.orig	2026-04-14 14:21:20.585631982 +0000
+++ Source/WebCore/platform/SharedMemory.h
@@ -54,6 +54,10 @@ class SharedBuffer;
 class ProcessIdentity;
 class SharedBuffer;
 
+#ifdef None
+#undef None
+#endif
+
 enum class MemoryLedger { None, Default, Network, Media, Graphics, Neural };
 enum class SharedMemoryProtection : bool { ReadOnly, ReadWrite };
 
