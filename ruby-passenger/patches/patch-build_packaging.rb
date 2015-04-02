$NetBSD: patch-build_packaging.rb,v 1.1 2015/04/02 15:40:15 fhajny Exp $

Mangle faceroot support for our purposes.
--- build/packaging.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/packaging.rb
@@ -483,7 +483,7 @@ def change_shebang(filename, value)
 end
 
 desc "Create a fakeroot, useful for building native packages"
-task :fakeroot => [:apache2, :nginx, :doc] do
+task :fakeroot => [:agents] do
   require 'rbconfig'
   require 'fileutils'
   include RbConfig
@@ -513,7 +513,7 @@ task :fakeroot => [:apache2, :nginx, :do
   psg_ruby_extension_source_dir = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
   psg_nginx_module_source_dir   = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
 
-  fakeroot = "pkg/fakeroot"
+  fakeroot = ENV['DESTDIR'].nil? ? '' : ENV['DESTDIR']
   fake_rubylibdir = "#{fakeroot}#{psg_rubylibdir}"
   fake_nodelibdir = "#{fakeroot}#{psg_nodelibdir}"
   fake_libdir     = "#{fakeroot}#{psg_libdir}"
@@ -622,10 +622,6 @@ task :fakeroot => [:apache2, :nginx, :do
     end
   end
 
-  # Apache 2 module
-  sh "mkdir -p #{File.dirname(fake_apache2_module_path)}"
-  sh "cp #{APACHE2_MODULE} #{fake_apache2_module_path}"
-
   # Ruby extension sources
   sh "mkdir -p #{fake_ruby_extension_source_dir}"
   sh "cp -R #{PhusionPassenger.ruby_extension_source_dir}/* #{fake_ruby_extension_source_dir}"
@@ -656,5 +652,5 @@ task :fakeroot => [:apache2, :nginx, :do
     end
   end
 
-  sh "find #{fakeroot} -name .DS_Store -print0 | xargs -0 rm -f"
+  sh "find #{fakeroot} -name .DS_Store -exec rm -f '{}' \\\;"
 end
