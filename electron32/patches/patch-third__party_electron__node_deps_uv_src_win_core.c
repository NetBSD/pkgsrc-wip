$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/win/core.c.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/src/win/core.c
@@ -384,10 +384,20 @@ int uv__loop_configure(uv_loop_t* loop, 
     return 0;
   }
 
+  if (option == UV_LOOP_INTERRUPT_ON_IO_CHANGE) {
+    lfields->flags |= UV_LOOP_INTERRUPT_ON_IO_CHANGE;
+    return 0;
+  }
+
   return UV_ENOSYS;
 }
 
 
+void uv__loop_interrupt(uv_loop_t* loop) {
+  PostQueuedCompletionStatus(loop->iocp, 0, 0, NULL);
+}
+
+
 int uv_backend_fd(const uv_loop_t* loop) {
   return -1;
 }
