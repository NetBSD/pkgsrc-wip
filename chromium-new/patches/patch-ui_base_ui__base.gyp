$NetBSD$

--- ui/base/ui_base.gyp.orig	2016-06-24 01:02:52.000000000 +0000
+++ ui/base/ui_base.gyp
@@ -456,7 +456,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
@@ -480,7 +480,7 @@
             '../../build/linux/system.gyp:glib',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['toolkit_views==0 and use_aura==0', {
               # Note: because of gyp predence rules this has to be defined as
@@ -513,7 +513,7 @@
             'clipboard/clipboard_aurax11.cc',
           ],
         }],
-        ['chromeos==1 or (use_aura==1 and OS=="linux" and use_x11==0)', {
+        ['chromeos==1 or (use_aura==1 and (OS=="linux" or os_bsd==1) and use_x11==0)', {
           'sources!': [
             'dragdrop/os_exchange_data_provider_aurax11.cc',
           ],
