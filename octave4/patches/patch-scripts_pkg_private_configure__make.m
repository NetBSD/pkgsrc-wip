$NetBSD: patch-scripts_pkg_pkg.m,v 1.1 2012/10/27 13:01:35 asau Exp $

Provide path to GNU make, since this is what assumed here.

--- scripts/pkg/private/configure_make.m.orig	2015-05-23 14:21:53.000000000 +0000
+++ scripts/pkg/private/configure_make.m
@@ -88,7 +88,7 @@ function configure_make (desc, packdir, 
     endif
 
     if (exist (fullfile (src, "Makefile"), "file"))
-      [status, output] = shell (sprintf ("%s make --jobs %i --directory '%s'",
+      [status, output] = shell (sprintf ("%s @GMAKE@ --jobs %i --directory '%s'",
                                          scenv, jobs, src), verbose);
       if (status != 0)
         rmdir (desc.dir, "s");
