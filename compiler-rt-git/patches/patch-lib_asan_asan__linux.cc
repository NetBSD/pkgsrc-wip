$NetBSD$

--- lib/asan/asan_linux.cc.orig	2017-08-05 14:29:08.000000000 +0000
+++ lib/asan/asan_linux.cc
@@ -13,7 +13,7 @@
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "asan_interceptors.h"
 #include "asan_internal.h"
@@ -42,6 +42,10 @@
 #if SANITIZER_ANDROID || SANITIZER_FREEBSD
 #include <ucontext.h>
 extern "C" void* _DYNAMIC;
+#elif SANITIZER_NETBSD
+#include <link_elf.h>
+#include <ucontext.h>
+extern Elf_Dyn _DYNAMIC;
 #else
 #include <sys/ucontext.h>
 #include <link.h>
@@ -101,6 +105,15 @@ static int FindFirstDSOCallback(struct d
   if (internal_strncmp(info->dlpi_name, "linux-", sizeof("linux-") - 1) == 0)
     return 0;
 
+#if SANITIZER_NETBSD
+  // Ignore first entry (the main program)
+  char **p = (char **)data;
+  if (*p == NULL) {
+    *p = (char *)-1;
+    return 0;
+  }
+#endif
+
   *(const char **)data = info->dlpi_name;
   return 1;
 }
@@ -179,4 +192,4 @@ void *AsanDlSymNext(const char *sym) {
 
 } // namespace __asan
 
-#endif // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
