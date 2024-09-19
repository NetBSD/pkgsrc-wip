$NetBSD$

Baskport patch from TCL 8.6.

--- src/other/tcl/unix/tclUnixInit.c.orig	2016-08-09 06:47:10.000000000 +0000
+++ src/other/tcl/unix/tclUnixInit.c
@@ -54,6 +54,11 @@
 #   endif
 # endif
 #endif
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/utsname.h>
+#endif
 
 /*
  * Define TCL_NO_STACK_CHECK in the compiler options if you want to revert to
@@ -789,6 +794,11 @@ TclpSetVariables(
 #endif
     int unameOK;
     Tcl_DString ds;
+#if defined(__NetBSD__)
+    char machine_arch[SYS_NMLN];
+    int mib[2] = { CTL_HW, HW_MACHINE_ARCH };
+    size_t len = sizeof(machine_arch);
+#endif
 
 #ifdef HAVE_COREFOUNDATION
     char tclLibPath[MAXPATHLEN + 1];
@@ -939,8 +949,15 @@ TclpSetVariables(
 
 #endif /* DJGPP */
 	}
+#if defined(__NetBSD__)
+       if (sysctl(mib, sizeof(mib) / sizeof(int), machine_arch, &len, NULL, 0) < 0)
+           unameOK = 0;
+       else
+            Tcl_SetVar2(interp, "tcl_platform", "machine", machine_arch, TCL_GLOBAL_ONLY);
+#else
 	Tcl_SetVar2(interp, "tcl_platform", "machine", name.machine,
 		TCL_GLOBAL_ONLY);
+#endif /* __NetBSD__ */
     }
 #endif /* !NO_UNAME */
     if (!unameOK) {
