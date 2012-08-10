$NetBSD: patch-lib__phusion_passenger__platform_info__compiler.rb,v 1.2 2012/08/10 11:37:24 fhajny Exp $

Fix compilation on recent SunOS platforms (OpenIndiana/SmartOS).
--- lib/phusion_passenger/platform_info/compiler.rb.orig	2012-08-01 11:31:04.000000000 +0000
+++ lib/phusion_passenger/platform_info/compiler.rb
@@ -150,7 +150,6 @@ module PlatformInfo
 				flags << '-D_XOPEN_SOURCE=500 -D_XPG4_2 -D__EXTENSIONS__ -D__SOLARIS__ -D_FILE_OFFSET_BITS=64'
 				flags << '-D__SOLARIS9__ -DBOOST__STDC_CONSTANT_MACROS_DEFINED' if RUBY_PLATFORM =~ /solaris2.9/
 			end
-			flags << '-D_XOPEN_SOURCE=500 -D_XPG4_2 -D__EXTENSIONS__ -D__SOLARIS__ -D_FILE_OFFSET_BITS=64'
 			flags << '-DBOOST_HAS_STDINT_H' unless RUBY_PLATFORM =~ /solaris2.9/
 			flags << '-mcpu=ultrasparc' if RUBY_PLATFORM =~ /sparc/
 		elsif RUBY_PLATFORM =~ /openbsd/
