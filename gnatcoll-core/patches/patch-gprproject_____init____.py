$NetBSD: patch-gprproject_____init____.py,v 1.0 2024/11/27 11:00:00 dkazankov Exp $

Fix parameters throughput

--- gprproject/__init__.py.orig	2024-09-24 12:28:32.000000000 +0300
+++ gprproject/__init__.py	2024-11-27 14:33:44.097637432 +0200
@@ -173,7 +173,7 @@
             print(f'{var:<32} := "{value}";')
 
         if not args.configure_only:
-            status = gpr.build([])
+            status = gpr.build(args.gpr_opts)
             if status == 0 and args.install:
                 status = gpr.install([])
             return status
