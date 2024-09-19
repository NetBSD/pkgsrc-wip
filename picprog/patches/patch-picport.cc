$NetBSD: patch-picport.cc,v 1.1 2014/08/23 23:07:16 leot1990 Exp $

<sys/io.h> and iopl(2) is Linux-specific (from FreeBSD devel/picprog port).

--- picport.cc.orig	2010-04-14 01:45:20.000000000 +0000
+++ picport.cc
@@ -38,7 +38,6 @@ make sure your email passes my spam filt
 #include <ctime>
 
 #include <sys/ioctl.h>
-#include <sys/io.h>
 #include <fcntl.h>
 #include <sys/time.h>
 #include <unistd.h>
@@ -160,8 +159,6 @@ picport::picport (const char *tty, bool 
     // Not root.  Cannot use realtime scheduling.
     use_nanosleep = 0;
   }
-  if (iopl (3))
-    disable_interrupts = 0;
 
 #ifdef CPU_SETSIZE
   // When computing the delay loops, we do not want the cpu's to change.
