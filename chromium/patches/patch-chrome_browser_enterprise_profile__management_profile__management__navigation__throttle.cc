$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc.orig	2024-07-24 02:44:27.131860700 +0000
+++ chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc
@@ -67,8 +67,8 @@ base::flat_map<std::string, SAMLProfileA
   // TODO(crbug.com/40267996): Add actual domains with attribute names.
   profile_attributes->insert(std::make_pair(
       "supported.test",
-      SAMLProfileAttributes("placeholderName", "placeholderDomain",
-                            "placeholderToken")));
+      SAMLProfileAttributes(SAMLProfileAttributes{"placeholderName", "placeholderDomain",
+                            "placeholderToken"})));
 
   // Extract domains and attributes from the command line switch.
   const base::CommandLine& command_line =
