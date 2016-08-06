$NetBSD$

--- chrome/common/extensions/docs/examples/api/nativeMessaging/host/uninstall_host.sh.orig	2016-08-05 17:14:49.000000000 +0000
+++ chrome/common/extensions/docs/examples/api/nativeMessaging/host/uninstall_host.sh
@@ -5,14 +5,14 @@
 
 set -e
 
-if [ "$(uname -s)" == "Darwin" ]; then
-  if [ "$(whoami)" == "root" ]; then
+if [ "$(uname -s)" = "Darwin" ]; then
+  if [ "$(whoami)" = "root" ]; then
     TARGET_DIR="/Library/Google/Chrome/NativeMessagingHosts"
   else
     TARGET_DIR="$HOME/Library/Application Support/Google/Chrome/NativeMessagingHosts"
   fi
 else
-  if [ "$(whoami)" == "root" ]; then
+  if [ "$(whoami)" = "root" ]; then
     TARGET_DIR="/etc/opt/chrome/native-messaging-hosts"
   else
     TARGET_DIR="$HOME/.config/google-chrome/NativeMessagingHosts"
