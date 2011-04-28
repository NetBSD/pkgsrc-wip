$NetBSD: patch-net_net.gyp,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/net.gyp.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/net.gyp
@@ -238,7 +238,15 @@
         },
       ],
       'conditions': [
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
+          'sources!': [
+            'base/network_change_notifier_linux.cc',
+            'base/network_change_notifier_linux.h',
+            'base/network_change_notifier_netlink_linux.cc',
+            'base/network_change_notifier_netlink_linux.h',
+          ],
+        }],
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
@@ -772,7 +780,7 @@
             ],
           },
         ],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
@@ -1014,7 +1022,7 @@
              'proxy/proxy_config_service_linux_unittest.cc',
           ],
         }],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gtk',
               '../build/linux/system.gyp:nss',
@@ -1029,7 +1037,7 @@
             ],
           }
         ],
-        [ 'OS == "linux"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -1181,7 +1189,7 @@
             '../third_party/protobuf/protobuf.gyp:py_proto',
           ],
         }],
-        ['OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'conditions': [
             ['use_openssl==1', {
               'dependencies': [
@@ -1193,8 +1201,6 @@
               ],
             }],
           ],
-        }],
-        ['OS == "linux"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
