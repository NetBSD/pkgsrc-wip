$NetBSD$

* setting SIG_IGN on SIGCHLD removes the result from the child that triggered
  the signal on solaris/illumos

--- src/lib/util/signal_set.cc.orig	2020-01-10 08:19:15.723309083 +0000
+++ src/lib/util/signal_set.cc
@@ -118,11 +118,22 @@ SignalSet::invokeOnReceiptHandler(int si
     struct sigaction sa;
     struct sigaction prev_sa;
     memset(&sa, 0, sizeof(sa));
-    sa.sa_handler = SIG_IGN;
+    
+    if (sig == SIGCHLD) {
+        sa.sa_handler = SIG_DFL;
+    } else {
+        sa.sa_handler = SIG_IGN;
+    }
     if (sigaction(sig, &sa, &prev_sa) < 0) {
         // Highly unlikely we can get here.
+        std::string sig_type;
+        if (sa.sa_handler == SIG_DFL) {
+            sig_type = "SIG_DFL";
+        } else {
+            sig_type = "SIG_IGN";
+        }
         const char* errmsg = strerror(errno);
-        isc_throw(SignalSetError, "failed to set SIG_IGN for signal "
+        isc_throw(SignalSetError, "failed to set " << sig_type << " for signal "
                   << sig << ": " << errmsg);
     }
 
