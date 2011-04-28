$NetBSD: patch-chrome_browser_process__singleton__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/process_singleton_linux.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/process_singleton_linux.cc
@@ -55,6 +55,13 @@
 #include <set>
 #include <string>
 
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <kvm.h>
+#include <libgen.h>
+#endif
+
 #include "base/base_paths.h"
 #include "base/basictypes.h"
 #include "base/command_line.h"
@@ -314,10 +321,46 @@ void DisplayProfileInUseError(const std:
 }
 
 bool IsChromeProcess(pid_t pid) {
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+  int i, nproc;
+#if defined(OS_OPENBSD)
+  struct kinfo_proc *plist, *kp;
+#else
+  struct kinfo_proc2 *plist, *kp;
+#endif
+  char buf[_POSIX2_LINE_MAX], **pargv;
+  char *p;
+  kvm_t *kd;
+
+  if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, buf)) == NULL) {
+    LOG(ERROR) << "kvm_openfiles(): failed";
+    return false;
+  }
+
+  plist = kvm_getproc2(kd, KERN_PROC_PID, pid, sizeof(*plist), &nproc);
+  CHECK(plist != NULL);
+
+  for (i = 0, kp = plist; i < nproc; i++, kp++) {
+    if ((kp->p_flag & P_SYSTEM) != 0)
+      continue;
+    if ((pargv = kvm_getargv2(kd, kp, 0)) == NULL)
+      continue;
+    p = basename(pargv[0]);
+    if (!strcmp(p, "chrome")) {
+      LOG(ERROR) << pid << " is chrome";
+      kvm_close(kd);
+      return true;
+    }
+  }
+
+  kvm_close(kd);
+  return false;
+#else
   FilePath other_chrome_path(base::GetProcessExecutablePath(pid));
   return (!other_chrome_path.empty() &&
           other_chrome_path.BaseName() ==
           FilePath(chrome::kBrowserProcessExecutableName));
+#endif
 }
 
 // Return true if the given pid is one of our child processes.
