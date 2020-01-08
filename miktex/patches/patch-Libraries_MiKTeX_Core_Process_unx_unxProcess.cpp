$NetBSD$

Handle NetBSD like FreeBSD.
TODO: Still needs more porting to compile.

--- Libraries/MiKTeX/Core/Process/unx/unxProcess.cpp.orig	2019-11-16 19:20:48.000000000 +0000
+++ Libraries/MiKTeX/Core/Process/unx/unxProcess.cpp
@@ -30,14 +30,16 @@
 #  include <sys/proc.h>
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #   include <sys/param.h>
 #   include <sys/queue.h>
 #   include <sys/socket.h>
 #   include <sys/sysctl.h>
+#if defined(__FreeBSD__)
 #   include <sys/user.h>
-#   include <kvm.h>
 #   include <libprocstat.h>
+#endif
+#   include <kvm.h>
 #   include <fcntl.h>
 #endif
 
@@ -635,7 +637,7 @@ string unxProcess::get_ProcessName()
     MIKTEX_FATAL_CRT_ERROR("proc_pidpath")
   }
   return PathName(path).GetFileName().ToString();
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   std::string nameFromProcstat;
   kvm_t *kvm = kvm_open(nullptr, "/dev/null", nullptr, O_RDONLY, "");
   if (kvm)
@@ -755,7 +757,7 @@ ProcessInfo unxProcess::GetProcessInfo()
       break;
   }
   processInfo.parent = pbi.pbi_ppid;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   processInfo.parent = getppid();
 
   kvm_t *kvm = kvm_open(nullptr, "/dev/null", nullptr, O_RDONLY, "");
