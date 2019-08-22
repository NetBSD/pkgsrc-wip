$NetBSD$

Fix path to llvm-config executable.

--- common.py.orig	2019-08-07 16:39:16.000000000 +0000
+++ common.py
@@ -65,7 +65,7 @@ else:
     default_llvm = 'no'
     try:
         if target_platform != 'windows' and \
-           subprocess.call(['llvm-config', '--version'],
+           subprocess.call(['@LLVM_CONFIG_PATH@', '--version'],
                            stdout=subprocess.PIPE) == 0:
             default_llvm = 'yes'
     except:
