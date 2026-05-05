$NetBSD$

The file name link has a different name in NetBSD's procfs than on Linux.
Avoid providing zero-length paths.
https://github.com/WebKit/WebKit/pull/64201

--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2026-04-02 11:17:43.701464400 +0000
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -65,7 +65,7 @@ CString currentExecutablePath()
 {
     static char readLinkBuffer[PATH_MAX];
     ssize_t result = readlink("/proc/self/exe", readLinkBuffer, PATH_MAX);
-    if (result == -1)
+    if (result <= 0)
         return { };
 WTF_ALLOW_UNSAFE_BUFFER_USAGE_BEGIN // Linux port
     return CString(std::span { readLinkBuffer, static_cast<size_t>(result) });
@@ -85,16 +85,21 @@ CString currentExecutablePath()
     int selfFd = open("/proc/self/exefile", O_RDONLY);
     ssize_t result = read(selfFd, readBuffer, sizeof(readBuffer));
     close(selfFd);
-    if (result == -1)
+    if (result <= 0)
         return { };
     return CString(unsafeMakeSpan(readBuffer, static_cast<size_t>(result)));
 }
 #elif OS(UNIX)
+#if OS(NETBSD)
+#define _PROC_CURPROC_PATH "/proc/curproc/exe"
+#else
+#define _PROC_CURPROC_PATH "/proc/curproc/file"
+#endif
 CString currentExecutablePath()
 {
     static char readLinkBuffer[PATH_MAX];
-    ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
-    if (result == -1)
+    ssize_t result = readlink(_PROC_CURPROC_PATH, readLinkBuffer, PATH_MAX);
+    if (result <= 0)
         return { };
     return CString(unsafeMakeSpan(readLinkBuffer, static_cast<size_t>(result)));
 }
