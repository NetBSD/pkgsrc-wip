$NetBSD$

Fix stack-clash on SunOS.

...and fix the "count CPUs in affinity set" to work on i32 NetBSD ports.

--- library/std/src/sys/pal/unix/thread.rs.orig	2024-03-17 19:03:00.000000000 +0000
+++ library/std/src/sys/pal/unix/thread.rs
@@ -388,7 +388,7 @@ pub fn available_parallelism() -> io::Re
                     if !set.is_null() {
                         let mut count: usize = 0;
                         if libc::pthread_getaffinity_np(libc::pthread_self(), libc::_cpuset_size(set), set) == 0 {
-                            for i in 0..u64::MAX {
+                            for i in 0..libc::cpuid_t::MAX {
                                 match libc::_cpuset_isset(i, set) {
                                     -1 => break,
                                     0 => continue,
@@ -819,7 +819,7 @@ pub mod guard {
         let page_size = os::page_size();
         PAGE_SIZE.store(page_size, Ordering::Relaxed);
 
-        if cfg!(all(target_os = "linux", not(target_env = "musl"))) {
+        if cfg!(all(target_os = "solaris", all(target_os = "linux", not(target_env = "musl")))) {
             // Linux doesn't allocate the whole stack right away, and
             // the kernel has its own stack-guard mechanism to fault
             // when growing too close to an existing mapping. If we map
