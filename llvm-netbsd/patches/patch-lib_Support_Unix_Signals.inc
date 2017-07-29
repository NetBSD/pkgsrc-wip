$NetBSD$

--- lib/Support/Unix/Signals.inc.orig	2017-07-05 18:38:14.000000000 +0000
+++ lib/Support/Unix/Signals.inc
@@ -158,8 +158,8 @@ static void RegisterHandlers() {
   // be able to reliably handle signals due to stack overflow.
   CreateSigAltStack();
 
-  for (auto S : IntSigs) RegisterHandler(S);
-  for (auto S : KillSigs) RegisterHandler(S);
+//  for (auto S : IntSigs) RegisterHandler(S);
+//  for (auto S : KillSigs) RegisterHandler(S);
 }
 
 static void UnregisterHandlers() {
