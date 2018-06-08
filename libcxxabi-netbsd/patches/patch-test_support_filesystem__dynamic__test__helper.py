$NetBSD$

--- test/support/filesystem_dynamic_test_helper.py.orig	2018-06-07 17:10:26.000000000 +0000
+++ test/support/filesystem_dynamic_test_helper.py
@@ -4,7 +4,8 @@ import stat
 
 # Ensure that this is being run on a specific platform
 assert sys.platform.startswith('linux') or sys.platform.startswith('darwin') \
-    or sys.platform.startswith('cygwin') or sys.platform.startswith('freebsd')
+    or sys.platform.startswith('cygwin') or sys.platform.startswith('freebsd') \
+    or sys.platform.startswith('netbsd')
 
 def env_path():
     ep = os.environ.get('LIBCXX_FILESYSTEM_DYNAMIC_TEST_ROOT')
