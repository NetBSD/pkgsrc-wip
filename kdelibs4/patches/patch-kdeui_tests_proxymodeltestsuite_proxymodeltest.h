$NetBSD: patch-kdeui_tests_proxymodeltestsuite_proxymodeltest.h,v 1.1 2011/05/13 23:25:15 mwdavies Exp $

Make build with gcc 4.1

--- kdeui/tests/proxymodeltestsuite/proxymodeltest.h.orig	2011-04-01 13:55:50.000000000 +0000
+++ kdeui/tests/proxymodeltestsuite/proxymodeltest.h
@@ -38,6 +38,8 @@ typedef QList<QVariantList> SignalList;
 
 Q_DECLARE_METATYPE( SignalList )
 
+#define PROXYMODELTESTSUITE_EXPORT
+
 enum PROXYMODELTESTSUITE_EXPORT Persistence
 {
   LazyPersistence,
