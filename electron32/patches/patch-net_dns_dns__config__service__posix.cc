$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/dns/dns_config_service_posix.cc.orig	2024-10-18 12:34:30.270576500 +0000
+++ net/dns/dns_config_service_posix.cc
@@ -39,6 +39,11 @@
 #include "net/dns/dns_config_watcher_mac.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/command_line.h"
+#include "sandbox/policy/switches.h"
+#endif
+
 namespace net {
 
 namespace internal {
@@ -136,7 +141,13 @@ class DnsConfigServicePosix::Watcher : p
   bool Watch() override {
     CheckOnCorrectSequence();
 
+// pledge + unveil
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox))
+      return false;
+
     bool success = true;
+#if !IS_MAS_BUILD()
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
                                                    base::Unretained(this)))) {
       LOG(ERROR) << "DNS config watch failed to start.";
@@ -153,6 +164,7 @@ class DnsConfigServicePosix::Watcher : p
       success = false;
     }
 #endif  // !BUILDFLAG(IS_IOS)
+#endif
     return success;
   }
 
