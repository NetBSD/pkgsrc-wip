$NetBSD$

--- base/base.gypi.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/base.gypi
@@ -502,6 +502,7 @@
           'process/process_handle_freebsd.cc',
           'process/process_handle_linux.cc',
           'process/process_handle_mac.cc',
+          'process/process_handle_netbsd.cc',
           'process/process_handle_openbsd.cc',
           'process/process_handle_posix.cc',
           'process/process_handle_win.cc',
@@ -514,6 +515,7 @@
           'process/process_iterator_freebsd.cc',
           'process/process_iterator_linux.cc',
           'process/process_iterator_mac.cc',
+          'process/process_iterator_netbsd.cc',
           'process/process_iterator_openbsd.cc',
           'process/process_iterator_win.cc',
           'process/process_linux.cc',
@@ -524,6 +526,7 @@
           'process/process_metrics_linux.cc',
           'process/process_metrics_mac.cc',
           'process/process_metrics_nacl.cc',
+          'process/process_metrics_netbsd.cc',
           'process/process_metrics_openbsd.cc',
           'process/process_metrics_posix.cc',
           'process/process_metrics_win.cc',
@@ -627,6 +630,7 @@
           'sys_info_ios.mm',
           'sys_info_linux.cc',
           'sys_info_mac.mm',
+          'sys_info_netbsd.cc',
           'sys_info_openbsd.cc',
           'sys_info_posix.cc',
           'sys_info_win.cc',
@@ -971,6 +975,10 @@
               'sources/': [ ['exclude', '_openbsd\\.cc$'] ],
             },
           ],
+          ['OS != "netbsd" or >(nacl_untrusted_build)==1', {
+              'sources/': [ ['exclude', '_netbsd\\.cc$'] ],
+            },
+          ],
           ['OS == "win" and >(nacl_untrusted_build)==0', {
             'include_dirs': [
               '<(DEPTH)/third_party/wtl/include',
@@ -1021,11 +1029,17 @@
               'process/memory_stubs.cc',
             ],
             'sources/': [
+              ['exclude', '^debug/proc_maps_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_linux\\.cc$'],
-              ['exclude', '^files/file_path_watcher_stub\\.cc$'],
               ['exclude', '^files/file_util_linux\\.cc$'],
+              ['exclude', '^process/memory_linux\\.cc$'],
               ['exclude', '^process/process_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
+              ['exclude', '^process/process_handle_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
+              ['exclude', '^files/file_path_watcher_fsevents\\.cc$'],
+              ['exclude', '^files/file_path_watcher_fsevents\\.h$'],
             ],
           }],
           # Remove all unnecessary files for build_nexe.py to avoid exceeding
