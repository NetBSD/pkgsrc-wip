$NetBSD$

--- src/pal/src/exception/seh-unwind.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/exception/seh-unwind.cpp
@@ -297,7 +297,6 @@ BOOL PAL_VirtualUnwind(CONTEXT *context,
 }
 
 #else
-#error don't know how to unwind on this platform
 #endif
 
 // These methods are only used on the AMD64 build
@@ -584,7 +583,7 @@ RtlpRaiseException(EXCEPTION_RECORD *Exc
 #elif defined(_ARM_) || defined(_ARM64_)
     ExceptionRecord->ExceptionAddress = (void *) ContextRecord.Pc;
 #else
-#error unsupported architecture
+#warning unsupported architecture
 #endif
 
     throw PAL_SEHException(ExceptionRecord, &ContextRecord);
