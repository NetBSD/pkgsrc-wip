$NetBSD$

Add missing include for errno.

--- findcrcs.cc.orig	2015-05-24 22:26:34.000000000 +0000
+++ findcrcs.cc
@@ -33,6 +33,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
