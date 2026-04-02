$NetBSD$

Fix build

webkitgtk-2.46.3/Source/WTF/wtf/glib/FileSystemGlib.cpp: In function 'WTF::CString WTF::FileSystemImpl::currentExecutablePath()':
webkitgtk-2.46.3/Source/WTF/wtf/glib/FileSystemGlib.cpp:83:42: error: no matching function for call to 'WTF::CString::CString(char [1024], ssize_t&)'
   83 |     return CString(readLinkBuffer, result);
      |                                          ^


--- Source/WTF/wtf/glib/FileSystemGlib.cpp.orig	2026-02-23 14:40:54.578305500 +0000
+++ Source/WTF/wtf/glib/FileSystemGlib.cpp
@@ -96,7 +96,7 @@ CString currentExecutablePath()
     ssize_t result = readlink("/proc/curproc/file", readLinkBuffer, PATH_MAX);
     if (result == -1)
         return { };
-    return CString(readLinkBuffer, result);
+    return CString(unsafeMakeSpan(readLinkBuffer, static_cast<size_t>(result)));
 }
 #elif OS(WINDOWS)
 CString currentExecutablePath()
