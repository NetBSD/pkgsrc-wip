$NetBSD: patch-lib__phusion_passenger__platform_info__compiler.rb,v 1.1 2012/05/11 09:14:40 fhajny Exp $

Fix compilation on recent SunOS platforms (OpenIndiana/SmartOS).
--- lib/phusion_passenger/platform_info/compiler.rb.orig	2011-11-28 11:51:11.000000000 +0000
+++ lib/phusion_passenger/platform_info/compiler.rb
@@ -143,9 +143,14 @@ module PlatformInfo
 		
 		if RUBY_PLATFORM =~ /solaris/
 			flags << '-pthreads'
-			flags << '-D_XOPEN_SOURCE=500 -D_XPG4_2 -D__EXTENSIONS__ -D__SOLARIS__ -D_FILE_OFFSET_BITS=64'
+			if RUBY_PLATFORM =~ /solaris2.11/
+				# skip the _XOPEN_SOURCE and _XPG4_2 definitions in later versions of Solaris / OpenIndiana
+				flags << '-D__EXTENSIONS__ -D__SOLARIS__ -D_FILE_OFFSET_BITS=64'
+			else
+				flags << '-D_XOPEN_SOURCE=500 -D_XPG4_2 -D__EXTENSIONS__ -D__SOLARIS__ -D_FILE_OFFSET_BITS=64'
+				flags << '-D__SOLARIS9__ -DBOOST__STDC_CONSTANT_MACROS_DEFINED' if RUBY_PLATFORM =~ /solaris2.9/
+			end
 			flags << '-DBOOST_HAS_STDINT_H' unless RUBY_PLATFORM =~ /solaris2.9/
-			flags << '-D__SOLARIS9__ -DBOOST__STDC_CONSTANT_MACROS_DEFINED' if RUBY_PLATFORM =~ /solaris2.9/
 			flags << '-mcpu=ultrasparc' if RUBY_PLATFORM =~ /sparc/
 		elsif RUBY_PLATFORM =~ /openbsd/
 			flags << '-DBOOST_HAS_STDINT_H -D_GLIBCPP__PTHREADS'
@@ -158,7 +163,7 @@ module PlatformInfo
 			flags << '-DBOOST_SP_USE_PTHREADS'
 		end
 		
-		flags << '-DHAS_ALLOCA_H' if has_alloca_h?
+		flags << '-DHAS_ALLOCA_H_' if has_alloca_h?
 		flags << '-DHAS_SFENCE' if supports_sfence_instruction?
 		flags << '-DHAS_LFENCE' if supports_lfence_instruction?
 		
