$NetBSD$

Avoid to invoke preexec_fn on NetBSD.

It fails due some exception.

Easily reproducible via:

 python3 -c 'import pwn; pwn.process("true")'

--- pwnlib/tubes/process.py.orig	2025-03-24 12:20:18.000000000 +0000
+++ pwnlib/tubes/process.py
@@ -14,6 +14,7 @@ import sys
 import time
 from collections import namedtuple
 
+IS_NETBSD = sys.platform.startswith('netbsd')
 IS_WINDOWS = sys.platform.startswith('win')
 
 if IS_WINDOWS:
@@ -307,7 +308,26 @@ class process(tube):
             # Create the PTY if necessary
             stdin, stdout, stderr, master, slave = self._handles(*handles)
 
-            internal_preexec_fn = self.__preexec_fn
+            if IS_NETBSD:
+                # XXX: On NetBSD running
+                # XXX:  `python3 -c 'import pwn; pwn.process("true")'`
+                # XXX: Fails with:
+                # XXX: [-] Starting local process '/usr/bin/true': Failed
+                # XXX: Traceback (most recent call last):
+                # XXX:   File "<string>", line 1, in <module>
+                # XXX:   File "/usr/pkg/lib/python3.12/site-packages/pwnlib/tubes/process.py", line 359, in __init__
+                # XXX:     self.proc = subprocess.Popen(args = args,
+                # XXX:                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
+                # XXX:   File "/usr/pkg/lib/python3.12/subprocess.py", line 1026, in __init__
+                # XXX:     self._execute_child(args, executable, preexec_fn, close_fds,
+                # XXX:   File "/usr/pkg/lib/python3.12/subprocess.py", line 1958, in _execute_child
+                # XXX:     raise child_exception_type(err_msg)
+                # XXX: subprocess.SubprocessError: Exception occurred in preexec_fn.
+                # XXX: Avoid to use the self.__preexec_fn completely.
+                # XXX: This should be investigated and addressed properly!
+                internal_preexec_fn = None
+            else:
+                internal_preexec_fn = self.__preexec_fn
 
         #: Arguments passed on argv
         self.argv = argv_val
