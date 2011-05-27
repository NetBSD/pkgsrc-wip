$NetBSD: patch-chrome_chrome__tests.gypi,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/chrome_tests.gypi.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/chrome_tests.gypi
@@ -185,7 +185,7 @@
         '../content/common/notification_observer_mock.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -239,7 +239,7 @@
             'chrome.gyp:crash_service',  # run time dependency
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -279,7 +279,7 @@
         'test/unit/run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   test/unit/run_all_unittests.cc
@@ -325,7 +325,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
           ],
@@ -398,14 +398,14 @@
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
             'browser/ui/views/bookmarks/bookmark_bar_view_test.cc',
@@ -606,7 +606,7 @@
             '../webkit/webkit.gyp:copy_npapi_test_plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -672,7 +672,7 @@
             'browser/printing/printing_layout_uitest.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -782,7 +782,7 @@
         'test/webdriver/commands/webelement_commands.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -793,7 +793,7 @@
             '../views/views.gyp:views',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -939,7 +939,7 @@
           ],
         },],
         # Set fPIC in case it isn't set.
-        ['(OS=="linux" or OS=="openbsd" or OS=="freebsd" or OS=="solaris")'
+        ['(OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="solaris")'
          'and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
           'cflags': ['-fPIC'],
         },],
@@ -1893,7 +1893,7 @@
             ['exclude', '^browser/chromeos/'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['gcc_version==44', {
               # Avoid gcc 4.4 strict aliasing issues in stl_tree.h when
@@ -1937,7 +1937,7 @@
             '../views/focus/accelerator_handler_gtk_unittest.cc',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2362,7 +2362,7 @@
             'test/plugin/pdf_browsertest.cc',
           ],
         }],
-        ['OS!="linux" or toolkit_views==1', {
+        ['(OS!="linux" and OS!="dragonfly" and OS!="freebsd" and OS!="netbsd" and OS!="openbsd") or toolkit_views==1', {
           'sources!': [
             'browser/extensions/browser_action_test_util_gtk.cc',
             'browser/ui/gtk/view_id_util_browsertest.cc',
@@ -2420,7 +2420,7 @@
             '../content/browser/renderer_host/render_view_host_manager_browsertest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -2458,7 +2458,7 @@
             'browser/extensions/browser_action_test_util_mac.mm',
           ],
         }],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2589,7 +2589,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2620,7 +2620,7 @@
             },
           },
         },],
-        ['OS=="linux" or OS=="freebsd"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -2690,7 +2690,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -2727,7 +2727,7 @@
             },
           },
         },],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2764,7 +2764,7 @@
         'test/tab_switching/tab_switching_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2798,7 +2798,7 @@
         'test/memory_test/memory_test.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -2961,7 +2961,7 @@
             'browser/sync/util/data_encryption_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../build/linux/system.gyp:nss',
@@ -3075,7 +3075,7 @@
       ],
       'conditions': [
         # Plugin code.
-        ['OS=="linux" or OS=="win"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd" or OS=="win"', {
           'dependencies': [
             'plugin',
            ],
@@ -3083,7 +3083,7 @@
             'plugin',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3228,7 +3228,7 @@
           # See comments about "xcode_settings" elsewhere in this file.
           'xcode_settings': {'OTHER_LDFLAGS': ['-Wl,-ObjC']},
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
            'dependencies': [
              '../build/linux/system.gyp:gtk',
              '../build/linux/system.gyp:nss',
@@ -3311,7 +3311,7 @@
             'test/perf/url_parse_perftest.cc',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'dependencies': [
                 '../build/linux/system.gyp:gtk',
                 '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -3705,7 +3705,7 @@
                 '../courgette/courgette.gyp:courgette_unittests',
                 'browser_tests',
                 ]}],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or OS=="openbsd"', {
               'dependencies': [
                 # Reason for disabling UI tests on non-Linux above.
                 'ui_tests',
