$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/url_request/static_http_user_agent_settings.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/url_request/static_http_user_agent_settings.h
@@ -30,13 +30,17 @@ class NET_EXPORT StaticHttpUserAgentSett
     accept_language_ = new_accept_language;
   }
 
+  void set_user_agent(const std::string& new_user_agent) {
+    user_agent_ = new_user_agent;
+  }
+
   // HttpUserAgentSettings implementation
   std::string GetAcceptLanguage() const override;
   std::string GetUserAgent() const override;
 
  private:
   std::string accept_language_;
-  const std::string user_agent_;
+  std::string user_agent_;
 };
 
 }  // namespace net
