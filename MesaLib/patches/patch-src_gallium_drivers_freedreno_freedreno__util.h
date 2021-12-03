$NetBSD$

gettid() is linux-specific

--- src/gallium/drivers/freedreno/freedreno_util.h.orig	2021-12-01 19:04:14.000000000 +0000
+++ src/gallium/drivers/freedreno/freedreno_util.h
@@ -107,12 +107,21 @@ extern bool fd_binning_enabled;
 #include <unistd.h>
 #include <sys/types.h>
 
+#if defined(__linux__)
 #define DBG(fmt, ...)                                                          \
    do {                                                                        \
       if (FD_DBG(MSGS))                                                        \
          mesa_logi("%5d: %s:%d: " fmt, gettid(), __FUNCTION__, __LINE__,       \
                    ##__VA_ARGS__);                                             \
    } while (0)
+#else
+#define DBG(fmt, ...)                                                          \
+   do {                                                                        \
+      if (FD_DBG(MSGS))                                                        \
+         mesa_logi("%s:%d: " fmt, __FUNCTION__, __LINE__,                      \
+                   ##__VA_ARGS__);                                             \
+   } while (0)
+#endif
 
 #define perf_debug_message(debug, type, ...)                                   \
    do {                                                                        \
