$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -31,7 +31,15 @@ bool CheckCmdlineForOrca(const std::stri
   std::string cmdline;
   std::stringstream ss(cmdline_all);
   while (std::getline(ss, cmdline, '\0')) {
+#if BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+    re2::RE2 orca_regex(R"((^|/)(usr/)?(pkg/)?bin/orca(\s|$))");
+#else
+    re2::RE2 orca_regex(R"((^|/)(usr/)?(local/)?bin/orca(\s|$))");
+#endif
+#else
     re2::RE2 orca_regex(R"((^|/)(usr/)?bin/orca(\s|$))");
+#endif
     if (re2::RE2::PartialMatch(cmdline, orca_regex)) {
       return true;  // Orca was found
     }
@@ -57,7 +65,9 @@ class BrowserAccessibilityStateImplAural
 
 void BrowserAccessibilityStateImplAuralinux::UpdateHistogramsOnOtherThread() {
   BrowserAccessibilityStateImpl::UpdateHistogramsOnOtherThread();
-
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly. Code that
   // needs to run in the UI thread can be run in
@@ -105,6 +115,7 @@ void BrowserAccessibilityStateImplAurali
   } else {
     base::debug::ClearCrashKeyString(ax_orca_crash_key);
   }
+#endif
 }
 
 void BrowserAccessibilityStateImplAuralinux::UpdateUniqueUserHistograms() {
