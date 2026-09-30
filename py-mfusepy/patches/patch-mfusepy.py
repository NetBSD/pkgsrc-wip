$NetBSD$

From upstream pending PR, less CI hunk and hunk for code added
since 3.1.1:

  https://github.com/mxmlnkn/mfusepy/pull/59

--- mfusepy.py.orig	2026-03-13 00:36:12.000000000 +0000
+++ mfusepy.py
@@ -99,6 +99,11 @@ if not _libfuse_path:
         _libfuse_path = (
             find_library('fuse4x') or find_library('osxfuse') or find_library('fuse') or find_library('fuse-t')
         )
+    elif _system == 'NetBSD':
+        # On NetBSD 10+ librefuse implements FUSE 3, targeting 3.10 compatibility.
+        # On NetBSD, find_library only works if a C compiler or ld is in PATH (and e.g. not within pkgsrc builds,
+        # where the compiler wrappers drop -lrefuse), so fall back to the soname of the base system library.
+        _libfuse_path = find_library('refuse') or 'librefuse.so.2'
     elif _system == 'Windows':
         # pytype: disable=module-attr
         try:
@@ -139,6 +144,10 @@ _libfuse = ctypes.CDLL(_libfuse_path)
 if _system == 'Darwin' and hasattr(_libfuse, 'macfuse_version'):
     _system = 'Darwin-MacFuse'
 
+# NetBSD's librefuse is a FUSE reimplementation on top of puffs (no perfused daemon needed).
+# Its struct layouts differ from libfuse and are fixed, i.e. independent of the FUSE API version.
+_librefuse = _system == 'NetBSD' and hasattr(_libfuse, '__fuse_main')
+
 
 def get_fuse_version(libfuse):
     version = libfuse.fuse_version()
@@ -155,7 +164,7 @@ if fuse_version_major == 2 and fuse_vers
         f"Found library {_libfuse_path} is too old: {fuse_version_major}.{fuse_version_minor}. "
         "There have been several ABI breaks in each version. Libfuse < 2.6 is not supported!"
     )
-if fuse_version_major != 2 and not (fuse_version_major == 3 and _system == 'Linux'):
+if fuse_version_major != 2 and not (fuse_version_major == 3 and _system in ('Linux', 'NetBSD')):
     raise AttributeError(
         f"Found library {_libfuse_path} has wrong major version: {fuse_version_major}. Expected FUSE 2!"
     )
