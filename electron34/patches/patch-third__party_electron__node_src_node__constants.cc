$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/node_constants.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/node_constants.cc
@@ -241,10 +241,6 @@ void DefineErrnoConstants(Local<Object> 
   NODE_DEFINE_CONSTANT(target, ENOBUFS);
 #endif
 
-#ifdef ENODATA
-  NODE_DEFINE_CONSTANT(target, ENODATA);
-#endif
-
 #ifdef ENODEV
   NODE_DEFINE_CONSTANT(target, ENODEV);
 #endif
@@ -281,14 +277,6 @@ void DefineErrnoConstants(Local<Object> 
   NODE_DEFINE_CONSTANT(target, ENOSPC);
 #endif
 
-#ifdef ENOSR
-  NODE_DEFINE_CONSTANT(target, ENOSR);
-#endif
-
-#ifdef ENOSTR
-  NODE_DEFINE_CONSTANT(target, ENOSTR);
-#endif
-
 #ifdef ENOSYS
   NODE_DEFINE_CONSTANT(target, ENOSYS);
 #endif
@@ -369,10 +357,6 @@ void DefineErrnoConstants(Local<Object> 
   NODE_DEFINE_CONSTANT(target, ESTALE);
 #endif
 
-#ifdef ETIME
-  NODE_DEFINE_CONSTANT(target, ETIME);
-#endif
-
 #ifdef ETIMEDOUT
   NODE_DEFINE_CONSTANT(target, ETIMEDOUT);
 #endif
