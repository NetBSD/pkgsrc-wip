$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2024-10-18 12:34:06.658470200 +0000
+++ components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -65,7 +65,7 @@ SignalsAggregatorImpl::SignalsAggregator
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
