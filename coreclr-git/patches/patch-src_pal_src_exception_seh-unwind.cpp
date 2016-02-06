$NetBSD$

--- src/pal/src/exception/seh-unwind.cpp.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/exception/seh-unwind.cpp
@@ -297,7 +297,6 @@ BOOL PAL_VirtualUnwind(CONTEXT *context,
 }
 
 #else
-#error don't know how to unwind on this platform
 #endif
 
 // These methods are only used on the AMD64 build
@@ -570,12 +569,14 @@ RtlpRaiseException(EXCEPTION_RECORD *Exc
     ContextRecord.ContextFlags = CONTEXT_FULL;
     CONTEXT_CaptureContext(&ContextRecord);
 
+#if 0
     // Find the caller of RtlpRaiseException.  
     PAL_VirtualUnwind(&ContextRecord, NULL);
 
     // The frame we're looking at now is RaiseException. We have to unwind one 
     // level further to get the actual context user code could be resumed at.
     PAL_VirtualUnwind(&ContextRecord, NULL);
+#endif
 
 #if defined(_X86_)
     ExceptionRecord->ExceptionAddress = (void *) ContextRecord.Eip;
@@ -584,7 +585,7 @@ RtlpRaiseException(EXCEPTION_RECORD *Exc
 #elif defined(_ARM_) || defined(_ARM64_)
     ExceptionRecord->ExceptionAddress = (void *) ContextRecord.Pc;
 #else
-#error unsupported architecture
+#warning unsupported architecture
 #endif
 
     throw PAL_SEHException(ExceptionRecord, &ContextRecord);
