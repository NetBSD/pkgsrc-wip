$NetBSD$

- Ignore SIGPIPE globally, backported from upstream commit
  5935505d197620010be9366d6e6e84162a39e90c.
- Add casts betweeh char * and uint8_t * (to avoid warnings), backported from upstream
  commit 28235699f040cd0fa41f2d0e6d38328c0fe79579.
- Don't map files MAP_NOCORE if that's not defined, backported from upstream
  commit c8713c2f66eb42c5a3fcb7d16ae64997f7a9a33a.

--- main.c.orig	2021-01-30 11:25:00.884762293 +0000
+++ main.c
@@ -4,6 +4,7 @@
 
 #include <errno.h>
 #include <inttypes.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -117,7 +118,7 @@ s3_put(const char * key_id, const char *
 		goto err3;
 
 	/* Send the request. */
-	if ((errstr = sslreq2(host, "443", CERTFILE, headers, len,
+	if ((errstr = sslreq2(host, "443", CERTFILE, (uint8_t *)headers, len,
 	    buf, buflen, resp, &resplen)) != NULL) {
 		warnp("SSL request failed: %s", errstr);
 		goto err4;
@@ -127,11 +128,11 @@ s3_put(const char * key_id, const char *
 	resp[resplen] = '\0';
 
         /* Find the end of the first line. */
-        pos = strcspn(resp, "\r\n");
+        pos = strcspn((char *)resp, "\r\n");
 
         /* Look for a "200" status on the first line. */
-        if ((strstr(resp, " 200 ") == NULL) ||
-            (strstr(resp, " 200 ") > (char *)&resp[pos])) {
+        if ((strstr((char *)resp, " 200 ") == NULL) ||
+            (strstr((char *)resp, " 200 ") > (char *)&resp[pos])) {
 		warnp("S3 request failed:\n%s\n", resp);
 		goto err4;
 	}
@@ -386,7 +387,8 @@ uploadvolume(const char * fname, const c
 		free(s);
 		goto err2;
 	}
-	if (s3_put_loop(key_id, key_secret, region, bucket, path, s, len)) {
+	if (s3_put_loop(key_id, key_secret, region, bucket, path,
+	    (uint8_t *)s, len)) {
 		free(path);
 		free(s);
 		goto err2;
@@ -433,11 +435,11 @@ ec2_apicall(const char * key_id, const c
 	uint8_t * resp;
 	size_t resplen;
 	size_t pos;
-	uint8_t * body;
+	char * body;
 
 	/* Sign request. */
-	if (aws_sign_ec2_headers(key_id, key_secret, region, s, strlen(s),
-	    &x_amz_content_sha256, &x_amz_date, &authorization)) {
+	if (aws_sign_ec2_headers(key_id, key_secret, region, (uint8_t *)s,
+	    strlen(s), &x_amz_content_sha256, &x_amz_date, &authorization)) {
 		warnp("Failed to sign EC2 POST request");
 		goto err0;
 	}
@@ -468,8 +470,8 @@ ec2_apicall(const char * key_id, const c
 		goto err3;
 
 	/* Send the request. */
-	if ((errstr = sslreq(host, "443", CERTFILE, req, len, resp, &resplen))
-	    != NULL) {
+	if ((errstr = sslreq(host, "443", CERTFILE, (uint8_t *)req, len,
+	    resp, &resplen)) != NULL) {
 		warnp("SSL request failed: %s", errstr);
 		goto err4;
 	}
@@ -478,23 +480,23 @@ ec2_apicall(const char * key_id, const c
 	resp[resplen] = '\0';
 
 	/* EC2 API responses should not contain NUL bytes. */
-	if (strlen(resp) != resplen) {
+	if (strlen((char *)resp) != resplen) {
 		warnp("NUL byte in EC2 API response");
 		goto err4;
 	}
 
         /* Find the end of the first line. */
-        pos = strcspn(resp, "\r\n");
+        pos = strcspn((char *)resp, "\r\n");
 
         /* Look for a "200" status on the first line. */
-        if ((strstr(resp, " 200 ") == NULL) ||
-            (strstr(resp, " 200 ") > (char *)&resp[pos])) {
+        if ((strstr((char *)resp, " 200 ") == NULL) ||
+            (strstr((char *)resp, " 200 ") > (char *)&resp[pos])) {
 		warnp("EC2 API request failed:\n%s\n", resp);
 		goto err4;
 	}
 
 	/* Find the end of the headers. */
-	if ((body = strstr(resp, "\r\n\r\n")) == NULL) {
+	if ((body = strstr((char *)resp, "\r\n\r\n")) == NULL) {
 		warnp("Bad EC2 API response received:\n%s\n", resp);
 		goto err4;
 	}
@@ -1257,8 +1259,11 @@ uploadsnap(const char * fname, const cha
 	len = sb.st_size;
 
 	/* Map the file. */
-	if ((p = mmap(NULL, len, PROT_READ, MAP_PRIVATE | MAP_NOCORE,
-	    fileno(f), 0)) == MAP_FAILED) {
+	if ((p = mmap(NULL, len, PROT_READ, MAP_PRIVATE
+#ifdef MAP_NOCORE
+		| MAP_NOCORE
+#endif
+	    , fileno(f), 0)) == MAP_FAILED) {
 		warnp("Could not map disk image");
 		goto err1;
 	}
@@ -1660,7 +1665,8 @@ ssm_store(const char * key_id, const cha
 
 	/* Sign request. */
 	if (aws_sign_ssm_headers(key_id, key_secret, region, "PutParameter",
-	    s, strlen(s), &x_amz_content_sha256, &x_amz_date, &authorization)) {
+	    (uint8_t *)s, strlen(s), &x_amz_content_sha256, &x_amz_date,
+	    &authorization)) {
 		warnp("Failed to sign SSM PutParameter request");
 		goto err1;
 	}
@@ -1693,8 +1699,8 @@ ssm_store(const char * key_id, const cha
 		goto err4;
 
 	/* Send the request. */
-	if ((errstr = sslreq(host, "443", CERTFILE, req, len, resp, &resplen))
-	    != NULL) {
+	if ((errstr = sslreq(host, "443", CERTFILE, (uint8_t *)req, len,
+	    resp, &resplen)) != NULL) {
 		warnp("SSL request failed: %s", errstr);
 		goto err5;
 	}
@@ -1703,17 +1709,17 @@ ssm_store(const char * key_id, const cha
 	resp[resplen] = '\0';
 
 	/* EC2 API responses should not contain NUL bytes. */
-	if (strlen(resp) != resplen) {
+	if (strlen((char *)resp) != resplen) {
 		warnp("NUL byte in SSM API response");
 		goto err5;
 	}
 
         /* Find the end of the first line. */
-        pos = strcspn(resp, "\r\n");
+        pos = strcspn((char *)resp, "\r\n");
 
         /* Look for a "200" status on the first line. */
-        if ((strstr(resp, " 200 ") == NULL) ||
-            (strstr(resp, " 200 ") > (char *)&resp[pos])) {
+        if ((strstr((char *)resp, " 200 ") == NULL) ||
+            (strstr((char *)resp, " 200 ") > (char *)&resp[pos])) {
 		warnp("SSM API request failed:\n%s\n", resp);
 		goto err5;
 	}
@@ -1774,7 +1780,7 @@ sns_publish(const char * key_id, const c
 	uint8_t * resp;
 	size_t resplen;
 	size_t pos;
-	uint8_t * body;
+	char * body;
 
 	/* Construct message subject. */
 	if (asprintf(&msg_subject, "New %s AMIs", releaseversion) == -1)
@@ -1850,8 +1856,8 @@ sns_publish(const char * key_id, const c
 	region[strcspn(region, ":")] = '\0';
 
 	/* Sign request. */
-	if (aws_sign_sns_headers(key_id, key_secret, region, s, strlen(s),
-	    &x_amz_content_sha256, &x_amz_date, &authorization)) {
+	if (aws_sign_sns_headers(key_id, key_secret, region, (uint8_t *)s,
+	    strlen(s), &x_amz_content_sha256, &x_amz_date, &authorization)) {
 		warnp("Failed to sign SNS POST request");
 		goto err5;
 	}
@@ -1883,8 +1889,8 @@ sns_publish(const char * key_id, const c
 		goto err8;
 
 	/* Send the request. */
-	if ((errstr = sslreq(host, "443", CERTFILE, req, len, resp, &resplen))
-	    != NULL) {
+	if ((errstr = sslreq(host, "443", CERTFILE, (uint8_t *)req, len,
+	    resp, &resplen)) != NULL) {
 		warnp("SSL request failed: %s", errstr);
 		goto err9;
 	}
@@ -1893,23 +1899,23 @@ sns_publish(const char * key_id, const c
 	resp[resplen] = '\0';
 
 	/* SNS API responses should not contain NUL bytes. */
-	if (strlen(resp) != resplen) {
+	if (strlen((char *)resp) != resplen) {
 		warnp("NUL byte in SNS API response");
 		goto err9;
 	}
 
         /* Find the end of the first line. */
-        pos = strcspn(resp, "\r\n");
+        pos = strcspn((char *)resp, "\r\n");
 
         /* Look for a "200" status on the first line. */
-        if ((strstr(resp, " 200 ") == NULL) ||
-            (strstr(resp, " 200 ") > (char *)&resp[pos])) {
+        if ((strstr((char *)resp, " 200 ") == NULL) ||
+            (strstr((char *)resp, " 200 ") > (char *)&resp[pos])) {
 		warnp("SNS API request failed:\n%s\n", resp);
 		goto err9;
 	}
 
 	/* Find the end of the headers. */
-	if ((body = strstr(resp, "\r\n\r\n")) == NULL) {
+	if ((body = strstr((char *)resp, "\r\n\r\n")) == NULL) {
 		warnp("Bad SNS API response received:\n%s\n", resp);
 		goto err9;
 	}
@@ -2082,6 +2088,12 @@ main(int argc, char * argv[])
 		exit(1);
 	}
 
+	/* Ignore SIGPIPE. */
+	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
+		warnp("signal(SIGPIPE)");
+		exit(1);
+	}
+
 	/* Get list of AWS regions. */
 	if (allregions) {
 		if (getregionlist(key_id, key_secret, region, &regions,
