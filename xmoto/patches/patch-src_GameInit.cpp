$NetBSD: patch-src_GameInit.cpp,v 1.1 2014/08/09 18:33:51 nros Exp $
* check and set sa_restorer only on platforms that have it.
--- src/GameInit.cpp.orig	2011-10-11 20:18:35.000000000 +0000
+++ src/GameInit.cpp
@@ -269,7 +269,7 @@ void GameApp::run_load(int nNumArgs, cha
     struct sigaction v_act;
 
     v_act.sa_handler  = xmexit_term;
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if defined(HAVE_SIGACTION_SA_RESTORER)
     v_act.sa_restorer = NULL;
 #endif
     sigemptyset(&v_act.sa_mask);
