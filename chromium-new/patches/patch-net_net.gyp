$NetBSD$

--- net/net.gyp.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/net.gyp
@@ -186,7 +186,7 @@
         '<@(net_test_sources)',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'epoll_quic_tools',
             'epoll_server',
@@ -713,6 +713,11 @@
             'url_request/test_url_request_interceptor.h',
           ],
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
       # TODO(jschuh): crbug.com/167187 fix size_t to int truncations.
       'msvs_disabled_warnings': [4267, ],
