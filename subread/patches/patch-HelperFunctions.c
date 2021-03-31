$NetBSD$

# Use predefined macros

--- HelperFunctions.c.orig	2021-03-31 00:32:33.690802862 +0000
+++ HelperFunctions.c
@@ -26,7 +26,7 @@
 #include <pthread.h>
 
 
-#ifdef MACOS
+#ifdef __APPLE__
 
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -846,10 +846,10 @@ int strcmp_number(char * s1, char * s2)
 
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
@@ -2705,7 +2705,7 @@ void main(){
 
 int get_free_total_mem(size_t * total, size_t * free_mem){
 
-#ifdef FREEBSD
+#ifdef __FreeBSD__
     return -1;
 #endif
 
@@ -2717,7 +2717,7 @@ int get_free_total_mem(size_t * total, s
 	(*free_mem) = statex.ullAvailPhys;
 	return 0;
 #else
-#ifdef MACOS
+#ifdef __APPLE__
     mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
     vm_statistics_data_t vmstat;
     int page_size = getpagesize();
