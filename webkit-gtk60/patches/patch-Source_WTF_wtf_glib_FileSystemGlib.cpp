$NetBSD$

The file name link has a different name in NetBSD's procfs than on Linux.
Avoid providing zero-length paths.
https://github.com/WebKit/WebKit/pull/64201

--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2026-04-23 20:09:38.532658486 +0000
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -89,12 +89,21 @@ CString currentExecutablePath()
         return { };
     return CString(unsafeMakeSpan(readBuffer, static_cast<size_t>(result)));
 }
+#elif OS(NETBSD)
+CString currentExecutablePath()
+{
+    static char readLinkBuffer[PATH_MAX];
+    ssize_t result = readlink("/proc/curproc/exe", readLinkBuffer, PATH_MAX);
+    if (result <= 0)
+        return { };
+    return CString(unsafeMakeSpan(readLinkBuffer, static_cast<size_t>(result)));
+}
 #elif OS(UNIX)
 CString currentExecutablePath()
 {
     static char readLinkBuffer[PATH_MAX];
     ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
-    if (result == -1)
+    if (result <= 0)
         return { };
     return CString(unsafeMakeSpan(readLinkBuffer, static_cast<size_t>(result)));
 }
