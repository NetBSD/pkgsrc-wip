$NetBSD: patch-gpr_src_gpr-util-put_resource_usage__unix.adb,v 1.0 2023/12/22 12:40:00 dkazankov Exp $

Correct warning at link stage

--- gpr/src/gpr-util-put_resource_usage__unix.adb.orig	2023-10-09 21:31:11.000000000 +0300
+++ gpr/src/gpr-util-put_resource_usage__unix.adb	2023-12-22 12:36:20.531382047 +0200
@@ -69,7 +69,7 @@
       procedure Print (This : STC.Timeval);
 
       function Getrusage (Who : Integer; usage : out Rusage) return Integer
-        with Import, Convention => C;
+        with Import, Convention => C, External_Name => "__netbsd_getrusage";
 
       -----------
       -- Print --
