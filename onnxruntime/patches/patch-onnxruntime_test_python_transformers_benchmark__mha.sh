$NetBSD$

Fix unportable test(1) operator.

--- onnxruntime/test/python/transformers/benchmark_mha.sh.orig	2026-05-01 09:13:39.933359657 +0000
+++ onnxruntime/test/python/transformers/benchmark_mha.sh
@@ -101,8 +101,8 @@ run_cpu_benchmarks() {
 
 [ "$task" != "cpu" ] && configure_gpu 0
 
-[ "$task" == "gpu" ] && run_gpu_benchmarks
+[ "$task" = "gpu" ] && run_gpu_benchmarks
 
-[ "$task" == "cpu" ] && run_cpu_benchmarks
+[ "$task" = "cpu" ] && run_cpu_benchmarks
 
-[ "$task" == "lean" ] && run_lean_benchmarks
+[ "$task" = "lean" ] && run_lean_benchmarks
