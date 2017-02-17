$NetBSD$

--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2017-02-02 02:02:50.000000000 +0000
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -71,7 +71,7 @@ void ShowBadFlagsPrompt(Browser* browser
     // This flag gives extensions more powers.
     extensions::switches::kExtensionsOnChromeURLs,
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
