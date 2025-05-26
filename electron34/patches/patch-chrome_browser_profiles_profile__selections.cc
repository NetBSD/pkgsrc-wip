$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/profiles/profile_selections.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/profiles/profile_selections.cc
@@ -13,6 +13,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
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
 
@@ -132,6 +133,7 @@ ProfileSelection ProfileSelections::GetP
   }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
+#if 0
   // Treat other off the record profiles as Incognito (primary otr) Profiles.
   if (profile->IsRegularProfile() || profile->IsIncognitoProfile() ||
       profile_metrics::GetBrowserProfileType(profile) ==
@@ -148,6 +150,8 @@ ProfileSelection ProfileSelections::GetP
   }
 
   NOTREACHED();
+#endif
+  return ProfileSelection::kNone;
 }
 
 void ProfileSelections::SetProfileSelectionForRegular(
