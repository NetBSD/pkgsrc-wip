$NetBSD$

pick from 95485f2f9b181cc710ddbf806b5f8601f23edb33

--- src/gns/test_plugin_rest_gns.sh~
+++ src/gns/test_plugin_rest_gns.sh
@@ -24,7 +24,7 @@ curl_get () {
     #$2 is grep
     cache="$(gnurl -v "$1" 2>&1 | grep "$2")"
     #echo "$cache"
-    if [ "" == "$cache" ]
+    if [ "" = "$cache" ]
     then
         gnunet-identity -D "$TEST_TLD" -c test_gns_lookup.conf > /dev/null 2>&1
         gnunet-arm -e -c test_gns_lookup.conf
