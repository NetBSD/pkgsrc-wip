$NetBSD$

--- net/net.gyp.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/net.gyp
@@ -148,7 +148,7 @@
         '<@(net_test_sources)',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'epoll_quic_tools',
             'epoll_server',
@@ -672,6 +672,11 @@
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
