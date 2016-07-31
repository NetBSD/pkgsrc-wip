$NetBSD$

--- src/core/core.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/core/core.pro
@@ -282,7 +282,8 @@ RESOURCES = resources/core.qrc
 OTHER_FILES += core.dox math/math.dox
 DEFINES += QCADCORE_LIBRARY

-LIBS += -lopennurbs -lzlib
+LIBS += ../../$${ROUTDIR}/$${RLIBPRE}opennurbs$${RLIBPOSTDLL} \
+	../../$${ROUTDIR}/$${RLIBPRE}zlib$${RLIBPOSTDLL}

 win32 {
     LIBS += -lRpcrt4 -lAdvapi32
