$NetBSD$

--- src/pal/src/exception/seh.cpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/pal/src/exception/seh.cpp
@@ -149,6 +149,21 @@ PAL_SetGetGcMarkerExceptionCode(
     g_getGcMarkerExceptionCode = getGcMarkerExceptionCode;
 }
 
+EXTERN_C void ThrowHardwareExceptionFromContext(CONTEXT* context, PAL_SEHException* ex);
+
+//---------------------------------------------------------------------------------------
+//
+// Helper function to throw the passed in exception.
+// It is called from the assembler function StartUnwindingNativeFrames 
+// Arguments:
+//
+//      ex - the exception to throw.
+//
+extern "C"
+void ThrowHardwareExceptionHelper(PAL_SEHException* ex)
+{
+    throw *ex;
+}
 /*++
 Function:
     SEHProcessException
@@ -175,7 +190,10 @@ SEHProcessException(PEXCEPTION_POINTERS 
 
         if (CatchHardwareExceptionHolder::IsEnabled())
         {
-            throw exception;
+            static __thread BYTE threadLocalExceptionStorage[sizeof(PAL_SEHException)];
+            PAL_SEHException* ex = new (threadLocalExceptionStorage) PAL_SEHException(exception);
+            ThrowHardwareExceptionFromContext(&ex->ContextRecord, ex);
+            //throw exception;
         }
     }
 
