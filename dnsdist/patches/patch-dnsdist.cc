$NetBSD$

Let readline be handled by buildlink from editline.

--- dnsdist.cc.orig	2020-07-29 16:09:33.000000000 +0000
+++ dnsdist.cc
@@ -31,13 +31,9 @@
 #include <sys/resource.h>
 #include <unistd.h>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
 // If this is not undeffed, __attribute__ wil be redefined by /usr/include/readline/rlstdc.h
 #undef __STRICT_ANSI__
 #include <readline/readline.h>
-#else
-#include <editline/readline.h>
-#endif
 
 #include "dnsdist-systemd.hh"
 #ifdef HAVE_SYSTEMD
