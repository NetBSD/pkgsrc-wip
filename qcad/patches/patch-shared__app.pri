$NetBSD$

--- shared_app.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ shared_app.pri
@@ -1,24 +1,24 @@
 include($$PWD/shared.pri)

 LIBS += \
-    -l$${RLIBNAME}ecmaapi \
-    -l$${RLIBNAME}gui \
-    -l$${RLIBNAME}entity \
-    -l$${RLIBNAME}operations \
-    -l$${RLIBNAME}spatialindex \
-    -lspatialindexnavel \
-    -l$${RLIBNAME}grid \
-    -l$${RLIBNAME}snap \
-    -l$${RLIBNAME}core \
-    -l$${RLIBNAME}stemmer \
-    -lstemmer \
-    -l$${RLIBNAME}zip \
-    -lquazip
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}ecmaapi$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}gui$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}operations$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}spatialindex$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}spatialindexnavel$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}grid$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}snap$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}stemmer$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}stemmer$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}$${RLIBNAME}zip$${RLIBPOSTDLL} \
+    $${DESTDIR}/$${RLIBPRE}quazip$${RLIBPOSTDLL}

 !r_no_opennurbs {
     LIBS += \
-        -lopennurbs \
-        -lzlib
+        $${DESTDIR}/$${RLIBPRE}opennurbs$${RLIBPOSTDLL} \
+        $${DESTDIR}/$${RLIBPRE}zlib$${RLIBPOSTDLL}
 }

 win32 {
