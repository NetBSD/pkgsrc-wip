$NetBSD$

Add header for struct uvmexp.

--- arch/bsd.xs.orig	2006-09-16 14:32:56.000000000 +0000
+++ arch/bsd.xs
@@ -8,6 +8,8 @@ MODULE = Sys::MemInfo PACKAGE = Sys::Mem
 #include <stdio.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
 
 void
 availkeys()
