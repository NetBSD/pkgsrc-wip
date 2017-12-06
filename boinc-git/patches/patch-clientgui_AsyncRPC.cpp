$NetBSD$

Correct header path.
Do not use uselocale on NetBSD.

--- clientgui/AsyncRPC.cpp.orig	2017-12-06 19:29:06.000000000 +0000
+++ clientgui/AsyncRPC.cpp
@@ -20,7 +20,7 @@
 #endif
 
 #if HAVE_XLOCALE_H
-#include <xlocale.h>
+#include <wx/xlocale.h>
 #endif
 
 #include "stdwx.h"
@@ -149,7 +149,9 @@ void *RPCThread::Entry() {
     {
         // On Mac / Unix / Linux, set "C" locale for this thread only
         RPC_Thread_Locale = newlocale(LC_ALL_MASK, "C", NULL);
+#if !defined(__NetBSD__)
         uselocale(RPC_Thread_Locale);
+#endif
     }
 #endif      // ifndef __WXMSW__
 #endif      // ifndef NO_PER_THREAD_LOCALE
@@ -170,7 +172,9 @@ void *RPCThread::Entry() {
         if (uselocale)    // uselocale() is not available in Mac OS 10.3.9
 #endif
         {
+#if !defined(__NetBSD__)
             uselocale(LC_GLOBAL_LOCALE);
+#endif
             freelocale(RPC_Thread_Locale);
         }
 #endif
