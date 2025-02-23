$NetBSD$

Add NetBSD as a supported platform.

--- s.h.orig	2024-08-09 09:42:51.172343095 +0000
+++ s.h
@@ -93,6 +93,16 @@ typedef struct stat64 stat_t; 
 #else
 typedef struct stat stat_t; 
 #endif
+#elif defined(__GNUC__) && defined(__NetBSD__) 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/wait.h>
+#include <unistd.h>
+#include <dirent.h>
+#include <fcntl.h>
+#include <signal.h>
+#define setbmode(fp) /* nothing */
+typedef struct stat stat_t; 
 #elif defined(__GNUC__) && (defined(_WIN32) || defined(__INTERIX))
 #include <sys/types.h>
 #include <sys/stat.h>
