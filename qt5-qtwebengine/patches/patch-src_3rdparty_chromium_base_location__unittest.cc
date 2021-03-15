$NetBSD$

--- src/3rdparty/chromium/base/location_unittest.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/location_unittest.cc
@@ -32,7 +32,7 @@ TEST(LocationTest, CurrentYieldsCorrectV
   EXPECT_EQ(here.line_number(), previous_line + 1);
   EXPECT_STREQ("TestBody", here.function_name());
 #endif
-#elif defined(OFFICIAL_BUILD)
+#elif defined(OFFICIAL_BUILD) && !defined(OS_BSD)
 #error Location builtins must be supported in official builds.
 #elif BUILDFLAG(FROM_HERE_USES_LOCATION_BUILTINS)
 #error FROM_HERE requires location builtins to be supported.
