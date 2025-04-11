$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/embedder_support/user_agent_utils_unittest.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ components/embedder_support/user_agent_utils_unittest.cc
@@ -151,7 +151,7 @@ void CheckUserAgentStringOrdering(bool m
   ASSERT_EQ("CrOS", pieces[0]);
   ASSERT_EQ("x86_64", pieces[1]);
   ASSERT_EQ("14541.0.0", pieces[2]);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Post-UA Reduction there is a single <unifiedPlatform> value for Linux:
   // X11; Linux x86_64
   ASSERT_EQ(2u, pieces.size());
@@ -339,7 +339,7 @@ class UserAgentUtilsTest : public testin
         "X11; CrOS x86_64 14541.0.0";
 #elif BUILDFLAG(IS_FUCHSIA)
         "Fuchsia";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         "X11; Linux x86_64";
 #elif BUILDFLAG(IS_MAC)
         "Macintosh; Intel Mac OS X 10_15_7";
@@ -699,7 +699,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMeta
 #endif
 #elif BUILDFLAG(IS_ANDROID)
   EXPECT_EQ(metadata.platform, "Android");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform, "Linux");
 #elif BUILDFLAG(IS_FREEBSD)
   EXPECT_EQ(metadata.platform, "FreeBSD");
