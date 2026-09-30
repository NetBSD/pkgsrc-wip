$NetBSD$

Logically part of mfusepy.py patch.

--- tests/test_struct_layout.py.orig	2026-03-13 00:36:12.000000000 +0000
+++ tests/test_struct_layout.py
@@ -1,6 +1,5 @@
 import ctypes
 import os
-import platform
 import pprint
 import shutil
 import subprocess
@@ -82,8 +81,7 @@ STRUCT_NAMES = {
     ],
 }
 
-if platform.system() != 'NetBSD':
-    STRUCT_NAMES['fuse_file_info'] = ['flags', 'fh', 'lock_owner']
+STRUCT_NAMES['fuse_file_info'] = ['flags', 'fh', 'lock_owner']
 
 if mfusepy.fuse_version_major == 3:
     STRUCT_NAMES['fuse_config'] = [
@@ -188,10 +186,12 @@ def c_run(name: str, source: str) -> str
             f'-DFUSE_USE_VERSION={mfusepy.fuse_version_major}{mfusepy.fuse_version_minor}',
             '-D_FILE_OFFSET_BITS=64',
         ]
-        cflags += [f'-I{path}' for path in include_paths if os.path.exists(path)]
+        # librefuse's fuse.h is in the default include path, do not pick up the headers of a libfuse package.
+        if not mfusepy._librefuse:
+            cflags += [f'-I{path}' for path in include_paths if os.path.exists(path)]
 
         # Add possible pkg-config flags if available
-        for fuse_lib in ("fuse", "fuse3"):
+        for fuse_lib in () if mfusepy._librefuse else ("fuse", "fuse3"):
             try:
                 pkg_config_flags = subprocess.check_output(['pkg-config', '--cflags', fuse_lib], text=True).split()
                 cflags.extend(pkg_config_flags)
