$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/embedder_support/user_agent_utils_unittest.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/embedder_support/user_agent_utils_unittest.cc
@@ -71,7 +71,7 @@ const char kDesktop[] =
     "X11; CrOS x86_64 14541.0.0"
 #elif BUILDFLAG(IS_FUCHSIA)
     "Fuchsia"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "X11; Linux x86_64"
 #elif BUILDFLAG(IS_MAC)
     "Macintosh; Intel Mac OS X 10_15_7"
@@ -84,7 +84,7 @@ const char kDesktop[] =
     "Safari/537.36";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string GetMachine() {
   struct utsname unixinfo;
   uname(&unixinfo);
@@ -192,7 +192,7 @@ void CheckUserAgentStringOrdering(bool m
     int value;
     ASSERT_TRUE(base::StringToInt(pieces[i], &value));
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // X11; Linux x86_64
   ASSERT_EQ(2u, pieces.size());
   ASSERT_EQ("X11", pieces[0]);
@@ -750,7 +750,7 @@ TEST_F(UserAgentUtilsTest, UserAgentMeta
 #endif
 #elif BUILDFLAG(IS_ANDROID)
   EXPECT_EQ(metadata.platform, "Android");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(metadata.platform, "Linux");
 #elif BUILDFLAG(IS_FREEBSD)
   EXPECT_EQ(metadata.platform, "FreeBSD");
