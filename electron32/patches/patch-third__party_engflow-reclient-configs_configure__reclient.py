$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/engflow-reclient-configs/configure_reclient.py.orig	2023-12-20 16:48:43.000000000 +0000
+++ third_party/engflow-reclient-configs/configure_reclient.py
@@ -21,6 +21,7 @@ import os
 import re
 import runpy
 import shutil
+import stat
 import string
 import subprocess
 import sys
@@ -109,6 +110,8 @@ class ReclientConfigurator:
             self.download_linux_clang_toolchain()
             self.generate_clang_remote_wrapper()
 
+        self.generate_python_remote_wrapper()
+
         # Reproxy config includes auth and network-related parameters.
         self.generate_reproxy_cfg()
         # Rewrapper configs describe how different tools should be run remotely.
@@ -199,6 +202,32 @@ class ReclientConfigurator:
             (f'{Paths.src_dir}/buildtools/reclient_cfgs/chromium-browser-clang/'
              'clang_remote_wrapper'), clang_remote_wrapper)
 
+        FileUtils.chmod_x((f'{Paths.src_dir}/buildtools/reclient_cfgs/chromium-browser-clang/'
+             'clang_remote_wrapper'))
+
+    @staticmethod
+    def generate_python_remote_wrapper():
+        # Load python remote wrapper template.
+        template_file = (f'{Paths.script_dir}/python/'
+                         'python_remote_wrapper.template')
+        python_remote_wrapper_template = FileUtils.read_text_file(template_file)
+
+        # Variables to set in the template.
+        template_vars = {
+        }
+
+        # Substitute variables into the template.
+        python_remote_wrapper = ShellTemplate(
+            python_remote_wrapper_template).substitute(template_vars)
+
+        # Write the python remote wrapper.
+        FileUtils.write_text_file(
+            (f'{Paths.src_dir}/buildtools/reclient_cfgs/python/'
+             'python_remote_wrapper'), python_remote_wrapper)
+
+        FileUtils.chmod_x((f'{Paths.src_dir}/buildtools/reclient_cfgs/python/'
+             'python_remote_wrapper'))
+
     def generate_reproxy_cfg(self):
         # Load Chromium config template and remove everything starting with $
         # symbol on each line.
@@ -268,6 +297,11 @@ class ReclientConfigurator:
             f'{Paths.reclient_cfgs_dir}/{tool}/rewrapper_{host_os}.cfg',
             rewrapper_cfg, source_cfg_paths)
 
+        # Write "large" configs to the expected location.
+        ReclientCfg.write_to_file(
+            f'{Paths.reclient_cfgs_dir}/{tool}/rewrapper_{host_os}_large.cfg',
+            rewrapper_cfg, source_cfg_paths)
+
 
 class Paths:
     script_dir = ''
@@ -537,6 +571,11 @@ class FileUtils:
         shutil.move(filepath_new, filepath)
 
     @classmethod
+    def chmod_x(cls, filepath):
+        st = os.stat(filepath)
+        os.chmod(filepath, st.st_mode | stat.S_IEXEC)
+
+    @classmethod
     def create_generated_header(cls, source_files):
         if not isinstance(source_files, (list, tuple)):
             source_files = (source_files, )
