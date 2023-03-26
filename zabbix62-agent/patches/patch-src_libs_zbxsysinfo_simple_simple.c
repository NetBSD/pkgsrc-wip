$NetBSD$

Enclose macro argument in () to ensure proper handling.

--- src/libs/zbxsysinfo/simple/simple.c.orig	2023-02-01 07:20:47.633230938 +0000
+++ src/libs/zbxsysinfo/simple/simple.c
@@ -176,14 +176,14 @@ static int	check_https(const char *host,
 	else
 		zbx_snprintf(https_host, sizeof(https_host), "%s%s", (0 == strncmp(host, "https://", 8) ? "" : "https://"), host);
 
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
@@ -192,7 +192,7 @@ static int	check_https(const char *host,
 
 	if (NULL != CONFIG_SOURCE_IP)
 	{
-		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, opt = CURLOPT_INTERFACE, CONFIG_SOURCE_IP)))
+		if (CURLE_OK != (err = curl_easy_setopt(easyhandle, (opt = CURLOPT_INTERFACE), CONFIG_SOURCE_IP)))
 		{
 			zabbix_log(LOG_LEVEL_DEBUG, "%s: could not set source interface option [%d]: %s",
 					__func__, (int)opt, curl_easy_strerror(err));
