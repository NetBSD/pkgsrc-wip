$NetBSD$

Fix for a use-after-free error causing a SIGSEGV crash during destructor call.

--- lib/client.cpp.orig	2025-11-22 07:37:21.756132969 +0000
+++ lib/client.cpp
@@ -250,6 +250,8 @@ Client::~Client() {
     event_del(&this->stop_event);
     event_del(&this->cancel_requests_timer);
     event_base_free(this->evbase);
+    curl_multi_setopt(this->multi, CURLMOPT_SOCKETFUNCTION, NULL);
+    curl_multi_setopt(this->multi, CURLMOPT_TIMERFUNCTION, NULL);
     curl_multi_cleanup(this->multi);
 }
 
