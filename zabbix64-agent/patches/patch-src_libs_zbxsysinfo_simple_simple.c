$NetBSD$

Enclose macro argument in () to ensure proper handling.

--- src/libs/zbxsysinfo/simple/simple.c.orig	2023-03-31 17:00:35.699821153 +0900
+++ src/libs/zbxsysinfo/simple/simple.c	2023-04-08 09:56:30.577666918 +0900
@@ -188,14 +188,14 @@
 				"https://"), host);
 	}
 
-	if (CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_USERAGENT, "Zabbix " ZABBIX_VERSION)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_URL, https_host)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_PORT, (long)port)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_NOBODY, 1L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_SSL_VERIFYPEER, 0L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_SSL_VERIFYHOST, 0L)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_TIMEOUT, (long)timeout)) ||
-		CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = ZBX_CURLOPT_ACCEPT_ENCODING, "")))
+	if (CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_USERAGENT), "Zabbix " ZABBIX_VERSION)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_URL), https_host)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_PORT), (long)port)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_NOBODY), 1L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_SSL_VERIFYPEER), 0L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_SSL_VERIFYHOST), 0L)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_TIMEOUT), (long)timeout)) ||
+		CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = ZBX_CURLOPT_ACCEPT_ENCODING), "")))
 	{
 		zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set cURL option [%d]: %s",
 				__func__, (int)opt, curl_easy_strerror(err));
@@ -215,7 +215,7 @@
 
 	if (NULL != CONFIG_SOURCE_IP)
 	{
-		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_INTERFACE, CONFIG_SOURCE_IP)))
+		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_INTERFACE), CONFIG_SOURCE_IP)))
 		{
 			zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set source interface option [%d]: %s",
 					__func__, (int)opt, curl_easy_strerror(err));
