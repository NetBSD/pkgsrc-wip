$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -169,7 +169,7 @@ base::Value::Dict CreateProfileEntry(con
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (entry->GetIsManaged() == signin::Tribool::kTrue) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (entry->IsSupervised()) {
     profileCardButtonLabel = l10n_util::GetStringFUTF16(
         IDS_PROFILE_PICKER_PROFILE_CARD_LABEL_SUPERVISED, local_profile_name);
