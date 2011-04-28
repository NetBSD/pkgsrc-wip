$NetBSD: patch-chrome_plugin_plugin__main__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/plugin/plugin_main_linux.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/plugin/plugin_main_linux.cc
@@ -5,13 +5,13 @@
 #include <signal.h>
 #include <string.h>
 #include <sys/types.h>
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <unistd.h>
 
 #include "build/build_config.h"
 
 // This whole file is only useful on 64-bit architectures.
-#if defined(ARCH_CPU_64_BITS)
+#if defined(ARCH_CPU_64_BITS) && !defined(OS_BSD)
 
 namespace {
 
