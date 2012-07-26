$NetBSD: patch-db_db.cpp,v 1.1 2012/07/26 11:08:46 fhajny Exp $

Patch for SunOS crashes due to incorrect usage of SIGPIPE.

--- db/db.cpp.orig	2012-06-04 13:42:54.000000000 +0000
+++ db/db.cpp
@@ -1055,14 +1055,6 @@ namespace mongo {
 
 namespace mongo {
 
-    void pipeSigHandler( int signal ) {
-#ifdef psignal
-        psignal( signal, "Signal Received : ");
-#else
-        cout << "got pipe signal:" << signal << endl;
-#endif
-    }
-
     void abruptQuit(int x) {
         ostringstream ossSig;
         ossSig << "Got signal: " << x << " (" << strsignal( x ) << ")." << endl;
@@ -1134,7 +1126,7 @@ namespace mongo {
         
         assert( signal(SIGABRT, abruptQuit) != SIG_ERR );
         assert( signal(SIGQUIT, abruptQuit) != SIG_ERR );
-        assert( signal(SIGPIPE, pipeSigHandler) != SIG_ERR );
+        assert( signal(SIGPIPE, SIG_IGN) != SIG_ERR );
 
         setupSIGTRAPforGDB();
 
