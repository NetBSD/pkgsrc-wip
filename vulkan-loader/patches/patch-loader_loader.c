$NetBSD$
* add netbsd support
--- loader/loader.c.orig	2020-12-01 20:50:08.000000000 +0000
+++ loader/loader.c
@@ -44,6 +44,8 @@
 
 #if defined(__APPLE__)
 #include <CoreFoundation/CoreFoundation.h>
+#endif
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/param.h>
 #endif
 
@@ -253,7 +255,7 @@ void *loader_device_heap_realloc(const s
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__NetBSD__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
@@ -268,7 +270,7 @@ static inline char *loader_getenv(const 
 
 static inline char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
     char *out;
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
