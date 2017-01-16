$NetBSD$

#Fixes an issue with the audiocd option that prevents it to build

--- src/ripper/ripper.h.orig	2017-01-16 20:27:29.624524275 +0000
+++ src/ripper/ripper.h
@@ -18,9 +18,9 @@
 #ifndef SRC_RIPPER_RIPPER_H_
 #define SRC_RIPPER_RIPPER_H_
 
-#include <cdio/cdio.h>
 #include <QMutex>
 #include <QObject>
+#include <cdio/cdio.h>
 
 #include "core/song.h"
 #include "core/tagreaderclient.h"
