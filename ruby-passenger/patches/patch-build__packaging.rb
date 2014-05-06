$NetBSD: patch-build__packaging.rb,v 1.3 2014/05/06 13:40:31 fhajny Exp $

Mangle faceroot support for our purposes.
--- build/packaging.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/packaging.rb
@@ -396,7 +396,7 @@ def change_shebang(filename, value)
 end
 
 desc "Create a fakeroot, useful for building native packages"
-task :fakeroot => [:apache2, :nginx, :doc] do
+task :fakeroot => [:agents] do
 	require 'rbconfig'
 	require 'fileutils'
 	include RbConfig
@@ -426,7 +426,7 @@ task :fakeroot => [:apache2, :nginx, :do
 	psg_ruby_extension_source_dir = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
 	psg_nginx_module_source_dir   = "#{fs_datadir}/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
 	
-	fakeroot = "pkg/fakeroot"
+	fakeroot = ENV['DESTDIR'].nil? ? '' : ENV['DESTDIR']
 	fake_rubylibdir = "#{fakeroot}#{psg_rubylibdir}"
 	fake_nodelibdir = "#{fakeroot}#{psg_nodelibdir}"
 	fake_libdir     = "#{fakeroot}#{psg_libdir}"
@@ -529,10 +529,6 @@ task :fakeroot => [:apache2, :nginx, :do
 		end
 	end
 	
-	# Apache 2 module
-	sh "mkdir -p #{File.dirname(fake_apache2_module_path)}"
-	sh "cp #{APACHE2_MODULE} #{fake_apache2_module_path}"
-
 	# Ruby extension sources
 	sh "mkdir -p #{fake_ruby_extension_source_dir}"
 	sh "cp -R #{PhusionPassenger.ruby_extension_source_dir}/* #{fake_ruby_extension_source_dir}"
@@ -564,5 +560,5 @@ task :fakeroot => [:apache2, :nginx, :do
 		end
 	end
 
-	sh "find #{fakeroot} -name .DS_Store -print0 | xargs -0 rm -f"
+	sh "find #{fakeroot} -name .DS_Store -exec rm -f '{}' \\\;"
 end
