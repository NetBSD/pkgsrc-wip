$NetBSD: patch-src_util_directory.cpp,v 1.1 2015/02/13 15:18:00 nros Exp $
* docs are installed in share/doc/${PKGBASE}
--- src/util/directory.cpp.orig	2014-07-05 14:29:03.000000000 +0000
+++ src/util/directory.cpp
@@ -144,9 +144,9 @@ bool initDirectoryCache() {
     QString langCode(localeName.section('_', 0, 0));
 
     cachedHandbookDir.reset(new QDir(wDir));
-    if (!cachedHandbookDir->cd("share/bibletime/docs/handbook/" + localeName)) {
-        if (!cachedHandbookDir->cd("share/bibletime/docs/handbook/" + langCode)) {
-            if (!cachedHandbookDir->cd("share/bibletime/docs/handbook/en/")) {
+    if (!cachedHandbookDir->cd("share/doc/bibletime/handbook/" + localeName)) {
+        if (!cachedHandbookDir->cd("share/doc/bibletime/handbook/" + langCode)) {
+            if (!cachedHandbookDir->cd("share/doc/bibletime/handbook/en/")) {
                 qWarning() << "Cannot find handbook directory relative to" << wDir.absolutePath();
                 return false;
             }
@@ -154,9 +154,10 @@ bool initDirectoryCache() {
     }
 
     cachedHowtoDir.reset(new QDir(wDir));
-    if (!cachedHowtoDir->cd("share/bibletime/docs/howto/" + localeName)) {
-        if (!cachedHowtoDir->cd("share/bibletime/docs/howto/" + langCode)) {
-            if (!cachedHowtoDir->cd("share/bibletime/docs/howto/en/")) {
+    if (!cachedHowtoDir->cd("share/doc/bibletime/howto/" + localeName)) 
+{
+        if (!cachedHowtoDir->cd("share/doc/bibletime/howto/" + langCode)) {
+            if (!cachedHowtoDir->cd("share/doc/bibletime/howto/en/")) {
                 qWarning() << "Cannot find handbook directory relative to" << wDir.absolutePath();
                 return false;
             }
