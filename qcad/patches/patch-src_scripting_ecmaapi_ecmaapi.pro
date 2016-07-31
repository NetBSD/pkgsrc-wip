$NetBSD$

--- src/scripting/ecmaapi/ecmaapi.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/scripting/ecmaapi/ecmaapi.pro
@@ -19,13 +19,13 @@ SOURCES += \
 include(adapters/adapters.pri)
 include(generated/generated.pri)
 LIBS += \
-    -l$${RLIBNAME}core \
-    -l$${RLIBNAME}entity \
-    -l$${RLIBNAME}grid \
-    -l$${RLIBNAME}gui \
-    -l$${RLIBNAME}operations \
-    -l$${RLIBNAME}snap \
-    -l$${RLIBNAME}spatialindex \
-    -l$${RLIBNAME}stemmer \
-    -l$${RLIBNAME}zip \
-    -lquazip
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}core$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}entity$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}grid$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}gui$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}operations$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}snap$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}spatialindex$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}stemmer$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}$${RLIBNAME}zip$${RLIBPOSTDLL} \
+    ../../../$${ROUTDIR}/$${RLIBPRE}quazip$${RLIBPOSTDLL}
