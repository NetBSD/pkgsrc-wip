$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/os_crypt/async/common/encryptor.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/os_crypt/async/common/encryptor.cc
@@ -277,7 +277,7 @@ std::optional<std::string> Encryptor::De
     // or not encryption worked or not, and certainly not advisable to recommend
     // a re-encryption of this potentially invalid data.
     // TODO(crbug.com/365712505): Remove this fallback.
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) &&         \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
         !(BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
     BUILDFLAG(IS_FUCHSIA)
     if (plaintext == string_data) {
