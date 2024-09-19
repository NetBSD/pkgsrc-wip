$NetBSD$

Respect PKG_SYSCONFDIR
An ANSI C FILE and a unix file number are two kettle of fish. Convert.

--- in.jabberd/in.jabberd.c.orig	2014-09-04 10:54:38.000000000 +0000
+++ in.jabberd/in.jabberd.c
@@ -37,7 +37,7 @@
 #define VERSION "201409"
 #define PROGNAME "in.jabberd"
 #define WORKING_FOLDER "/tmp"
-#define USER_LIST "/etc/in.jabberd.conf"
+#define USER_LIST SYSCONFDIR "/in.jabberd.conf"
 
 #define B_SIZE 16384
 #define PATH_SIZE 255
@@ -124,7 +124,7 @@ FILE* get_buffer(char* user, char* mode)
     char fname[PATH_SIZE];
     sprintf(fname, "%s/in.jabberd_%s", WORKING_FOLDER, user);
     FILE* f = fopen(fname, mode);
-    flock(f, LOCK_EX);
+    flock(fileno(f), LOCK_EX);
     return f;
 }
 
