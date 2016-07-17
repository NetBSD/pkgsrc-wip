$NetBSD$

--- net/net_common.gypi.orig	2016-06-24 01:02:25.000000000 +0000
+++ net/net_common.gypi
@@ -235,9 +235,10 @@
         'conditions': [
           ['os_bsd==1', {
             'sources!': [
+              'base/address_tracker_linux.cc',
               'base/network_change_notifier_linux.cc',
               'base/network_change_notifier_netlink_linux.cc',
-              'proxy/proxy_config_service_linux.cc',
+#              'proxy/proxy_config_service_linux.cc',
             ],
           },{
             'dependencies': [
