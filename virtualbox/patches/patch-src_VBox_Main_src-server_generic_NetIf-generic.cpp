$NetBSD$

--- src/VBox/Main/src-server/generic/NetIf-generic.cpp.orig	2016-03-04 19:29:41.000000000 +0000
+++ src/VBox/Main/src-server/generic/NetIf-generic.cpp
@@ -184,7 +184,7 @@ int NetIfCreateHostOnlyNetworkInterface(
                                         IProgress **aProgress,
                                         const char *pcszName)
 {
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* create a progress object */
     ComObjPtr<Progress> progress;
     progress.createObject();
@@ -311,7 +311,7 @@ int NetIfCreateHostOnlyNetworkInterface(
 int NetIfRemoveHostOnlyNetworkInterface(VirtualBox *pVirtualBox, IN_GUID aId,
                                         IProgress **aProgress)
 {
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* create a progress object */
     ComObjPtr<Progress> progress;
     progress.createObject();
