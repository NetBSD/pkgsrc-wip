$NetBSD$

# Needed by pkgsrc on all platforms
--- ../staden-io_lib-1.14.8.1/progs/scram_merge.c.orig	2018-09-13 20:12:38.101447761 +0000
+++ ../staden-io_lib-1.14.8.1/progs/scram_merge.c
@@ -45,9 +45,7 @@
 #include <ctype.h>
 #include <errno.h>
 
-#if defined(__MINGW32__) || defined(__FreeBSD__) || defined(__APPLE__)
 #   include <getopt.h>
-#endif
 
 #include <io_lib/scram.h>
 #include <io_lib/os.h>
