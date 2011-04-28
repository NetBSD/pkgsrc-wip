$NetBSD: patch-chrome_chrome__tests.gypi,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/chrome_tests.gypi.orig	2011-04-13 08:01:59.000000000 +0000
+++ chrome/chrome_tests.gypi
@@ -149,7 +149,7 @@
         'test/unit/chrome_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -199,7 +199,7 @@
         'test/ui/ui_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -223,7 +223,7 @@
         'test/unit/run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   test/unit/run_all_unittests.cc
@@ -269,7 +269,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
@@ -346,14 +346,14 @@
         'test/unit/chrome_test_suite.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
         }],
-        ['OS=="linux" and toolkit_views==0', {
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd") and toolkit_views==0', {
           'sources!': [
             # TODO(port)
             'browser/ui/views/bookmark_bar_view_test.cc',
@@ -558,7 +558,7 @@
             '../webkit/webkit.gyp:copy_npapi_test_plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -630,7 +630,7 @@
             'browser/printing/printing_layout_uitest.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -723,7 +723,7 @@
         'test/webdriver/commands/webdriver_command.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -767,7 +767,7 @@
             },
           },
         },],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -822,7 +822,7 @@
           ],
         },],
         # Set fPIC in case it isn't set.
-        ['(OS=="linux" or OS=="openbsd" or OS=="freebsd" or OS=="solaris")'
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris")'
          'and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
           'cflags': ['-fPIC'],
         },],
@@ -1746,7 +1746,7 @@
             ['exclude', '^browser/chromeos/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['gcc_version==44', {
               # Avoid gcc 4.4 strict aliasing issues in stl_tree.h when
@@ -1790,7 +1790,7 @@
             '../views/focus/accelerator_handler_gtk_unittest.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2202,7 +2202,7 @@
             'test/plugin/pdf_browsertest.cc',
           ],
         }],
-        ['OS!="linux" or toolkit_views==1', {
+        ['(OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd") or toolkit_views==1', {
           'sources!': [
             'browser/extensions/browser_action_test_util_gtk.cc',
             'browser/ui/gtk/view_id_util_browsertest.cc',
@@ -2262,7 +2262,7 @@
             'browser/renderer_host/test/render_view_host_manager_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2299,7 +2299,7 @@
             'browser/extensions/browser_action_test_util_mac.mm',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2432,7 +2432,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2463,7 +2463,7 @@
             },
           },
         },],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2533,7 +2533,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -2570,7 +2570,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2607,7 +2607,7 @@
         'test/tab_switching/tab_switching_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2641,7 +2641,7 @@
         'test/memory_test/memory_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2792,7 +2792,7 @@
             'browser/sync/util/data_encryption_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2910,7 +2910,7 @@
       ],
       'conditions': [
         # Plugin code.
-        ['OS=="linux" or OS=="win"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="win"', {
           'dependencies': [
             'plugin',
            ],
@@ -2918,7 +2918,7 @@
             'plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3065,7 +3065,7 @@
           # See comments about "xcode_settings" elsewhere in this file.
           'xcode_settings': {'OTHER_LDFLAGS': ['-Wl,-ObjC']},
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3148,7 +3148,7 @@
             'test/perf/url_parse_perftest.cc',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
                 '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -3539,7 +3539,7 @@
                 '../courgette/courgette.gyp:courgette_unittests',
                 'browser_tests',
                 ]}],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'dependencies': [
                 # Reason for disabling UI tests on non-Linux above.
                 'ui_tests',
