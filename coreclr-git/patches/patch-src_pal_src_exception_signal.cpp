$NetBSD$

--- src/pal/src/exception/signal.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/exception/signal.cpp
@@ -45,7 +45,13 @@ using namespace CorUnix;
 
 SET_DEFAULT_DEBUG_CHANNEL(EXCEPT);
 
+#ifdef SIGRTMIN
 #define INJECT_ACTIVATION_SIGNAL SIGRTMIN
+#endif
+
+#if !defined(INJECT_ACTIVATION_SIGNAL) && defined(FEATURE_HIJACK)
+#error FEATURE_HIJACK requires INJECT_ACTIVATION_SIGNAL to be defined
+#endif
 
 /* local type definitions *****************************************************/
 
@@ -70,7 +76,9 @@ static void sigquit_handler(int code, si
 static void common_signal_handler(PEXCEPTION_POINTERS pointers, int code, 
                                   native_context_t *ucontext);
 
+#ifdef INJECT_ACTIVATION_SIGNAL
 static void inject_activation_handler(int code, siginfo_t *siginfo, void *context);
+#endif
 
 static void handle_signal(int signal_id, SIGFUNC sigfunc, struct sigaction *previousAction);
 static void restore_signal(int signal_id, struct sigaction *previousAction);
@@ -125,7 +133,9 @@ BOOL SEHInitializeSignals()
     handle_signal(SIGINT, sigint_handler, &g_previous_sigint);
     handle_signal(SIGQUIT, sigquit_handler, &g_previous_sigquit);
 
+#ifdef INJECT_ACTIVATION_SIGNAL
     handle_signal(INJECT_ACTIVATION_SIGNAL, inject_activation_handler, NULL);
+#endif
 
     /* The default action for SIGPIPE is process termination.
        Since SIGPIPE can be signaled when trying to write on a socket for which
@@ -484,6 +494,7 @@ static void sigquit_handler(int code, si
     kill(gPID, code);
 }
 
+#ifdef INJECT_ACTIVATION_SIGNAL
 /*++
 Function :
     inject_activation_handler
@@ -523,6 +534,7 @@ static void inject_activation_handler(in
         }
     }
 }
+#endif
 
 /*++
 Function :
@@ -538,6 +550,7 @@ Parameters :
 --*/
 PAL_ERROR InjectActivationInternal(CorUnix::CPalThread* pThread)
 {
+#ifdef INJECT_ACTIVATION_SIGNAL
     int status = pthread_kill(pThread->GetPThreadSelf(), INJECT_ACTIVATION_SIGNAL);
     if (status != 0)
     {
@@ -550,6 +563,9 @@ PAL_ERROR InjectActivationInternal(CorUn
     }
 
     return NO_ERROR;
+#else
+    return ERROR_CANCELLED;
+#endif
 }
 
 /*++
