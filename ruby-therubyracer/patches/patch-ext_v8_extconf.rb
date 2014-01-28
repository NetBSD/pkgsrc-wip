$NetBSD: patch-ext_v8_extconf.rb,v 1.1 2014/01/28 15:59:49 fhajny Exp $

Make sure we actually link libv8.
--- ext/v8/extconf.rb.orig	2014-01-23 11:49:29.626635920 +0000
+++ ext/v8/extconf.rb
@@ -2,6 +2,7 @@ require 'mkmf'
 
 have_library('pthread')
 have_library('objc') if RUBY_PLATFORM =~ /darwin/
+have_library('v8')
 $CPPFLAGS += " -Wall" unless $CPPFLAGS.split.include? "-Wall"
 $CPPFLAGS += " -g" unless $CPPFLAGS.split.include? "-g"
 $CPPFLAGS += " -rdynamic" unless $CPPFLAGS.split.include? "-rdynamic"
