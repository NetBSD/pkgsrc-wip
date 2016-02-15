$NetBSD$

--- src/vm/exceptmacros.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/exceptmacros.h
@@ -230,7 +230,7 @@ VOID DECLSPEC_NORETURN RealCOMPlusThrowS
 #if !defined(WIN64EXCEPTIONS)
 
 #define INSTALL_NESTED_EXCEPTION_HANDLER(frame)                                                                       \
-   NestedHandlerExRecord *__pNestedHandlerExRecord = (NestedHandlerExRecord*) _alloca(sizeof(NestedHandlerExRecord)); \
+   NestedHandlerExRecord *__pNestedHandlerExRecord = (NestedHandlerExRecord*) Alloca(sizeof(NestedHandlerExRecord)); \
    __pNestedHandlerExRecord->m_handlerInfo.m_hThrowable = NULL;                                                       \
    __pNestedHandlerExRecord->Init((PEXCEPTION_ROUTINE)COMPlusNestedExceptionHandler, frame);                          \
    INSTALL_EXCEPTION_HANDLING_RECORD(&(__pNestedHandlerExRecord->m_ExReg));
