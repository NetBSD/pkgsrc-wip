$NetBSD$

--- components/viz/test/mock_display_client.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ components/viz/test/mock_display_client.h
@@ -36,7 +36,7 @@ class MockDisplayClient : public mojom::
   MOCK_METHOD1(SetWideColorEnabled, void(bool enabled));
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif
 
