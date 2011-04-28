$NetBSD: patch-chrome_test_automation_automation__proxy__uitest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/automation/automation_proxy_uitest.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/automation/automation_proxy_uitest.cc
@@ -1376,7 +1376,7 @@ TEST_F(ExternalTabUITestPopupEnabled, MA
 #endif  // defined(OS_WIN)
 
 // TODO(port): Need to port autocomplete_edit_proxy.* first.
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 TEST_F(AutomationProxyTest, AutocompleteGetSetText) {
   scoped_refptr<BrowserProxy> browser(automation()->GetBrowserWindow(0));
   ASSERT_TRUE(browser.get());
@@ -1420,7 +1420,7 @@ TEST_F(AutomationProxyTest, Autocomplete
   EXPECT_EQ(text_to_set2, actual_text2);
 }
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 // Disabled, http://crbug.com/48601.
