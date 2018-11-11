$NetBSD$

Use the correct data type for modification time.

The second part of the patch prevents wyeb from trying to download
urls which have failed (according to the http error code).

--- main.c.orig	2018-11-10 14:18:57.000000000 +0000
+++ main.c
@@ -2895,7 +2895,7 @@ static char *histdata(bool rest, bool al
 	int size = all ? 0 : confint("histviewsize");
 
 	int start = 0;
-	__time_t mtime = 0;
+	time_t mtime = 0;
 	for (int j = 2; j > 0; j--) for (int i = histfnum - 1; i >= 0; i--)
 	{
 		if (!rest && size && num >= size) break;
@@ -3948,6 +3948,9 @@ static gboolean policycb(
 	WebKitResponsePolicyDecision *rdec = dec;
 	WebKitURIResponse *res = webkit_response_policy_decision_get_response(rdec);
 
+	if(!SOUP_STATUS_IS_SUCCESSFUL(webkit_uri_response_get_status_code(res)))
+		return false;
+
 	bool dl = false;
 	char *msr = getset(win, "dlmimetypes");
 	//for checking whether is sub frame or not.
