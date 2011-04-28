$NetBSD: patch-jingle_jingle.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- jingle/jingle.gyp.orig	2011-04-13 08:01:33.000000000 +0000
+++ jingle/jingle.gyp
@@ -84,7 +84,7 @@
         '../third_party/libjingle/libjingle.gyp:libjingle',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk'
           ],
@@ -138,7 +138,7 @@
       # TODO(akalin): Remove this once we have our own test suite and
       # runner.
       'conditions': [
-        ['OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'dependencies': [
             # Needed to handle the #include chain:
             #   base/test/test_suite.h
