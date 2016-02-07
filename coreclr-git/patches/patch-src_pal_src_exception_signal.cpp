$NetBSD$

--- src/pal/src/exception/signal.cpp.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/pal/src/exception/signal.cpp
@@ -45,7 +45,7 @@ using namespace CorUnix;
 
 SET_DEFAULT_DEBUG_CHANNEL(EXCEPT);
 
-#define INJECT_ACTIVATION_SIGNAL SIGRTMIN
+#define INJECT_ACTIVATION_SIGNAL 0
 
 /* local type definitions *****************************************************/
 
@@ -194,10 +194,10 @@ static void sigill_handler(int code, sig
 
         ucontext = (native_context_t *)context;
 
-        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
+//        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
         record.ExceptionFlags = EXCEPTION_IS_SIGNAL;
         record.ExceptionRecord = NULL;
-        record.ExceptionAddress = GetNativeContextPC(ucontext);
+//        record.ExceptionAddress = GetNativeContextPC(ucontext);
         record.NumberParameters = 0;
 
         pointers.ExceptionRecord = &record;
@@ -241,10 +241,10 @@ static void sigfpe_handler(int code, sig
 
         ucontext = (native_context_t *)context;
 
-        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
+//        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
         record.ExceptionFlags = EXCEPTION_IS_SIGNAL;
         record.ExceptionRecord = NULL;
-        record.ExceptionAddress = GetNativeContextPC(ucontext);
+//        record.ExceptionAddress = GetNativeContextPC(ucontext);
         record.NumberParameters = 0;
 
         pointers.ExceptionRecord = &record;
@@ -288,10 +288,10 @@ static void sigsegv_handler(int code, si
 
         ucontext = (native_context_t *)context;
 
-        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
+//        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
         record.ExceptionFlags = EXCEPTION_IS_SIGNAL;
         record.ExceptionRecord = NULL;
-        record.ExceptionAddress = GetNativeContextPC(ucontext);
+//        record.ExceptionAddress = GetNativeContextPC(ucontext);
         record.NumberParameters = 2;
 
         if (record.ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
@@ -358,10 +358,10 @@ static void sigtrap_handler(int code, si
 
         ucontext = (native_context_t *)context;
 
-        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
+//        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
         record.ExceptionFlags = EXCEPTION_IS_SIGNAL;
         record.ExceptionRecord = NULL;
-        record.ExceptionAddress = GetNativeContextPC(ucontext);
+//        record.ExceptionAddress = GetNativeContextPC(ucontext);
         record.NumberParameters = 0;
 
         pointers.ExceptionRecord = &record;
@@ -406,10 +406,10 @@ static void sigbus_handler(int code, sig
 
         ucontext = (native_context_t *)context;
 
-        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
+//        record.ExceptionCode = CONTEXTGetExceptionCodeForSignal(siginfo, ucontext);
         record.ExceptionFlags = EXCEPTION_IS_SIGNAL;
         record.ExceptionRecord = NULL;
-        record.ExceptionAddress = GetNativeContextPC(ucontext);
+//        record.ExceptionAddress = GetNativeContextPC(ucontext);
         record.NumberParameters = 2;
 
         // TODO: First parameter says whether a read (0) or write (non-0) caused the
@@ -508,18 +508,19 @@ static void inject_activation_handler(in
             native_context_t *ucontext = (native_context_t *)context;
 
             CONTEXT winContext;
+#if 0
             CONTEXTFromNativeContext(
                 ucontext, 
                 &winContext, 
                 CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT);
-
+#endif
             if (g_safeActivationCheckFunction(CONTEXTGetPC(&winContext)))
             {
                 g_activationFunction(&winContext);
             }
 
             // Activation function may have modified the context, so update it.
-            CONTEXTToNativeContext(&winContext, ucontext);
+//            CONTEXTToNativeContext(&winContext, ucontext);
         }
     }
 }
@@ -625,7 +626,7 @@ static void common_signal_handler(PEXCEP
     // Fill context record with required information. from pal.h :
     // On non-Win32 platforms, the CONTEXT pointer in the
     // PEXCEPTION_POINTERS will contain at least the CONTEXT_CONTROL registers.
-    CONTEXTFromNativeContext(ucontext, &context, CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT);
+//    CONTEXTFromNativeContext(ucontext, &context, CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT);
 
     pointers->ContextRecord = &context;
 
