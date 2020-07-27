$NetBSD$

--- printing/print_settings_conversion.cc.orig	2020-07-15 18:56:00.000000000 +0000
+++ printing/print_settings_conversion.cc
@@ -208,7 +208,7 @@ bool PrintSettingsFromJobSettings(const 
 #endif
   }
 
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(USE_CUPS))
+#if defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
   if (advanced_settings) {
