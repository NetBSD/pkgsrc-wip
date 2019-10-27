$NetBSD$

pick from cf9440cc40334ed87755615ecf6d5d2c2445f17b

--- src/namestore/test_plugin_rest_namestore.sh~
+++ src/namestore/test_plugin_rest_namestore.sh
@@ -25,7 +25,7 @@ curl_get () {
   resp=$(curl -v "$1" 2>&1)
   cache="$(echo $resp | grep "$2")"
   #echo $cache
-  if [ "" == "$cache" ]
+  if [ "" = "$cache" ]
   then
     echo "Error in get response: $resp, expected $2"
     gnunet-arm -e -c test_namestore_api.conf
@@ -40,7 +40,7 @@ curl_post () {
   resp=$(curl -v -X "POST" "$1" --data "$2" 2>&1)
   cache="$(echo $resp | grep "$3")"
   #echo $cache
-  if [ "" == "$cache" ]
+  if [ "" = "$cache" ]
   then
     echo "Error in post response: $resp ($2), expected $3"
     gnunet-arm -e -c test_namestore_api.conf
@@ -54,7 +54,7 @@ curl_delete () {
   resp=$(curl -v -X "DELETE" "$1" 2>&1)
   cache="$(echo $resp | grep "$2")"
   #echo $cache
-  if [ "" == "$cache" ]
+  if [ "" = "$cache" ]
   then
     echo "Error in delete response: $resp, expected $2"
     gnunet-arm -e -c test_namestore_api.conf
