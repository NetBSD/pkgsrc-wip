$NetBSD$

From upstream pending PR:

  https://github.com/mxmlnkn/mfusepy/pull/42

with additional debugging/kludging of the refuse path.  Hence this is in wip :-)

--- mfusepy.py.orig	2026-03-13 00:36:12.000000000 +0000
+++ mfusepy.py
@@ -99,6 +99,12 @@ if not _libfuse_path:
         _libfuse_path = (
             find_library('fuse4x') or find_library('osxfuse') or find_library('fuse') or find_library('fuse-t')
         )
+    elif _system == 'NetBSD':
+        # On NetBSD 10+ librefuse implements FUSE 3, targetting 3.10 compatibility.
+        _libfuse_path = find_library('refuse')
+        print(f"_libfuse_path 001 is {_libfuse_path}")
+        _libfuse_path = 'librefuse.so.2'
+        print(f"_libfuse_path 002 is {_libfuse_path}")
     elif _system == 'Windows':
         # pytype: disable=module-attr
         try:
@@ -155,7 +161,7 @@ if fuse_version_major == 2 and fuse_vers
         f"Found library {_libfuse_path} is too old: {fuse_version_major}.{fuse_version_minor}. "
         "There have been several ABI breaks in each version. Libfuse < 2.6 is not supported!"
     )
-if fuse_version_major != 2 and not (fuse_version_major == 3 and _system == 'Linux'):
+if fuse_version_major != 2 and not (fuse_version_major == 3 and _system in ('Linux', 'NetBSD')):
     raise AttributeError(
         f"Found library {_libfuse_path} has wrong major version: {fuse_version_major}. Expected FUSE 2!"
     )
@@ -1379,7 +1385,8 @@ class FUSE:
         }
 
         argsb = [arg.encode(encoding, self.errors) for arg in args]
-        argv = (ctypes.c_char_p * len(argsb))(*argsb)
+        argc = len(argsb)
+        argv = (ctypes.c_char_p * (argc + 1))(*argsb, None)  # Null terminate explicitly
 
         alternative_callbacks = {
             "readdir": ["readdir_with_offset"],
@@ -1443,7 +1450,7 @@ class FUSE:
         except ValueError:
             old_handler = SIG_DFL
 
-        err = fuse_main_real(len(argsb), argv, ctypes.pointer(fuse_ops), ctypes.sizeof(fuse_ops), None)
+        err = fuse_main_real(argc, argv, ctypes.pointer(fuse_ops), ctypes.sizeof(fuse_ops), None)
 
         try:
             signal(SIGINT, old_handler)
