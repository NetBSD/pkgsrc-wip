$NetBSD$

--- third_party/WebKit/Source/web/PopupMenuImpl.cpp.orig	2016-11-10 20:02:27.000000000 +0000
+++ third_party/WebKit/Source/web/PopupMenuImpl.cpp
@@ -156,7 +156,7 @@ public:
         , m_buffer(buffer)
     {
         DCHECK(m_buffer);
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
         // On other platforms, the <option> background color is the same as the
         // <select> background color. On Linux, that makes the <option>
         // background color very dark, so by default, try to use a lighter
