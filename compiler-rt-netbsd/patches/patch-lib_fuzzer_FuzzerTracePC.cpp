$NetBSD$

--- lib/fuzzer/FuzzerTracePC.cpp.orig	2017-08-30 19:37:28.000000000 +0000
+++ lib/fuzzer/FuzzerTracePC.cpp
@@ -32,7 +32,10 @@ ATTRIBUTE_INTERFACE
 uintptr_t __sancov_trace_pc_pcs[fuzzer::TracePC::kNumPCs];
 
 // Used by -fsanitize-coverage=stack-depth to track stack depth
-ATTRIBUTE_INTERFACE __attribute__((tls_model("initial-exec")))
+ATTRIBUTE_INTERFACE
+#if !SANITIZER_NETBSD
+__attribute__((tls_model("initial-exec")))
+#endif
 thread_local uintptr_t __sancov_lowest_stack;
 
 namespace fuzzer {
