$NetBSD$

- kldfind is only on FreeBSD
- Todo: Add logic for NetBSD

diff --git src/iocore/net/Server.cc src/iocore/net/Server.cc
index 32a8c0f7ae..ae4e955f6c 100644
--- src/iocore/net/Server.cc
+++ src/iocore/net/Server.cc
@@ -44,10 +44,13 @@
 #include <hwloc.h>
 #endif
 
+#undef SO_ACCEPTFILTER
 #ifdef SO_ACCEPTFILTER
 #include <sys/param.h>
+#if !defined(__NetBSD__)
 #include <sys/linker.h>
 #endif
+#endif
 
 namespace
 {
@@ -361,6 +364,7 @@ Server::setup_fd_after_listen([[maybe_unused]] const NetProcessor::AcceptOptions
 #ifdef SO_ACCEPTFILTER
   // SO_ACCEPTFILTER needs to be set **after** listen
   if (opt.defer_accept > 0) {
+#if !defined(__NetBSD__)
     int file_id = kldfind("accf_data");
 
     struct kld_file_stat stat;
@@ -369,6 +373,7 @@ Server::setup_fd_after_listen([[maybe_unused]] const NetProcessor::AcceptOptions
     if (kldstat(file_id, &stat) < 0) {
       Error("[Server::listen] Ignored defer_accept config. Because accf_data module is not loaded errno=%d", errno);
     } else {
+#endif
       struct accept_filter_arg afa;
 
       bzero(&afa, sizeof(afa));
@@ -378,9 +383,11 @@ Server::setup_fd_after_listen([[maybe_unused]] const NetProcessor::AcceptOptions
         Error("[Server::listen] Defer accept is configured but set failed: %d", errno);
         return -errno;
       }
+#if !defined(__NetBSD__)
     }
-  }
 #endif
+  }
 
+#endif
   return 0;
 }
