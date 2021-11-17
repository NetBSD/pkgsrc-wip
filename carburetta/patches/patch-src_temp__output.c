$NetBSD$

Unconditionally disable Windows code paths.
Unconditionally enable POSIX code paths.

--- src/temp_output.c.orig	2021-04-09 12:00:52.000000000 +0000
+++ src/temp_output.c
@@ -38,7 +38,7 @@
 #include <string.h>
 #endif
 
-#ifdef _WIN32
+#if 0  /* #ifdef _WIN32 */
 #ifndef IO_H_INCLUDED
 #define IO_H_INCLUDED
 #include <io.h> /* _open_osfhandle */
@@ -49,7 +49,7 @@
 #endif
 #endif
 
-#ifdef __linux__
+#if 1  /* #ifdef __linux__ */
 #ifndef SYS_TYPES_H_INCLUDED
 #define SYS_TYPES_H_INCLUDED
 #include <sys/types.h>
@@ -74,7 +74,7 @@
 #endif
 
 static int to_get_random_bytes(void *buf, size_t num_bytes) {
-#ifdef __linux__
+#if 1  /* #ifdef __linux__ */
   FILE *fp = fopen("/dev/urandom", "rb");
   if (!fp) {
     return errno;
@@ -147,7 +147,7 @@ FILE *to_make_temp(const char *final_des
       return NULL;
     }
 
-#ifdef _WIN32
+#if 0  /* #ifdef _WIN32 */
     HANDLE h = CreateFileA(temp_filename, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
     if (INVALID_HANDLE_VALUE == h) {
       /* keep going; we're assuming a collision, which may be naive */
@@ -173,7 +173,7 @@ FILE *to_make_temp(const char *final_des
       continue;
     }
 #endif
-#ifdef __linux__
+#if 1  /* #ifdef __linux__ */
     int fd = open(temp_filename, O_CREAT|O_EXCL|O_RDWR, 0664);
     if (fd == -1) {
       if (attempt == last_attempt) {
