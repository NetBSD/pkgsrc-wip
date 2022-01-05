$NetBSD$

* quick fix, don't set or get affinity on unsupported platforms

--- auxil/highwayhash/highwayhash/os_specific.cc.orig	2021-09-22 16:48:30.000000000 +0000
+++ auxil/highwayhash/highwayhash/os_specific.cc
@@ -108,7 +108,7 @@ void RaiseThreadPriority() {
   // lead to 2-3x runtime and higher variability!
 #elif OS_FREEBSD || OS_MAC
 #else
-#error "port"
+
 #endif
 }
 
@@ -177,7 +177,7 @@ void SetThreadAffinity(ThreadAffinity* a
   const int err = mac_setaffinity(&affinity->set);
   CHECK(err == 0);
 #else
-#error "port"
+
 #endif
 }
 
@@ -210,7 +210,7 @@ std::vector<int> AvailableCPUs() {
     }
   }
 #else
-#error "port"
+
 #endif
   return cpus;
 }
@@ -229,7 +229,7 @@ void PinThreadToCPU(const int cpu) {
   CPU_ZERO(&affinity.set);
   CPU_SET(cpu, &affinity.set);
 #else
-#error "port"
+
 #endif
   SetThreadAffinity(&affinity);
 }
