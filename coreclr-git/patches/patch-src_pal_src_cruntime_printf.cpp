$NetBSD$

--- src/pal/src/cruntime/printf.cpp.orig	2016-04-15 21:21:27.000000000 +0000
+++ src/pal/src/cruntime/printf.cpp
@@ -45,6 +45,7 @@ static int SscanfFloatCheckExponent(LPCS
                                       void * voidPtr, int * pn);
 #endif // SSCANF_CANNOT_HANDLE_MISSING_EXPONENT
 
+
 /*******************************************************************************
 Function:
   Internal_AddPaddingA