@@ -747,56 +756,25 @@ _fuse_int32 = ctypes.c_int32 if (fuse_ve
 _fuse_uint32 = ctypes.c_uint32 if (fuse_version_major, fuse_version_minor) >= (3, 17) else ctypes.c_uint
 _fuse_file_info_fields_: list[FieldsEntry] = []
 _fuse_file_info_fields_bitfield: list[BitFieldsEntry] = []
-# Bogus check. It fixes the struct for NetBSD, but it makes the examples not run anymore!
-if _system == 'NetBSD_False':
-    # NetBSD has its own FUSE library reimplementation with mismatching struct layouts!
-    # writepage is a bitfield (as in libFUSE 3.x), but the fh_old member still exists and the reported version is 2.9!
-    # https://www.netbsd.org/docs/puffs/
+if _librefuse:
+    # librefuse has one fuse_file_info layout for all API versions: fh_old still exists (removed in FUSE 3),
+    # writepage is a bitfield and poll_events exists (both as in FUSE 3).
     # https://github.com/NetBSD/src/blob/netbsd-11/lib/librefuse/fuse.h#L100-L129
-    # https://github.com/NetBSD/src/blob/netbsd-10/lib/librefuse/fuse.h#L100-L129
-    #  - fuse_file_info is unchanged between 10 and 11
-    #  - FUSE_USE_VERSION is not set, but is set to _REFUSE_VERSION_ (3.10) with a warning if not set!
-    #  - However, the CI prints FUSE version 2.9?!
-    #  - Seems there is no sane way to get the correct compiled version! This is again an absolute shit show!
-    # https://github.com/NetBSD/src/blob/netbsd-9/lib/librefuse/fuse.h#L51-L61
-    #  - fuse_file_info looks quite different and version is specified as 2.6!
-    #  - #define FUSE_USE_VERSION 26
-    fuse_version = (fuse_version_major, fuse_version_minor)
     _fuse_file_info_fields_ = [
         ('flags', ctypes.c_int32),
         ('fh_old', ctypes.c_uint32),
-    ]
-
-    if fuse_version >= (2, 9):
-        _fuse_file_info_fields_bitfield += [('writepage', ctypes.c_int32, 1)]
-    else:
-        _fuse_file_info_fields_ += [('writepage', ctypes.c_int32)]
-
-    _fuse_file_info_fields_bitfield += [
-        ('direct_io', ctypes.c_uint32, 1),  # Introduced in FUSE 2.4
-        ('keep_cache', ctypes.c_uint32, 1),  # Introduced in FUSE 2.4
-        ('flush', ctypes.c_uint32, 1),  # Introduced in FUSE 2.6
-    ]
-    if fuse_version >= (2, 9):
-        _fuse_file_info_fields_bitfield += [
-            ('nonseekable', ctypes.c_uint, 1),  # Introduced in FUSE 2.8
-            ('flock_release', ctypes.c_uint, 1),  # Introduced in FUSE 2.9
-            ('cache_readdir', ctypes.c_uint, 1),  # Introduced in FUSE 3.5
-        ]
-
-    _fuse_file_info_flag_count = sum(x[2] for x in _fuse_file_info_fields_bitfield)
-    assert _fuse_file_info_flag_count < ctypes.sizeof(_fuse_uint32) * 8
-
-    _fuse_file_info_fields_ += _fuse_file_info_fields_bitfield
-    _fuse_file_info_fields_ += [
-        ('padding', _fuse_uint32, ctypes.sizeof(_fuse_uint32) * 8 - _fuse_file_info_flag_count),
+        ('writepage', ctypes.c_uint32, 1),
+        ('direct_io', ctypes.c_uint32, 1),
+        ('keep_cache', ctypes.c_uint32, 1),
+        ('flush', ctypes.c_uint32, 1),
+        ('nonseekable', ctypes.c_uint32, 1),
+        ('flock_release', ctypes.c_uint32, 1),
+        ('cache_readdir', ctypes.c_uint32, 1),
+        ('padding', ctypes.c_uint32, 25),
         ('fh', ctypes.c_uint64),
         ('lock_owner', ctypes.c_uint64),
+        ('poll_events', ctypes.c_uint32),
     ]
-
-    if fuse_version >= (2, 9):
-        _fuse_file_info_fields_ += [('poll_events', ctypes.c_uint32)]
-
 elif fuse_version_major == 2:
     _fh_old_type = ctypes.c_uint if _system == 'OpenBSD' else ctypes.c_ulong
     _fuse_file_info_fields_ = [
@@ -937,14 +915,12 @@ _fuse_conn_info_fields: list[FieldsEntry
     ('proto_major', ctypes.c_uint),
     ('proto_minor', ctypes.c_uint),
 ]
-# For some reason, NetBSD return 2.9 even though the API is 3.10!
-# The correct version is important for the struct layout!
-# https://github.com/NetBSD/src/blob/netbsd-10/lib/librefuse/fuse.h#L58-L59
-# However, the fuse_operations layout probably fits the advertised version because I had segfaults from utimens!
-if fuse_version_major == 2 or _system == 'NetBSD':  # No idea why NetBSD did not remove it -.-
+# librefuse has one fuse_conn_info layout for all API versions, containing the FUSE 2 and FUSE 3 members.
+# https://github.com/NetBSD/src/blob/netbsd-11/lib/librefuse/fuse.h
+if fuse_version_major == 2 or _librefuse:
     _fuse_conn_info_fields += [('async_read', _fuse_uint32)]
 _fuse_conn_info_fields += [('max_write', _fuse_uint32)]
-if fuse_version_major == 3 or _system == 'NetBSD':
+if fuse_version_major == 3 or _librefuse:
     _fuse_conn_info_fields += [('max_read', _fuse_uint32)]
 _fuse_conn_info_fields += [('max_readahead', _fuse_uint32)]
 if _system == 'Darwin':
@@ -955,11 +931,11 @@ _fuse_conn_info_fields += [
     ('max_background', _fuse_uint32),  # Added in 2.9
     ('congestion_threshold', _fuse_uint32),  # Added in 2.9
 ]
-if fuse_version_major == 2 and _system != 'NetBSD':
+if fuse_version_major == 2 and not _librefuse:
     _fuse_conn_info_fields += [('reserved', _fuse_uint32 * (22 if _system == 'Darwin' else 23))]
-elif fuse_version_major == 3 or _system == 'NetBSD':
+elif fuse_version_major == 3 or _librefuse:
     _fuse_conn_info_fields += [('time_gran', _fuse_uint32)]
-    if fuse_version_minor < 17 or _system == 'NetBSD':
+    if fuse_version_minor < 17 or _librefuse:
         _fuse_conn_info_fields += [('reserved', _fuse_uint32 * 22)]
     else:
         _fuse_conn_info_fields += [
@@ -1037,7 +1013,7 @@ if fuse_version_major == 3:
     if fuse_version_minor >= 15 and fuse_version_minor < 17:
         _fuse_config_fields_ += [('parallel_direct_writes', ctypes.c_int)]
 
-    if _system != 'NetBSD':
+    if not _librefuse:
         _fuse_config_fields_ += [
             ('show_help', _fuse_int32),
             ('modules', ctypes.c_char_p),
@@ -1243,6 +1219,15 @@ if _system == "OpenBSD":
     def fuse_main_real(argc, argv, fuse_ops_v, sizeof_fuse_ops, ctx_p):
         return _libfuse.fuse_main(argc, argv, fuse_ops_v, ctx_p)
 
+elif _librefuse:
+    # librefuse's fuse_main_real is only a shim for binaries built against FUSE 2.6: it always interprets
+    # the operations as struct fuse_operations_v26. __fuse_main takes the layout version instead of the size.
+    # The FUSE 3 fuse_operations defined above is struct fuse_operations_v38 (used for FUSE_USE_VERSION 38..310).
+    _REFUSE_OP_VERSION = 38
+
+    def fuse_main_real(argc, argv, fuse_ops_v, sizeof_fuse_ops, ctx_p):
+        return getattr(_libfuse, '__fuse_main')(argc, argv, fuse_ops_v, _REFUSE_OP_VERSION, ctx_p)
+
 else:
     fuse_main_real = _libfuse.fuse_main_real
 
@@ -1379,7 +1364,8 @@ class FUSE:
         }
 
         argsb = [arg.encode(encoding, self.errors) for arg in args]
-        argv = (ctypes.c_char_p * len(argsb))(*argsb)
+        argc = len(argsb)
+        argv = (ctypes.c_char_p * (argc + 1))(*argsb, None)  # Null terminate explicitly
 
         alternative_callbacks = {
             "readdir": ["readdir_with_offset"],
@@ -1443,7 +1429,7 @@ class FUSE:
         except ValueError:
             old_handler = SIG_DFL
 
-        err = fuse_main_real(len(argsb), argv, ctypes.pointer(fuse_ops), ctypes.sizeof(fuse_ops), None)
+        err = fuse_main_real(argc, argv, ctypes.pointer(fuse_ops), ctypes.sizeof(fuse_ops), None)
 
         try:
             signal(SIGINT, old_handler)
