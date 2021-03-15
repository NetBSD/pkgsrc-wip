$NetBSD$

icu >= 68

--- src/3rdparty/chromium/components/url_formatter/spoof_checks/skeleton_generator.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/url_formatter/spoof_checks/skeleton_generator.cc
@@ -117,7 +117,7 @@ SkeletonGenerator::~SkeletonGenerator() 
 Skeletons SkeletonGenerator::GetSkeletons(base::StringPiece16 hostname) {
   Skeletons skeletons;
   size_t hostname_length = hostname.length() - (hostname.back() == '.' ? 1 : 0);
-  icu::UnicodeString host(FALSE, hostname.data(), hostname_length);
+  icu::UnicodeString host(false, hostname.data(), hostname_length);
   // If input has any characters outside Latin-Greek-Cyrillic and [0-9._-],
   // there is no point in getting rid of diacritics because combining marks
   // attached to non-LGC characters are already blocked.
