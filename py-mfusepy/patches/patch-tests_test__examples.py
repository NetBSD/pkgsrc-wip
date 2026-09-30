$NetBSD$

Tests depend on ioctl_opt, not documented:
  https://github.com/mxmlnkn/mfusepy/issues/48
  https://github.com/mxmlnkn/mfusepy/pull/60

Reimplementation of PR patch, less continuing to run the tests on
Linux.  Filed upstream as a comment in the PR.

--- tests/test_examples.py.orig	2026-09-30 13:47:39.350361831 +0000
+++ tests/test_examples.py
@@ -19,7 +19,8 @@ from types import ModuleType
 from typing import Optional
 
 import pytest
-from ioctl_opt import IOWR
+#from ioctl_opt import IOWR
+ioctl_opt=None
 
 pwd: Optional[ModuleType]
 try:
@@ -248,7 +249,7 @@ def test_read_write_file_system(cli, tmp
             with open(path, 'rb') as file:
                 # Test a simple ioctl command that returns the argument incremented by one.
                 argument = 123
-                iowr_m = IOWR(ord('M'), 1, ctypes.c_uint32)
+                iowr_m = ioctl_opt.IOWR(ord('M'), 1, ctypes.c_uint32)
                 result = fcntl.ioctl(file, iowr_m, struct.pack('I', argument))
                 assert struct.unpack('I', result)[0] == argument + 1
 
