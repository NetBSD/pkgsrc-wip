$NetBSD$
* add netbsd support
--- loader/loader.c.orig	2019-09-11 17:39:09.000000000 +0000
+++ loader/loader.c
@@ -44,6 +44,8 @@
 
 #if defined(__APPLE__)
 #include <CoreFoundation/CoreFoundation.h>
+#endif
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/param.h>
 #endif
 
@@ -241,7 +243,7 @@ void *loader_device_heap_realloc(const s
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
@@ -255,7 +257,7 @@ static inline char *loader_getenv(const 
 }
 
 static inline char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
