$NetBSD: patch-net_net.gyp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- net/net.gyp.orig	2011-05-24 08:01:15.000000000 +0000
+++ net/net.gyp
@@ -241,11 +241,23 @@
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
+        [ 'OS == "linux" or OS == "netbsd"', {
+            'dependencies': [
+              '../build/linux/system.gyp:libresolv',
+            ],
+        }],
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
-              '../build/linux/system.gyp:libresolv',
             ],
             'conditions': [
               ['use_openssl==1', {
@@ -777,7 +789,7 @@
             ],
           },
         ],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
@@ -1011,7 +1023,7 @@
              'proxy/proxy_config_service_linux_unittest.cc',
           ],
         }],
-        [ 'OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
             'dependencies': [
               '../build/linux/system.gyp:gtk',
               '../build/linux/system.gyp:nss',
@@ -1023,7 +1035,7 @@
             ],
           }
         ],
-        [ 'OS == "linux"', {
+        [ 'OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -1183,7 +1195,7 @@
             '../third_party/protobuf/protobuf.gyp:py_proto',
           ],
         }],
-        ['OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
+        ['OS == "linux" or OS == "dragonfly" or OS == "freebsd" or OS == "netbsd" or OS == "openbsd"', {
           'conditions': [
             ['use_openssl==1', {
               'dependencies': [
@@ -1195,8 +1207,6 @@
               ],
             }],
           ],
-        }],
-        ['OS == "linux"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
