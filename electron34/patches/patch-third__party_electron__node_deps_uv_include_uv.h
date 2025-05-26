$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/include/uv.h.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uv/include/uv.h
@@ -155,7 +155,6 @@ struct uv__queue {
   XX(EFTYPE, "inappropriate file type or format")                             \
   XX(EILSEQ, "illegal byte sequence")                                         \
   XX(ESOCKTNOSUPPORT, "socket type not supported")                            \
-  XX(ENODATA, "no data available")                                            \
   XX(EUNATCH, "protocol driver not attached")                                 \
 
 #define UV_HANDLE_TYPE_MAP(XX)                                                \
@@ -260,7 +259,8 @@ typedef struct uv_metrics_s uv_metrics_t
 
 typedef enum {
   UV_LOOP_BLOCK_SIGNAL = 0,
-  UV_METRICS_IDLE_TIME
+  UV_METRICS_IDLE_TIME,
+  UV_LOOP_INTERRUPT_ON_IO_CHANGE
 } uv_loop_option;
 
 typedef enum {
