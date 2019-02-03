$NetBSD$

--- setup.py.orig	2019-01-16 12:20:40.000000000 +0000
+++ setup.py
@@ -145,6 +145,6 @@ setup(
     package_dir={"cysignals": opj("src", "cysignals")},
     package_data={"cysignals": ["*.pxi", "*.pxd", "*.h"]},
     data_files=[(opj("share", "cysignals"), [opj("src", "scripts", "cysignals-CSI-helper.py")])],
-    scripts=glob(opj("src", "scripts", "cysignals-CSI")),
+    scripts=glob(opj("src", "scripts", "cysignals-CSI"+sys.version[0:3])),
     cmdclass=dict(build=build, bdist_egg=no_egg),
 )
