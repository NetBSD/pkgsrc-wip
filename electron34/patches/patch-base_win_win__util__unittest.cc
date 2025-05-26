$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/win/win_util_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/win/win_util_unittest.cc
@@ -84,6 +84,12 @@ TEST(BaseWinUtilTest, TestUint32ToInvali
   EXPECT_EQ(INVALID_HANDLE_VALUE, Uint32ToHandle(invalid_handle));
 }
 
+TEST(BaseWinUtilTest, PseudoHandles) {
+  EXPECT_TRUE(IsPseudoHandle(::GetCurrentProcess()));
+  EXPECT_TRUE(IsPseudoHandle(::GetCurrentThread()));
+  EXPECT_FALSE(IsPseudoHandle(nullptr));
+}
+
 TEST(BaseWinUtilTest, WStringFromGUID) {
   const GUID kGuid = {0x7698f759,
                       0xf5b0,
