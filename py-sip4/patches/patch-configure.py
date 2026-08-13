$NetBSD$

Add PYVERSSUFFIX.
Support python >3.12.

--- configure.py.orig	2021-02-26 15:28:41.621025600 +0000
+++ configure.py
@@ -20,7 +20,7 @@ import optparse
 import os
 import glob
 import optparse
-from distutils import sysconfig
+import sysconfig
 
 try:
     from importlib import invalidate_caches
@@ -220,9 +220,9 @@ def set_platform_directories():
     global plat_py_conf_inc_dir, plat_bin_dir, plat_py_lib_dir, plat_sip_dir
 
     # We trust distutils for some stuff.
-    plat_py_site_dir = sysconfig.get_python_lib(plat_specific=1)
-    plat_py_inc_dir = sysconfig.get_python_inc()
-    plat_py_venv_inc_dir = sysconfig.get_python_inc(prefix=sys.prefix)
+    plat_py_site_dir = sysconfig.get_path('platlib')
+    plat_py_inc_dir = sysconfig.get_path('include')
+    plat_py_venv_inc_dir = sysconfig.get_path('include', vars={'base': sys.prefix, 'platbase': sys.prefix})
     plat_py_conf_inc_dir = os.path.dirname(sysconfig.get_config_h_filename())
 
     if sys.platform == "win32":
@@ -249,11 +249,11 @@ def set_platform_directories():
         plat_bin_dir = bin_dir
         plat_sip_dir = sys.prefix + "\\sip"
     else:
-        lib_dir = sysconfig.get_python_lib(plat_specific=1, standard_lib=1)
+        lib_dir = sysconfig.get_path('platstdlib')
 
         plat_py_lib_dir = lib_dir + "/config"
         plat_bin_dir = sys.exec_prefix + "/bin"
-        plat_sip_dir = sys.prefix + "/share/sip"
+        plat_sip_dir = sys.prefix + "/share/sip{}.{}".format(sys.version_info.major, sys.version_info.minor)
 
 
 def create_config(module, template, macros):
@@ -271,7 +271,7 @@ def create_config(module, template, macros):
         "sip_version":      sip_version,
         "sip_version_str":  sip_version_str,
         "platform":         build_platform,
-        "sip_bin":          os.path.join(sip_bin_dir, "sip"),
+        "sip_bin":          os.path.join(sip_bin_dir, "sip{}.{}".format(sys.version_info.major, sys.version_info.minor)),
         "sip_inc_dir":      sip_inc_dir,
         "sip_root_dir":     sip_root_dir,
         "sip_module_dir":   sip_module_dir,
