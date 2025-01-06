$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/unix/async.c.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/src/unix/async.c
@@ -38,7 +38,6 @@
 #include <sys/eventfd.h>
 #endif
 
-static void uv__async_send(uv_loop_t* loop);
 static int uv__async_start(uv_loop_t* loop);
 static void uv__cpu_relax(void);
 
@@ -78,7 +77,7 @@ int uv_async_send(uv_async_t* handle) {
 
   /* Wake up the other thread's event loop. */
   if (atomic_exchange(pending, 1) == 0)
-    uv__async_send(handle->loop);
+    uv__loop_interrupt(handle->loop);
 
   /* Set the loop to not-busy. */
   atomic_fetch_add(busy, -1);
@@ -178,39 +177,6 @@ static void uv__async_io(uv_loop_t* loop
 }
 
 
-static void uv__async_send(uv_loop_t* loop) {
-  const void* buf;
-  ssize_t len;
-  int fd;
-  int r;
-
-  buf = "";
-  len = 1;
-  fd = loop->async_wfd;
-
-#if defined(__linux__)
-  if (fd == -1) {
-    static const uint64_t val = 1;
-    buf = &val;
-    len = sizeof(val);
-    fd = loop->async_io_watcher.fd;  /* eventfd */
-  }
-#endif
-
-  do
-    r = write(fd, buf, len);
-  while (r == -1 && errno == EINTR);
-
-  if (r == len)
-    return;
-
-  if (r == -1)
-    if (errno == EAGAIN || errno == EWOULDBLOCK)
-      return;
-
-  abort();
-}
-
 
 static int uv__async_start(uv_loop_t* loop) {
   int pipefd[2];
