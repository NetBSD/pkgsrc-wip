$NetBSD$

don't want the 'mainwindow' binary

--- support/examples/examples.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ support/examples/examples.pro
@@ -2,5 +2,4 @@ include (../../shared.pri)
 TEMPLATE = subdirs
 SUBDIRS = \
     exampleplugin \
-    mainwindow \
     transactionlistener
