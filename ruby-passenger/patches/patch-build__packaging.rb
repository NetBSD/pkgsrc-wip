$NetBSD: patch-build__packaging.rb,v 1.4 2014/10/29 12:59:17 fhajny Exp $

Mangle faceroot support for our purposes.
--- build/packaging.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/packaging.rb
@@ -477,7 +477,7 @@ def change_shebang(filename, value)
 end
 
 desc "Create a fakeroot, useful for building native packages"
-task :fakeroot => [:apache2, :nginx, :doc] do
+task :fakeroot => [:agents] do
 	require 'rbconfig'
 	require 'fileutils'
 	include RbConfig
@@ -507,7 +507,7 @@ task :fakeroot => [:apache2, :nginx, :do
 	psg_ruby_extension_source_dir = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
 	psg_nginx_module_source_dir   = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
 
-	fakeroot = "pkg/fakeroot"
+	fakeroot = ENV['DESTDIR'].nil? ? '' : ENV['DESTDIR']
 	fake_rubylibdir = "#{fakeroot}#{psg_rubylibdir}"
 	fake_nodelibdir = "#{fakeroot}#{psg_nodelibdir}"
 	fake_libdir     = "#{fakeroot}#{psg_libdir}"
@@ -610,10 +610,6 @@ task :fakeroot => [:apache2, :nginx, :do
 		end
 	end
 
-	# Apache 2 module
-	sh "mkdir -p #{File.dirname(fake_apache2_module_path)}"
-	sh "cp #{APACHE2_MODULE} #{fake_apache2_module_path}"
-
 	# Ruby extension sources
 	sh "mkdir -p #{fake_ruby_extension_source_dir}"
 	sh "cp -R #{PhusionPassenger.ruby_extension_source_dir}/* #{fake_ruby_extension_source_dir}"
@@ -645,5 +641,5 @@ task :fakeroot => [:apache2, :nginx, :do
 		end
 	end
 
-	sh "find #{fakeroot} -name .DS_Store -print0 | xargs -0 rm -f"
+	sh "find #{fakeroot} -name .DS_Store -exec rm -f '{}' \\\;"
 end
