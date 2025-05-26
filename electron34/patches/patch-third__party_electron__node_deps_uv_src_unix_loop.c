$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/unix/loop.c.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uv/src/unix/loop.c
@@ -217,6 +217,11 @@ int uv__loop_configure(uv_loop_t* loop, 
     return 0;
   }
 
+  if (option == UV_LOOP_INTERRUPT_ON_IO_CHANGE) {
+    lfields->flags |= UV_LOOP_INTERRUPT_ON_IO_CHANGE;
+    return 0;
+  }
+
   if (option != UV_LOOP_BLOCK_SIGNAL)
     return UV_ENOSYS;
 
@@ -226,3 +231,40 @@ int uv__loop_configure(uv_loop_t* loop, 
   loop->flags |= UV_LOOP_BLOCK_SIGPROF;
   return 0;
 }
+
+
+void uv__loop_interrupt(uv_loop_t* loop) {
+  const void* buf;
+  ssize_t len;
+  int fd;
+  int r;
+
+  buf = "";
+  len = 1;
+  fd = loop->async_wfd;
+
+#if defined(__linux__)
+  if (fd == -1) {
+    static const uint64_t val = 1;
+    buf = &val;
+    len = sizeof(val);
+    fd = loop->async_io_watcher.fd;  /* eventfd */
+  }
+#endif
+
+  do
+    r = write(fd, buf, len);
+  while (r == -1 && errno == EINTR);
+
+  if (r == len)
+    return;
+
+  if (!uv_loop_alive(loop))
+    return;
+
+  if (r == -1)
+    if (errno == EAGAIN || errno == EWOULDBLOCK)
+      return;
+
+  abort();
+}
