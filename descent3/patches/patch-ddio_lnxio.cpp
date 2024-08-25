$NetBSD$

Support *BSD.

--- ddio/lnxio.cpp.orig	2024-08-18 20:19:29.228315892 +0000
+++ ddio/lnxio.cpp
@@ -123,6 +123,15 @@ bool ddio_GetBinaryPath(char *exec_path,
    perror("realpath");
    return false;
   }
+#elif defined(__FreeBSD__)
+  perror("realpath");
+  return false;
+#elif defined(__NetBSD__)
+  perror("realpath");
+  return false;
+#elif defined(__OpenBSD__)
+  perror("realpath");
+  return false;
 #else
   if (GetModuleFileName(NULL, exec_path, len) == 0) {
   DWORD error = GetLastError();
