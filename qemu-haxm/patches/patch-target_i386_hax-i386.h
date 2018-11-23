$NetBSD$

--- target/i386/hax-i386.h.orig	2018-11-23 12:57:45.000000000 +0000
+++ target/i386/hax-i386.h
@@ -16,7 +16,7 @@
 #include "cpu.h"
 #include "sysemu/hax.h"
 
-#ifdef CONFIG_DARWIN
+#ifdef CONFIG_POSIX
 typedef int hax_fd;
 #endif
 
@@ -82,8 +82,8 @@ hax_fd hax_mod_open(void);
 void hax_memory_init(void);
 
 
-#ifdef CONFIG_DARWIN
-#include "target/i386/hax-darwin.h"
+#ifdef CONFIG_POSIX
+#include "target/i386/hax-posix.h"
 #endif
 
 #ifdef CONFIG_WIN32
