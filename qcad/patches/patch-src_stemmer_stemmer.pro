$NetBSD$

--- src/stemmer/stemmer.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/stemmer/stemmer.pro
@@ -7,8 +7,6 @@ HEADERS = \
 TEMPLATE = lib
 CONFIG += plugin
 TARGET = $${RLIBNAME}stemmer
-LIBS += -lstemmer
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}stemmer$${RLIBPOSTDLL}
 OTHER_FILES += stemmer.dox
 DEFINES += QCADSTEMMER_LIBRARY
-
-POST_TARGETDEPS += ../../$$ROUTDIR/$${RLIBPRE}stemmer$${RLIBPOST}
