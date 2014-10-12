$NetBSD: patch-src_install.pri,v 1.3 2014/10/12 17:12:13 nros Exp $

 Don't install bash completion files since they install outside 
 localbase. 

--- src/install.pri.orig	2014-10-08 12:33:31.000000000 +0000
+++ src/install.pri
@@ -43,15 +43,15 @@ mac {
     ico256.files = $$PWD/../linux/hicolor/256x256/apps/qupzilla.png
     ico256.path = $$hicolor_folder/256x256/apps
 
-    bashcompletion.files = $$PWD/../linux/completion/qupzilla
-    bashcompletion.path = /usr/share/bash-completion/completions
+#    bashcompletion.files = $$PWD/../linux/completion/qupzilla
+#    bashcompletion.path = /usr/share/bash-completion/completions
 
-    appdata.files = $$PWD/../linux/appdata/qupzilla.appdata.xml
-    appdata.path = /usr/share/appdata
+#    appdata.files = $$PWD/../linux/appdata/qupzilla.appdata.xml
+#    appdata.path = /usr/share/appdata
 
 
     INSTALLS += target target1 target2 target3
     INSTALLS += ico16 ico32 ico48 ico64 ico128 ico256
-    INSTALLS += bashcompletion
-    INSTALLS += appdata
+#    INSTALLS += bashcompletion
+#    INSTALLS += appdata
 }
