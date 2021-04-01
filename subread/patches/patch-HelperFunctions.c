$NetBSD$

# Use predefined macros, guard sysinfo

--- HelperFunctions.c.orig	2021-03-27 07:38:08.000000000 +0000
+++ HelperFunctions.c
@@ -26,7 +26,7 @@
 #include <pthread.h>
 
 
-#ifdef MACOS
+#ifdef __APPLE__
 
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -47,8 +47,11 @@
 #include <sys/ioctl.h>
 #include <netinet/in.h>
 #include <net/if.h>
+// Add other platforms that lack native or pkgsrc libsysinfo
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysinfo.h>
 #endif
+#endif
 #include <sys/types.h>
 #endif
 
@@ -846,10 +849,10 @@ int strcmp_number(char * s1, char * s2)
 
 int mac_str(char * str_buff)
 {
-#if defined(FREEBSD) || defined(__MINGW32__)
+#if defined(__FreeBSD__) || defined(__MINGW32__)
 	return 1;
 #else
-#ifdef MACOS
+#ifdef __APPLE__
     int         mib[6], x1, ret = 1;
 	size_t		len;
     char            *buf;
@@ -2702,22 +2705,20 @@ void main(){
 #include <windows.h>
 #endif
 
-
+/* FIXME: Should this always return 0, or send back -1 as an error code? */
 int get_free_total_mem(size_t * total, size_t * free_mem){
 
-#ifdef FREEBSD
+// Add other platforms that lack native or pkgsrc libsysinfo
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     return -1;
-#endif
-
-#ifdef __MINGW32__
+#elif defined(__MINGW32__)
 	MEMORYSTATUSEX statex;
 	statex.dwLength = sizeof (statex);
 	GlobalMemoryStatusEx (&statex);
 	(*total) = statex.ullTotalPhys;
 	(*free_mem) = statex.ullAvailPhys;
 	return 0;
-#else
-#ifdef MACOS
+#elif defined(__APPLE__)
     mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
     vm_statistics_data_t vmstat;
     int page_size = getpagesize();
@@ -2737,7 +2738,6 @@ int get_free_total_mem(size_t * total, s
     *total = sinf.totalram;
     return 0;
 #endif
-#endif
 }
 
 void worker_master_mutex_init(worker_master_mutex_t * wmt, int all_workers){
