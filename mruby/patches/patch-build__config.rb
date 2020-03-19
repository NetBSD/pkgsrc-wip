$NetBSD$

Avoid adding "-g3 -O0" to CFLAGS.

--- build_config.rb.orig	2020-03-16 14:38:56.753795981 +0000
+++ build_config.rb
@@ -95,7 +95,7 @@ MRuby::Build.new('host-debug') do |conf|
     toolchain :gcc
   end
 
-  enable_debug
+  # enable_debug
 
   # include the default GEMs
   conf.gembox 'default'
@@ -118,7 +118,7 @@ MRuby::Build.new('test') do |conf|
     toolchain :gcc
   end
 
-  enable_debug
+  # enable_debug
   conf.enable_bintest
   conf.enable_test
 
