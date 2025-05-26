$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/feed/core/v2/feed_network_impl_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/feed/core/v2/feed_network_impl_unittest.cc
@@ -747,8 +747,8 @@ TEST_F(FeedNetworkTest, SendApiRequest_D
 
   EXPECT_EQ(feedwire::ClientInfo::CHROME_ANDROID, client_info.app_type());
   EXPECT_EQ(feedwire::Version::RELEASE, client_info.app_version().build_type());
-  EXPECT_EQ(1, client_info.app_version().major());
-  EXPECT_EQ(2, client_info.app_version().minor());
+  EXPECT_EQ(1, client_info.app_version().gmajor());
+  EXPECT_EQ(2, client_info.app_version().gminor());
   EXPECT_EQ(3, client_info.app_version().build());
   EXPECT_EQ(4, client_info.app_version().revision());
   EXPECT_FALSE(client_info.chrome_client_info().start_surface());
