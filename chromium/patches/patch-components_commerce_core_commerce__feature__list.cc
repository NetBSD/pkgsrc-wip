$NetBSD: patch-components_commerce_core_commerce__feature__list.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/commerce/core/commerce_feature_list.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/commerce/core/commerce_feature_list.cc
@@ -168,7 +168,7 @@ BASE_FEATURE(kPriceInsights,
              "PriceInsights",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPriceInsightsRegionLaunched,
              "PriceInsightsRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -250,7 +250,7 @@ const base::FeatureParam<bool> kDiscount
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, false};
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDiscountInfoApiRegionLaunched,
              "EnableDiscountInfoApiRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -289,7 +289,7 @@ const base::FeatureParam<bool> kDeleteAl
 
 BASE_FEATURE(kShoppingList, "ShoppingList", base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShoppingListRegionLaunched,
              "ShoppingListRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
