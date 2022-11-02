$NetBSD$

Fix test portability.
Sent upstream, upstream seems unwilling to fix this.

--- contrib/packages/fedora/10-dns2gns.sh.orig	2022-11-01 19:42:47.417189244 +0100
+++ contrib/packages/fedora/10-dns2gns.sh	2022-11-01 19:44:26.474856703 +0100
@@ -28,7 +28,7 @@
         exit 1
       fi
       olddns=$(resolvectl status $interface | grep "DNS Servers" | cut -d':' -f2-)
-      if [ $? == 0 ]; then
+      if [ $? = 0 ]; then
         #echo "Setting to $dns2gns:$port [$dns2gns6]:$port $olddns 9.9.9.9"
         #resolvectl dns $interface $dns2gns:$port [$dns2gns6]:$port $olddns 9.9.9.9
         echo "Setting to $dns2gns:$port [$dns2gns6]:$port"
