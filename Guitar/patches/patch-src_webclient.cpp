$NetBSD$

NetBSD does not provide gethostbyname_r.

--- src/webclient.cpp.orig	2025-07-21 19:55:26.509062241 +0000
+++ src/webclient.cpp
@@ -102,7 +102,7 @@ bool HostNameResolver::resolve(const cha
 	if (!name || !out) return false;
 
 	struct hostent *he = nullptr;
-#if defined(_WIN32) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__NetBSD__)
 	he = ::gethostbyname(name);
 #else
 	int err = 0;
