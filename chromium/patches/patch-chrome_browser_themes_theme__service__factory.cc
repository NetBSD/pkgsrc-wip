$NetBSD$

--- chrome/browser/themes/theme_service_factory.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/themes/theme_service_factory.cc
@@ -22,7 +22,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
@@ -77,7 +77,7 @@ ThemeServiceFactory::~ThemeServiceFactor
 
 KeyedService* ThemeServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* profile) const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
@@ -89,7 +89,7 @@ KeyedService* ThemeServiceFactory::Build
 
 void ThemeServiceFactory::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   bool default_uses_system_theme = false;
 
   const views::LinuxUI* linux_ui = views::LinuxUI::instance();
