$NetBSD$

--- src/vm/i386/excepx86.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/i386/excepx86.cpp
@@ -2209,7 +2209,7 @@ VOID PopNestedExceptionRecords(LPVOID pT
  * COMPlusThrowCallbackHelper
  *
  * This function is a simple helper function for COMPlusThrowCallback.  It is needed
- * because of the EX_TRY macro.  This macro does an alloca(), which allocates space
+ * because of the EX_TRY macro.  This macro does an Alloca(), which allocates space
  * off the stack, not free'ing it.  Thus, doing a EX_TRY in a loop can easily result
  * in a stack overflow error.  By factoring out the EX_TRY into a separate function,
  * we recover that stack space.
