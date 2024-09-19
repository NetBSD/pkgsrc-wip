$NetBSD: patch-testport.cc,v 1.1 2014/08/23 23:07:16 leot1990 Exp $

<sys/io.h> is Linux-specific (from FreeBSD devel/picprog port).

--- testport.cc.orig	2010-04-14 01:14:09.000000000 +0000
+++ testport.cc
@@ -38,7 +38,6 @@ make sure your email passes my spam filt
 #include <ctime>
 
 #include <sys/ioctl.h>
-#include <sys/io.h>
 #include <fcntl.h>
 #include <sys/time.h>
 #include <unistd.h>
