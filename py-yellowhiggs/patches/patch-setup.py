$NetBSD: patch-setup.py,v 1.1 2012/09/16 15:08:05 jihbed Exp $

--- setup.py.orig	2012-09-16 16:01:06.000000000 +0100
+++ setup.py	2012-09-16 16:02:58.000000000 +0100
@@ -32,7 +32,6 @@
       url=URL,
       download_url=DOWNLOAD_URL,
       packages=['yellowhiggs'],
-      data_files=[(prefix, ['version.txt'])],
       package_data={
           'yellowhiggs': ['dat/xs/7/*.txt',
                           'dat/xs/8/*.txt',
