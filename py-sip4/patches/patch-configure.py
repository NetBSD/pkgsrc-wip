$NetBSD$

Add PYVERSSUFFIX.

--- configure.py.orig	2018-10-01 13:22:40.000000000 +0000
+++ configure.py
@@ -250,7 +250,7 @@ def set_platform_directories():
 
         plat_py_lib_dir = lib_dir + "/config"
         plat_bin_dir = sys.exec_prefix + "/bin"
-        plat_sip_dir = sys.prefix + "/share/sip"
+        plat_sip_dir = sys.prefix + "/share/sip{}.{}".format(sys.version_info.major, sys.version_info.minor)
 
 
 def create_config(module, template, macros):
@@ -268,7 +268,7 @@ def create_config(module, template, macr
         "sip_version":      sip_version,
         "sip_version_str":  sip_version_str,
         "platform":         build_platform,
-        "sip_bin":          os.path.join(sip_bin_dir, "sip"),
+        "sip_bin":          os.path.join(sip_bin_dir, "sip{}.{}".format(sys.version_info.major, sys.version_info.minor)),
         "sip_inc_dir":      sip_inc_dir,
         "sip_root_dir":     sip_root_dir,
         "sip_module_dir":   sip_module_dir,
