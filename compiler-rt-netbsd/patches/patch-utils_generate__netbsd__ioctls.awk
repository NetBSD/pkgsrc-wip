$NetBSD$

--- utils/generate_netbsd_ioctls.awk.orig	2018-08-21 21:25:37.000000000 +0000
+++ utils/generate_netbsd_ioctls.awk
@@ -314,6 +314,7 @@ FNR == 1 {
       $0 ~ /PRIQ_IF_DETACH/ ||
       $0 ~ /PRIQ_ENABLE/ ||
       $0 ~ /WFQ_IF_ATTACH/ ||
+      $0 ~ /POWER_IOC_GET_TYPE_WITH_LOSSAGE/ ||
       $0 ~ /HFSC_DEL_FILTER/) {
     # There are entries with duplicate codes.. disable the less used ones
     next
@@ -345,17 +346,12 @@ FNR == 1 {
 
   # This !NONE check allows to skip some unparsable entries
   if (ioctl_mode[ioctl_table_max] != "NONE") {
-    # special cases first
-    if ($0 ~ /POWER_IOC_GET_TYPE_WITH_LOSSAGE/) {
-      ioctl_type[ioctl_table_max] = "sizeof(uptr)"
-    } else {
-      n = split($0, a, ",")
-      if (n == 3) {
-        gsub(/^[ ]+/, "", a[3])
-        match(a[3], /[a-zA-Z0-9_* ]+/)
-        type = get_type(substr(a[3], 0, RLENGTH))
-        ioctl_type[ioctl_table_max] = type
-      }
+    n = split($0, a, ",")
+    if (n == 3) {
+      gsub(/^[ ]+/, "", a[3])
+      match(a[3], /[a-zA-Z0-9_* ]+/)
+      type = get_type(substr(a[3], 0, RLENGTH))
+      ioctl_type[ioctl_table_max] = type
     }
   }
 
