$NetBSD$

Add pkgsrc's PREFIX to the library search path.

--- src/compiler/crystal/codegen/link.cr.orig	2020-06-04 12:01:14.000000000 +0000
+++ src/compiler/crystal/codegen/link.cr
@@ -110,7 +110,7 @@ module Crystal
 
     private def lib_flags_posix
       library_path = ENV["LIBRARY_PATH"]?.try(&.split(':', remove_empty: true)) ||
-                     ["/usr/lib", "/usr/local/lib"]
+                     ["/usr/lib", "@PREFIX@/lib", "/usr/local/lib"]
       has_pkg_config = nil
 
       String.build do |flags|
