$NetBSD$

--- tools/gn/bootstrap/bootstrap.py.orig	2016-08-05 17:36:04.000000000 +0000
+++ tools/gn/bootstrap/bootstrap.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python2.7
 # Copyright 2014 The Chromium Authors. All rights reserved.
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
@@ -31,8 +31,9 @@ SRC_ROOT = os.path.dirname(os.path.dirna
 
 is_win = sys.platform.startswith('win')
 is_linux = sys.platform.startswith('linux')
+is_netbsd = sys.platform.startswith('netbsd')
 is_mac = sys.platform.startswith('darwin')
-is_posix = is_linux or is_mac
+is_posix = is_linux or is_mac or is_netbsd
 
 def check_call(cmd, **kwargs):
   logging.debug('Running: %s', ' '.join(cmd))
@@ -183,7 +184,7 @@ def build_gn_with_ninja_manually(tempdir
 
   write_gn_ninja(os.path.join(tempdir, 'build.ninja'),
                  root_gen_dir, options)
-  cmd = ['ninja', '-C', tempdir]
+  cmd = ['ninja', '-C', tempdir, '-v']
   if options.verbose:
     cmd.append('-v')
 
@@ -620,6 +621,37 @@ def write_gn_ninja(path, root_gen_dir, o
         '-framework', 'Security',
     ])
 
+  if is_netbsd:
+    libs.extend(['-lrt', '-lexecinfo'])
+    ldflags.extend(['-lpthread'])
+
+    static_libraries['xdg_user_dirs'] = {
+        'sources': [
+            'base/third_party/xdg_user_dirs/xdg_user_dir_lookup.cc',
+        ],
+        'tool': 'cxx',
+    }
+    static_libraries['base']['sources'].extend([
+#        'base/allocator/allocator_shim.cc',
+#        'base/allocator/allocator_shim_default_dispatch_to_glibc.cc',
+        'base/memory/shared_memory_posix.cc',
+        'base/nix/xdg_util.cc',
+        'base/process/process_handle_netbsd.cc',
+        'base/process/process_iterator_netbsd.cc',
+        'base/process/process_posix.cc',
+        'base/process/process_metrics_netbsd.cc',
+        'base/strings/sys_string_conversions_posix.cc',
+        'base/sys_info_netbsd.cc',
+        'base/threading/platform_thread_netbsd.cc',
+        'base/trace_event/malloc_dump_provider.cc',
+    ])
+    static_libraries['libevent']['include_dirs'].extend([
+        os.path.join(SRC_ROOT, 'base', 'third_party', 'libevent', 'freebsd')
+    ])
+    static_libraries['libevent']['sources'].extend([
+        'base/third_party/libevent/kqueue.c',
+    ])
+
   if is_win:
     static_libraries['base']['sources'].extend([
         'base/base_paths_win.cc',
