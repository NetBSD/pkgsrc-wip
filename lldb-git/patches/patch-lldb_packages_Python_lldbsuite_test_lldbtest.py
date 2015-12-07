$NetBSD$

--- lldb/packages/Python/lldbsuite/test/lldbtest.py.orig	2015-12-07 21:32:38.000000000 +0000
+++ lldb/packages/Python/lldbsuite/test/lldbtest.py
@@ -2106,7 +2106,7 @@ class Base(unittest2.TestCase):
                  'FRAMEWORK_INCLUDES' : "-F%s" % lib_dir,
                  'LD_EXTRAS' : "%s -Wl,-rpath,%s" % (dsym, lib_dir),
                 }
-        elif sys.platform.startswith('freebsd') or sys.platform.startswith("linux") or os.environ.get('LLDB_BUILD_TYPE') == 'Makefile':
+        elif sys.platform.rstrip('123456789') in ('freebsd', 'linux', 'netbsd') or os.environ.get('LLDB_BUILD_TYPE') == 'Makefile':
             d = {'CXX_SOURCES' : sources,
                  'EXE' : exe_name,
                  'CFLAGS_EXTRAS' : "%s %s -I%s" % (stdflag, stdlibflag, os.path.join(os.environ["LLDB_SRC"], "include")),
