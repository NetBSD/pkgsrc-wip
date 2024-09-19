$NetBSD$

--- src/core/tools/hpc/hpc_aio_provider.h.orig	2016-02-27 19:59:48.000000000 +0000
+++ src/core/tools/hpc/hpc_aio_provider.h
@@ -75,7 +75,7 @@ namespace dsn {
 
             io_context_t _ctx;
             int          _event_fd;
-# elif defined(__APPLE__) || defined(__FreeBSD__)
+# elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
             void complete_aio(struct aiocb* io, int bytes, int err);
 # endif
         };
