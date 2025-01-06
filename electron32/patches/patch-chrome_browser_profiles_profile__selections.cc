$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/profiles/profile_selections.cc.orig	2024-10-18 12:34:01.897079500 +0000
+++ chrome/browser/profiles/profile_selections.cc
@@ -13,6 +13,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 bool AreKeyedServicesDisabledForProfileByDefault(const Profile* profile) {
+#if 0
   // By default disable all services for System Profile.
   // Even though having no services is also the default value for Guest Profile,
   // this is not really the case in practice because a lot of Service Factories
@@ -20,7 +21,7 @@ bool AreKeyedServicesDisabledForProfileB
   if (profile && profile->IsSystemProfile()) {
     return true;
   }
-
+#endif
   return false;
 }
 
@@ -123,6 +124,7 @@ Profile* ProfileSelections::ApplyProfile
 
 ProfileSelection ProfileSelections::GetProfileSelection(
     Profile* profile) const {
+#if 0
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   // This check has to be performed before the check on
   // `profile->IsRegularProfile()` because profiles that are internal ASH
@@ -148,6 +150,7 @@ ProfileSelection ProfileSelections::GetP
   }
 
   NOTREACHED_IN_MIGRATION();
+#endif
   return ProfileSelection::kNone;
 }
 
