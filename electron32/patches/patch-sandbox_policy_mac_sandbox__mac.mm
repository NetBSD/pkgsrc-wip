$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/policy/mac/sandbox_mac.mm.orig	2024-10-18 12:34:31.997764600 +0000
+++ sandbox/policy/mac/sandbox_mac.mm
@@ -38,6 +38,10 @@
 #include "sandbox/policy/mac/utility.sb.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 
+#if BUILDFLAG(ENABLE_PRINTING)
+#include "sandbox/policy/mac/print_backend.sb.h"
+#endif
+
 namespace sandbox::policy {
 
 base::FilePath GetCanonicalPath(const base::FilePath& path) {
