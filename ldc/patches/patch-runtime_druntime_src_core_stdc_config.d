$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/config.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/config.d
@@ -116,6 +116,8 @@ else version( DigitalMars )
             alias real c_long_double;
         else version( FreeBSD )
             alias real c_long_double;
+        else version( NetBSD )
+            alias real c_long_double;
         else version( Solaris )
             alias real c_long_double;
         else version( OSX )
