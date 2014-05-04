$NetBSD: patch-setup.py,v 1.1 2014/05/04 00:27:26 jihbed Exp $

--- setup.py.orig	2014-05-04 01:23:19.000000000 +0100
+++ setup.py	2014-05-04 01:24:01.000000000 +0100
@@ -44,6 +44,4 @@
                       'alea',
                       'tlea',
                       'license' ] ,
-       data_files = [('.', [ 'COPYING',
-                             'COPYING.LESSER' ] ) ],
       )
\ No newline at end of file
