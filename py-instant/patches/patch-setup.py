$NetBSD$

--- setup.py.orig	2017-05-09 12:36:50.000000000 +0000
+++ setup.py
@@ -12,8 +12,8 @@ if sys.version_info < (2, 7):
     print("Python 2.7 or higher required, please upgrade.")
     sys.exit(1)
 
-scripts = [join("scripts", "instant-clean"),
-           join("scripts", "instant-showcache")]
+scripts = [join("scripts", "instant-clean"+sys.version[0:3]),
+           join("scripts", "instant-showcache"+sys.version[0:3])]
 
 if platform.system() == "Windows" or "bdist_wininst" in sys.argv:
     # In the Windows command prompt we can't execute Python scripts
@@ -72,7 +72,7 @@ setup(name="instant",
       package_data={'': [join('swig', 'numpy.i')]},
       scripts=scripts,
       install_requires=requires,
-      data_files=[(join("share", "man", "man1"),
+      data_files=[(join("man", "man1"),
                    [join("doc", "man", "man1", "instant-clean.1.gz"),
                     join("doc", "man", "man1", "instant-showcache.1.gz")])]
       )
