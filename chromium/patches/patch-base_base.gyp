$NetBSD: patch-base_base.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/base.gyp.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/base.gyp
@@ -20,7 +20,7 @@
         '../third_party/icu/icu.gyp:icuuc',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # i18n/rtl.cc uses gtk
             '../build/linux/system.gyp:gtk',
@@ -184,7 +184,7 @@
         '../testing/gtest.gyp:gtest',
       ],
       'conditions': [
-        ['OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'sources!': [
             'file_version_info_unittest.cc',
           ],
@@ -249,7 +249,7 @@
         '../testing/gtest.gyp:gtest',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # test_suite initializes GTK.
             '../build/linux/system.gyp:gtk',
@@ -294,7 +294,7 @@
         ],
       },
       'conditions': [
-        ['OS == "linux" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd" or OS == "solaris"', {
           'dependencies': [
             # Needed to handle the #include chain:
             #   base/test/perf_test_suite.h
