$NetBSD$

* support getting the cpu count on netbsd, openbsd and irix

--- sql/resourcegroups/platform/thread_attrs_api_apple.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ sql/resourcegroups/platform/thread_attrs_api_apple.cc
@@ -24,6 +24,10 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 
+#ifdef IRIX5
+#include <sys/sysmp.h>
+#endif
+
 #include "my_dbug.h"
 #include "sql/log.h"
 
@@ -84,8 +88,19 @@ bool set_thread_priority(int, my_thread_
 
 uint32_t num_vcpus_using_affinity() { return 0; }
 
+
+#ifdef IRIX5
 uint32_t num_vcpus_using_config() {
+  return sysmp(MP_NAPROCS);
+}
+#else
+
+uint32_t num_vcpus_using_config() {
+#if (defined(__NetBSD__) || defined(__OpenBSD__))
+  int name[2] = {CTL_HW, HW_NCPUONLINE};
+#else
   int name[2] = {CTL_HW, HW_AVAILCPU};
+#endif
   int ncpu;
 
   size_t size = sizeof(ncpu);
@@ -93,6 +108,9 @@ uint32_t num_vcpus_using_config() {
   return ncpu;
 }
 
+#endif
+
+
 bool can_thread_priority_be_set() {
   DBUG_ASSERT(0);
   return false;
