$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/src/uv-common.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uv/src/uv-common.h
@@ -144,6 +144,8 @@ int uv__loop_configure(uv_loop_t* loop, 
 
 void uv__loop_close(uv_loop_t* loop);
 
+void uv__loop_interrupt(uv_loop_t* loop);
+
 int uv__read_start(uv_stream_t* stream,
                    uv_alloc_cb alloc_cb,
                    uv_read_cb read_cb);
@@ -280,6 +282,10 @@ void uv__threadpool_cleanup(void);
     if (((h)->flags & UV_HANDLE_ACTIVE) != 0) break;                          \
     (h)->flags |= UV_HANDLE_ACTIVE;                                           \
     if (((h)->flags & UV_HANDLE_REF) != 0) uv__active_handle_add(h);          \
+    int loop_flags = uv__get_internal_fields((h)->loop)->flags;               \
+    if (loop_flags & UV_LOOP_INTERRUPT_ON_IO_CHANGE) {                        \
+      uv__loop_interrupt((h)->loop);                                          \
+    }                                                                         \
   }                                                                           \
   while (0)
 
