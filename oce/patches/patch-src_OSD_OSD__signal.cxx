$NetBSD: patch-src_OSD_OSD__signal.cxx,v 1.2 2015/06/25 12:41:09 fhajny Exp $

Define SIGFPE macros on SunOS.
Respect the reality as CMake found it, there might not be libsunmath.
--- src/OSD/OSD_signal.cxx.orig	2015-03-08 22:19:42.000000000 +0000
+++ src/OSD/OSD_signal.cxx
@@ -55,6 +55,17 @@ ACT_SIGIO_HANDLER *ADR_ACT_SIGIO_HANDLER
 typedef void (* SIG_PFV) (int);
 #endif
 
+#if defined(__sun)
+# include <sys/siginfo.h>
+# define FPE_FLTDIV_TRAP FPE_FLTDIV
+# define FPE_INTDIV_TRAP FPE_INTDIV
+# define FPE_FLTOVF_TRAP FPE_FLTOVF
+# define FPE_INTOVF_TRAP FPE_INTOVF
+# define FPE_FLTUND_TRAP FPE_FLTUND
+# define FPE_FLTRES_TRAP FPE_FLTRES
+# define FPE_FLTINV_TRAP FPE_FLTINV
+#endif
+
 #ifdef __GNUC__
 # include <stdlib.h>
 # include <stdio.h>
@@ -379,7 +390,7 @@ void OSD::SetSignal(const Standard_Boole
 
   if( aFloatingSignal ) {
     //==== Enable the floating point exceptions ===============
-#if defined (__sun) || defined (SOLARIS)
+#if ( defined (__sun) || defined (SOLARIS) ) && HAVE_SUNMATH
     sigfpe_handler_type PHandler = (sigfpe_handler_type) Handler ;
     stat = ieee_handler("set", "invalid",  PHandler);
     stat = ieee_handler("set", "division", PHandler) || stat;
