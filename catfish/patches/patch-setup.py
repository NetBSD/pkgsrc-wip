$NetBSD$

# Install man page into man/ instead of share/man/

--- setup.py.orig	2019-01-27 11:46:47.000000000 +0000
+++ setup.py
@@ -209,7 +209,7 @@ DistUtilsExtra.auto.setup(
                      'needs by using several command line options.',
     url='https://docs.xfce.org/apps/catfish/start',
     data_files=[
-        ('share/man/man1', ['catfish.1']),
+        ('man/man1', ['catfish.1']),
         ('share/metainfo/', ['data/metainfo/catfish.appdata.xml'])
     ],
     cmdclass={'install': InstallAndUpdateDataDirectory}
