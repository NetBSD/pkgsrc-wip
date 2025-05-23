$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/base/network_change_notifier.cc.orig	2024-10-18 12:34:30.010699000 +0000
+++ net/base/network_change_notifier.cc
@@ -42,7 +42,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "net/base/network_change_notifier_apple.h"
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_passive.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -329,6 +329,9 @@ std::unique_ptr<NetworkChangeNotifier> N
 #elif BUILDFLAG(IS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       /*require_wlan=*/false);
+#elif BUILDFLAG(IS_BSD)
+  return std::make_unique<MockNetworkChangeNotifier>(
+      /*dns_config_notifier*/nullptr);
 #else
   NOTIMPLEMENTED();
   return nullptr;
@@ -520,7 +523,7 @@ const char* NetworkChangeNotifier::Conne
   return kConnectionTypeNames[type];
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 AddressMapOwnerLinux* NetworkChangeNotifier::GetAddressMapOwner() {
   return g_network_change_notifier
@@ -866,7 +869,7 @@ NetworkChangeNotifier::NetworkChangeNoti
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 AddressMapOwnerLinux* NetworkChangeNotifier::GetAddressMapOwnerInternal() {
   return nullptr;
 }
