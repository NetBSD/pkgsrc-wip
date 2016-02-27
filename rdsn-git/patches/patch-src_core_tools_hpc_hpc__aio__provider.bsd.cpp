$NetBSD$

--- src/core/tools/hpc/hpc_aio_provider.bsd.cpp.orig	2016-02-27 19:59:48.000000000 +0000
+++ src/core/tools/hpc/hpc_aio_provider.bsd.cpp
@@ -34,7 +34,7 @@
  */
 
 
-# if defined(__APPLE__) || defined(__FreeBSD__)
+# if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 # include "hpc_aio_provider.h"
 # include <fcntl.h>
@@ -44,6 +44,11 @@
 # include <stdio.h>
 # include "mix_all_io_looper.h"
 
+# if defined(__NetBSD__)
+# include <sys/event.h>
+# include <sys/aio.h>
+# endif
+
 # ifdef __TITLE__
 # undef __TITLE__
 # endif
@@ -53,7 +58,7 @@ namespace dsn { namespace tools {
 
 struct posix_disk_aio_context : public disk_aio
 {
-    struct aiocb cb;
+    struct ::aiocb cb;
     aio_task* tsk;
     hpc_aio_provider* this_;
     utils::notify_event* evt;
@@ -62,7 +67,7 @@ struct posix_disk_aio_context : public d
 };
 
 #ifndef io_prep_pread
-static inline void io_prep_pread(struct aiocb *iocb, int fd, void *buf, size_t count, long long offset)
+static inline void io_prep_pread(struct ::aiocb *iocb, int fd, void *buf, size_t count, long long offset)
 {
     memset(iocb, 0, sizeof(*iocb));
     iocb->aio_fildes = fd;
@@ -211,6 +216,7 @@ error_code hpc_aio_provider::aio_interna
     }
 
     // set up callback
+#if 0
     aio->cb.aio_sigevent.sigev_notify = SIGEV_KEVENT;
     aio->cb.aio_sigevent.sigev_notify_kqueue = (int)(uintptr_t)_looper->native_handle();
     aio->cb.aio_sigevent.sigev_notify_kevent_flags = EV_CLEAR;
@@ -251,6 +257,7 @@ error_code hpc_aio_provider::aio_interna
             return aio->err;
         }
     }
+#endif
 }
 
 void hpc_aio_provider::complete_aio(struct aiocb* io, int bytes, int err)
