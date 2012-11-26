$NetBSD: patch-doc_doc.pri,v 1.1 2012/11/26 01:05:11 fwsf Exp $

Add a separate $PREFIX to the install paths, as qmake only supports
a single $INSTALL_ROOT prefix. By setting $INSTALL_ROOT to $DESTDIR
this enables DESTDIR support and fixes the library paths.

--- doc/doc.pri.orig	2012-08-08 13:47:06.000000000 +0000
+++ doc/doc.pri
@@ -69,12 +69,12 @@ dev_qch_docs.depends += dev_html_docs
 
 !macx {
     inst_qch_docs.files = $$QCH_FILE
-    inst_qch_docs.path = /share/doc/qtcreator
+    inst_qch_docs.path = $$(PREFIX)/share/doc/qtcreator
     inst_qch_docs.CONFIG += no_check_exist no_default_install
     INSTALLS += inst_qch_docs
 
     inst_dev_qch_docs.files = $$DEV_QCH_FILE
-    inst_dev_qch_docs.path = /share/doc/qtcreator
+    inst_dev_qch_docs.path = $$(PREFIX)/share/doc/qtcreator
     inst_dev_qch_docs.CONFIG += no_check_exist no_default_install
     INSTALLS += inst_dev_qch_docs
 
