$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- google_apis/google_api_keys-inc.cc.orig	2024-10-18 12:34:18.412350200 +0000
+++ google_apis/google_api_keys-inc.cc
@@ -190,14 +190,18 @@ class APIKeyCache {
         STRINGIZE_NO_EXPANSION(GOOGLE_METRICS_SIGNING_KEY), std::string(),
         nullptr, std::string(), environment.get(), command_line, gaia_config);
 
+    // https://gitlab.archlinux.org/archlinux/packaging/packages/chromium/-/blob/main/use-oauth2-client-switches-as-default.patch?ref_type=heads
+    // Use the --oauth2-client-id= and --oauth2-client-secret= switches for
+    // setting GOOGLE_DEFAULT_CLIENT_ID and GOOGLE_DEFAULT_CLIENT_SECRET at
+    // runtime -- this allows signing into Chromium without baked-in values
     std::string default_client_id = CalculateKeyValue(
         GOOGLE_DEFAULT_CLIENT_ID,
         STRINGIZE_NO_EXPANSION(GOOGLE_DEFAULT_CLIENT_ID), std::string(),
-        nullptr, std::string(), environment.get(), command_line, gaia_config);
+        ::switches::kOAuth2ClientID, std::string(), environment.get(), command_line, gaia_config);
     std::string default_client_secret = CalculateKeyValue(
         GOOGLE_DEFAULT_CLIENT_SECRET,
         STRINGIZE_NO_EXPANSION(GOOGLE_DEFAULT_CLIENT_SECRET), std::string(),
-        nullptr, std::string(), environment.get(), command_line, gaia_config);
+        ::switches::kOAuth2ClientSecret, std::string(), environment.get(), command_line, gaia_config);
 
     // We currently only allow overriding the baked-in values for the
     // default OAuth2 client ID and secret using a command-line
