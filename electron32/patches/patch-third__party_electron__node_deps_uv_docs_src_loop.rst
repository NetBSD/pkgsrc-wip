$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/docs/src/loop.rst.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/docs/src/loop.rst
@@ -73,7 +73,15 @@ API
 
       This option is necessary to use :c:func:`uv_metrics_idle_time`.
 
+    - UV_LOOP_INTERRUPT_ON_IO_CHANGE: Interrupt the loop whenever a new IO
+      event has been added or changed.
+
+      This option is usually when implementing event loop integration, to make
+      the polling of backend fd interrupt to recognize the changes of IO events.
+
     .. versionchanged:: 1.39.0 added the UV_METRICS_IDLE_TIME option.
+    .. versionchanged:: 1.43.0 added the UV_LOOP_INTERRUPT_ON_IO_CHANGE option.
+
 
 .. c:function:: int uv_loop_close(uv_loop_t* loop)
 
