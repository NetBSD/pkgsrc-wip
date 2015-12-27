$NetBSD$

--- src/core/CompUnit/Repository/Installation.pm.orig	2015-12-25 19:23:19.000000000 +0000
+++ src/core/CompUnit/Repository/Installation.pm
@@ -6,6 +6,10 @@ class CompUnit::Repository::Installation
 
     submethod BUILD(:$!prefix, :$!lock, :$!WHICH, :$!next-repo) { }
 
+    method prefix {
+	IO::Path.new(%*ENV<DESTDIR> ~ $!prefix)
+    }
+
     method writeable-path {
         $.prefix.w ?? $.prefix !! IO::Path;
     }
