$NetBSD: patch-src_install.pri,v 1.4 2014/12/04 15:51:25 nros Exp $
* Install bash completion correctly
* Dont' install appdata files
--- src/install.pri.orig	2014-11-03 20:21:24.000000000 +0000
+++ src/install.pri
@@ -44,14 +44,14 @@ mac {
     ico256.path = $$hicolor_folder/256x256/apps
 
     bashcompletion.files = $$PWD/../linux/completion/qupzilla
-    bashcompletion.path = /usr/share/bash-completion/completions
+    bashcompletion.path = $$bashcompletion_folder
 
-    appdata.files = $$PWD/../linux/appdata/qupzilla.appdata.xml
-    appdata.path = /usr/share/appdata
+#    appdata.files = $$PWD/../linux/appdata/qupzilla.appdata.xml
+#    appdata.path = /usr/share/appdata
 
 
     INSTALLS += target target1 target2 target3
     INSTALLS += ico16 ico32 ico48 ico64 ico128 ico256
     INSTALLS += bashcompletion
-    INSTALLS += appdata
+#    INSTALLS += appdata
 }
