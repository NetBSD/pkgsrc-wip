$NetBSD$

--- extensions/common/feature_switch.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ extensions/common/feature_switch.cc
@@ -39,7 +39,7 @@ class CommonSwitches {
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) || defined(OS_BSD)
             FeatureSwitch::DEFAULT_ENABLED)
 #else
             FeatureSwitch::DEFAULT_DISABLED)
