$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uv/test/test-list.h.orig	2024-11-18 09:27:56.000000000 +0000
+++ third_party/electron_node/deps/uv/test/test-list.h
@@ -273,6 +273,7 @@ TEST_DECLARE   (process_priority)
 TEST_DECLARE   (has_ref)
 TEST_DECLARE   (active)
 TEST_DECLARE   (embed)
+TEST_DECLARE   (embed_with_external_timer)
 TEST_DECLARE   (async)
 TEST_DECLARE   (async_null_cb)
 TEST_DECLARE   (eintr_handling)
@@ -894,6 +895,7 @@ TASK_LIST_START
   TEST_ENTRY  (active)
 
   TEST_ENTRY  (embed)
+  TEST_ENTRY  (embed_with_external_timer)
 
   TEST_ENTRY  (async)
   TEST_ENTRY  (async_null_cb)
