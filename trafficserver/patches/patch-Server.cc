$NetBSD$

- Handle accept filter and module load in NetBSD

diff --git src/iocore/net/Server.cc src/iocore/net/Server.cc
index 32a8c0f7ae..d2c53c3314 100644
--- src/iocore/net/Server.cc
+++ src/iocore/net/Server.cc
@@ -46,8 +46,14 @@
 
 #ifdef SO_ACCEPTFILTER
 #include <sys/param.h>
+#if defined(__NetBSD__)
+extern "C" {
+#include <sys/module.h>
+}
+#else
 #include <sys/linker.h>
 #endif
+#endif
 
 namespace
 {
@@ -361,6 +367,22 @@ Server::setup_fd_after_listen([[maybe_unused]] const NetProcessor::AcceptOptions
 #ifdef SO_ACCEPTFILTER
   // SO_ACCEPTFILTER needs to be set **after** listen
   if (opt.defer_accept > 0) {
+#if defined(__NetBSD__)
+    modctl_load_t args = {
+      .ml_filename = "accf_dataready",
+      .ml_flags = MODCTL_NO_PROP,
+      .ml_props = NULL,
+      .ml_propslen = 0
+    };
+
+    if (modctl(MODCTL_LOAD, &args) != 0 && errno != EEXIST) {
+      if (errno == ENOENT) {
+        Error("[Server::listen] Ignored defer_accept config. Because accf_data module is missing errno=%d", errno);
+        } else {
+        Error("[Server::listen] Ignored defer_accept config. Because accf_data module cannot loaded errno=%d", errno);
+      }
+      return -errno;
+#else
     int file_id = kldfind("accf_data");
 
     struct kld_file_stat stat;
@@ -369,6 +391,7 @@ Server::setup_fd_after_listen([[maybe_unused]] const NetProcessor::AcceptOptions
     if (kldstat(file_id, &stat) < 0) {
       Error("[Server::listen] Ignored defer_accept config. Because accf_data module is not loaded errno=%d", errno);
     } else {
+#endif
       struct accept_filter_arg afa;
 
       bzero(&afa, sizeof(afa));
