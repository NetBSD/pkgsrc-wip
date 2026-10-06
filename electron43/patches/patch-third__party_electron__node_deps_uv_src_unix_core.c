$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/unix/core.c.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uv/src/unix/core.c
@@ -926,6 +926,9 @@ void uv__io_start(uv_loop_t* loop, uv__i
     loop->watchers[w->fd] = w;
     loop->nfds++;
   }
+
+  if (uv__get_internal_fields(loop)->flags & UV_LOOP_INTERRUPT_ON_IO_CHANGE)
+    uv__loop_interrupt(loop);
 }
 
 
@@ -957,6 +960,9 @@ void uv__io_stop(uv_loop_t* loop, uv__io
   }
   else if (uv__queue_empty(&w->watcher_queue))
     uv__queue_insert_tail(&loop->watcher_queue, &w->watcher_queue);
+
+  if (uv__get_internal_fields(loop)->flags & UV_LOOP_INTERRUPT_ON_IO_CHANGE)
+    uv__loop_interrupt(loop);
 }
 
 
@@ -973,6 +979,9 @@ void uv__io_close(uv_loop_t* loop, uv__i
 void uv__io_feed(uv_loop_t* loop, uv__io_t* w) {
   if (uv__queue_empty(&w->pending_queue))
     uv__queue_insert_tail(&loop->pending_queue, &w->pending_queue);
+
+  if (uv__get_internal_fields(loop)->flags & UV_LOOP_INTERRUPT_ON_IO_CHANGE)
+    uv__loop_interrupt(loop);
 }
 
 
