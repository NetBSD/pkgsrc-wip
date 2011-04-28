$NetBSD: patch-testing_gtest.gyp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- testing/gtest.gyp.orig	2011-04-13 08:01:10.000000000 +0000
+++ testing/gtest.gyp
@@ -62,7 +62,7 @@
             ],
           },
         }],
-        ['OS == "mac" or OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        ['OS == "mac" or OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'defines': [
             # gtest isn't able to figure out when RTTI is disabled for gcc
             # versions older than 4.3.2, and assumes it's enabled.  Our Mac
