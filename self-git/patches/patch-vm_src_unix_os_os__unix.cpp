$NetBSD$

--- vm/src/unix/os/os_unix.cpp.orig	2019-07-21 22:47:42.000000000 +0000
+++ vm/src/unix/os/os_unix.cpp
@@ -195,6 +195,17 @@ void OS::init() {
   len = sizeof(mem_size);
   sysctl(mib, 2, &mem_size, &len, NULL, 0);
   real_mem_size = mem_size;
+# elif  TARGET_OS_VERSION ==  NETBSD_VERSION
+
+  int mib[2];
+  int64_t mem_size;
+  size_t len;
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_USERMEM64;
+  len = sizeof(mem_size);
+  sysctl(mib, 2, &mem_size, &len, NULL, 0);
+  real_mem_size = mem_size;
 # elif TARGET_OS_VERSION == LINUX_VERSION
   real_mem_size = 0x40000000; // punt for now
 # else
@@ -348,7 +359,8 @@ bool OS::setup_snapshot_to_run(const cha
 void OS::set_log_buf(FILE* f, char* buf, int bs) {    
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
   setvbuf(f, buf, _IOFBF, bs);
   
 # elif  TARGET_OS_VERSION == SUNOS_VERSION
@@ -403,7 +415,8 @@ bool OS::get_swap_space_info(int &totalK
 
 # elif  TARGET_OS_VERSION ==  SUNOS_VERSION \
     ||  TARGET_OS_VERSION == MACOSX_VERSION \
-    ||  TARGET_OS_VERSION ==  LINUX_VERSION
+    ||  TARGET_OS_VERSION ==  LINUX_VERSION \
+    ||  TARGET_OS_VERSION == NETBSD_VERSION
 
 bool OS::get_swap_space_info(int &, int &) {
   return false;
@@ -559,7 +572,7 @@ int OS::min_core(caddr_t addr, size_t le
     normal_access((char*)0, (char*)~0);
   }
 
-# elif  TARGET_OS_VERSION == LINUX_VERSION
+# elif  TARGET_OS_VERSION == LINUX_VERSION || TARGET_OS_VERSION == NETBSD_VERSION
   void OS::setPageAdvisory(char *start, char *end, int code) {
     if (end - start < OS::dont_bother) return;
     char *ps= real_page_start(start);
@@ -843,7 +856,8 @@ void OS::check_events() { 
 
 # if  TARGET_OS_VERSION == SOLARIS_VERSION \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION \
-  ||  TARGET_OS_VERSION ==  LINUX_VERSION
+  ||  TARGET_OS_VERSION ==  LINUX_VERSION \
+  ||  TARGET_OS_VERSION == NETBSD_VERSION
 extern "C" {
   int malloc_verify() { return 1; }
 }
