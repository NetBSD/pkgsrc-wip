$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel_posix.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ mojo/core/channel_posix.cc
@@ -606,6 +606,13 @@ void Channel::OfferChannelUpgrade() {
   }
   static_cast<ChannelLinux*>(this)->OfferSharedMemUpgrade();
 }
+#elif BUILDFLAG(IS_BSD)
+// static
+bool Channel::SupportsChannelUpgrade() {
+  return false;
+}
+void Channel::OfferChannelUpgrade() {
+}
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
 
