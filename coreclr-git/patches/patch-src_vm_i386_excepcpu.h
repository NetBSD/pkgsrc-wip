$NetBSD$

--- src/vm/i386/excepcpu.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/i386/excepcpu.h
@@ -50,7 +50,7 @@ class Thread;
 // stackOverwriteBarrier is used to detect overwriting of stack which will mess up handler registration
 #if defined(_DEBUG)
 #define DECLARE_CPFH_EH_RECORD(pCurThread) \
-    FrameHandlerExRecordWithBarrier *___pExRecordWithBarrier = (FrameHandlerExRecordWithBarrier *)_alloca(sizeof(FrameHandlerExRecordWithBarrier)); \
+    FrameHandlerExRecordWithBarrier *___pExRecordWithBarrier = (FrameHandlerExRecordWithBarrier *)Alloca(sizeof(FrameHandlerExRecordWithBarrier)); \
     for (int ___i =0; ___i < STACK_OVERWRITE_BARRIER_SIZE; ___i++) \
         ___pExRecordWithBarrier->m_StackOverwriteBarrier[___i] = STACK_OVERWRITE_BARRIER_VALUE; \
     FrameHandlerExRecord *___pExRecord = &(___pExRecordWithBarrier->m_ExRecord); \
@@ -59,7 +59,7 @@ class Thread;
 
 #else
 #define DECLARE_CPFH_EH_RECORD(pCurThread) \
-    FrameHandlerExRecord *___pExRecord = (FrameHandlerExRecord *)_alloca(sizeof(FrameHandlerExRecord)); \
+    FrameHandlerExRecord *___pExRecord = (FrameHandlerExRecord *)Alloca(sizeof(FrameHandlerExRecord)); \
     ___pExRecord->m_ExReg.Handler = (PEXCEPTION_ROUTINE)COMPlusFrameHandler; \
     ___pExRecord->m_pEntryFrame = (pCurThread)->GetFrame();
 
