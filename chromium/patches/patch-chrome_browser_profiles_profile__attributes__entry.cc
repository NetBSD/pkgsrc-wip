$NetBSD$

--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/profiles/profile_attributes_entry.cc
@@ -137,7 +137,7 @@ void ProfileAttributesEntry::Initialize(
   if (is_force_signin_enabled_) {
     if (!IsAuthenticated())
       is_force_signin_profile_locked_ = true;
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
     // left-overs from legacy supervised users. Just unlock them, so users can
