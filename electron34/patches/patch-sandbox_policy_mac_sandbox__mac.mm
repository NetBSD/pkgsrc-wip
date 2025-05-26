$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/mac/sandbox_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/policy/mac/sandbox_mac.mm
@@ -36,6 +36,10 @@
 #include "sandbox/policy/mac/utility.sb.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 
+#if BUILDFLAG(ENABLE_PRINTING)
+#include "sandbox/policy/mac/print_backend.sb.h"
+#endif
+
 namespace sandbox::policy {
 
 base::FilePath GetCanonicalPath(const base::FilePath& path) {
