$NetBSD: patch-build__packaging.rb,v 1.2 2013/09/05 10:55:51 fhajny Exp $

Mangle faceroot support for our purposes.
--- build/packaging.rb.orig	2013-08-15 15:21:53.000000000 +0000
+++ build/packaging.rb
@@ -218,29 +218,30 @@ task 'package:clean' do
 end
 
 desc "Create a fakeroot, useful for building native packages"
-task :fakeroot => [:apache2, :nginx, :doc] do
+task :fakeroot => [:agents] do
 	require 'rbconfig'
 	require 'fileutils'
 	include RbConfig
-	fakeroot = "pkg/fakeroot"
+	prefix = ENV['PREFIX']
+	fakeroot = ENV['DESTDIR'].nil? ? '' : ENV['DESTDIR']
 	
 	# We don't use CONFIG['archdir'] and the like because we want
-	# the files to be installed to /usr, and the Ruby interpreter
-	# on the packaging machine might be in /usr/local.
-	fake_rubylibdir = "#{fakeroot}/usr/lib/ruby/vendor_ruby"
-	fake_libdir = "#{fakeroot}/usr/lib/#{GLOBAL_NAMESPACE_DIRNAME}"
-	fake_native_support_dir = "#{fakeroot}/usr/lib/ruby/#{CONFIG['ruby_version']}/#{CONFIG['arch']}"
-	fake_agents_dir = "#{fakeroot}/usr/lib/#{GLOBAL_NAMESPACE_DIRNAME}/agents"
-	fake_helper_scripts_dir = "#{fakeroot}/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/helper-scripts"
-	fake_resources_dir = "#{fakeroot}/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}"
-	fake_include_dir = "#{fakeroot}/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/include"
-	fake_docdir = "#{fakeroot}/usr/share/doc/#{GLOBAL_NAMESPACE_DIRNAME}"
-	fake_bindir = "#{fakeroot}/usr/bin"
-	fake_sbindir = "#{fakeroot}/usr/sbin"
-	fake_apache2_module_dir = "#{fakeroot}/usr/lib/apache2/modules"
+	# the files to be installed to #{prefix}, and the Ruby interpreter
+	# on the packaging machine might be in #{prefix}/local.
+	fake_rubylibdir = "#{fakeroot}#{prefix}/lib/ruby/vendor_ruby"
+	fake_libdir = "#{fakeroot}#{prefix}/lib/#{GLOBAL_NAMESPACE_DIRNAME}"
+	fake_native_support_dir = "#{fakeroot}#{prefix}/lib/ruby/#{CONFIG['ruby_version']}/#{CONFIG['arch']}"
+	fake_agents_dir = "#{fakeroot}#{prefix}/lib/#{GLOBAL_NAMESPACE_DIRNAME}/agents"
+	fake_helper_scripts_dir = "#{fakeroot}#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/helper-scripts"
+	fake_resources_dir = "#{fakeroot}#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}"
+	fake_include_dir = "#{fakeroot}#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/include"
+	fake_docdir = "#{fakeroot}#{prefix}/share/doc/#{GLOBAL_NAMESPACE_DIRNAME}"
+	fake_bindir = "#{fakeroot}#{prefix}/bin"
+	fake_sbindir = "#{fakeroot}#{prefix}/sbin"
+	fake_apache2_module_dir = "#{fakeroot}#{prefix}/lib/httpd"
 	fake_apache2_module = "#{fake_apache2_module_dir}/mod_passenger.so"
-	fake_ruby_extension_source_dir = "#{fakeroot}/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
-	fake_nginx_module_source_dir = "#{fakeroot}/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
+	fake_ruby_extension_source_dir = "#{fakeroot}#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
+	fake_nginx_module_source_dir = "#{fakeroot}#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
 	
 	sh "rm -rf #{fakeroot}"
 	sh "mkdir -p #{fakeroot}"
@@ -315,10 +316,6 @@ task :fakeroot => [:apache2, :nginx, :do
 		sh "cp bin/#{exe} #{fake_sbindir}/"
 	end
 	
-	# Apache 2 module
-	sh "mkdir -p #{fake_apache2_module_dir}"
-	sh "cp #{APACHE2_MODULE} #{fake_apache2_module_dir}/"
-
 	# Ruby extension sources
 	sh "mkdir -p #{fake_ruby_extension_source_dir}"
 	sh "cp -R #{PhusionPassenger.ruby_extension_source_dir}/* #{fake_ruby_extension_source_dir}"
@@ -327,17 +324,17 @@ task :fakeroot => [:apache2, :nginx, :do
 	File.open("#{fake_rubylibdir}/phusion_passenger/locations.ini", "w") do |f|
 		f.puts "[locations]"
 		f.puts "natively_packaged=true"
-		f.puts "bin_dir=/usr/bin"
-		f.puts "agents_dir=/usr/lib/#{GLOBAL_NAMESPACE_DIRNAME}/agents"
-		f.puts "lib_dir=/usr/lib/#{GLOBAL_NAMESPACE_DIRNAME}"
-		f.puts "helper_scripts_dir=/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/helper-scripts"
-		f.puts "resources_dir=/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}"
-		f.puts "include_dir=/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/include"
-		f.puts "doc_dir=/usr/share/doc/#{GLOBAL_NAMESPACE_DIRNAME}"
-		f.puts "ruby_libdir=/usr/lib/ruby/vendor_ruby"
-		f.puts "apache2_module_path=/usr/lib/apache2/modules/mod_passenger.so"
-		f.puts "ruby_extension_source_dir=/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
-		f.puts "nginx_module_source_dir=/usr/share/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
+		f.puts "bin_dir=#{prefix}/bin"
+		f.puts "agents_dir=#{prefix}/lib/#{GLOBAL_NAMESPACE_DIRNAME}/agents"
+		f.puts "lib_dir=#{prefix}/lib/#{GLOBAL_NAMESPACE_DIRNAME}"
+		f.puts "helper_scripts_dir=#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/helper-scripts"
+		f.puts "resources_dir=#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}"
+		f.puts "include_dir=#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/include"
+		f.puts "doc_dir=#{prefix}/share/doc/#{GLOBAL_NAMESPACE_DIRNAME}"
+		f.puts "ruby_libdir=#{prefix}/lib/ruby/vendor_ruby"
+		f.puts "apache2_module_path=#{prefix}/lib/httpd/mod_passenger.so"
+		f.puts "ruby_extension_source_dir=#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/ruby_extension_source"
+		f.puts "nginx_module_source_dir=#{prefix}/share/#{GLOBAL_NAMESPACE_DIRNAME}/ngx_http_passenger_module"
 	end
 
 	# Sanity check the locations.ini file
@@ -348,5 +345,5 @@ task :fakeroot => [:apache2, :nginx, :do
 		end
 	end
 
-	sh "find #{fakeroot} -name .DS_Store -print0 | xargs -0 rm -f"
+	sh "find #{fakeroot} -name .DS_Store -exec rm -f '{}' \\\;"
 end
