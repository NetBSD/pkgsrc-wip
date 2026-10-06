$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/test/cctest/test_environment.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/test/cctest/test_environment.cc
@@ -620,12 +620,9 @@ TEST_F(EnvironmentTest, SetImmediateMicr
 
 #ifndef _WIN32  // No SIGINT on Windows.
 TEST_F(NodeZeroIsolateTestFixture, CtrlCWithOnlySafeTerminationTest) {
-  // We need to go through the whole setup dance here because we want to
-  // set only_terminate_in_safe_scope.
   // Allocate and initialize Isolate.
   v8::Isolate::CreateParams create_params;
   create_params.array_buffer_allocator = allocator.get();
-  create_params.only_terminate_in_safe_scope = true;
   v8::Isolate* isolate = v8::Isolate::Allocate();
   CHECK_NOT_NULL(isolate);
   platform->RegisterIsolate(isolate, &current_loop);
