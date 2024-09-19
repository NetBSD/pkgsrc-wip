$NetBSD$
* add netbsd support
--- loader/vk_loader_platform.h.orig	2020-12-01 20:50:08.000000000 +0000
+++ loader/vk_loader_platform.h
@@ -35,7 +35,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__NetBSD__)
 /* Linux-specific common code: */
 
 // Headers:
@@ -122,6 +122,23 @@ static inline char *loader_platform_exec
     buffer[ret] = '\0';
     return buffer;
 }
+#elif defined(__NetBSD__)
+#include <sys/sysctl.h>
+static inline char *loader_platform_executable_path(char *buffer, size_t size) {
+    int mib[4];
+    size_t len;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC_ARGS;
+    mib[2] = getpid();
+    mib[3] = KERN_PROC_PATHNAME;
+
+    if (sysctl(mib, 4, NULL, &len, NULL, 0)) return NULL;
+    if (len > size) return NULL;
+    if (sysctl(mib, 4, buffer, &len, NULL, 0)) return NULL;
+
+    return buffer;
+}
 #elif defined(__Fuchsia__)
 static inline char *loader_platform_executable_path(char *buffer, size_t size) { return NULL; }
 #endif  // defined (__APPLE__)
