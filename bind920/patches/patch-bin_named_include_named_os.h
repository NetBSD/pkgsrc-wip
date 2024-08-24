$NetBSD$

Part of fix to
https://gitlab.isc.org/isc-projects/bind9/-/issues/4793
pulled from
https://gitlab.isc.org/isc-projects/bind9/-/merge_requests/9123

--- bin/named/include/named/os.h.orig	2024-07-08 13:09:16.770267986 +0000
+++ bin/named/include/named/os.h
@@ -41,8 +41,11 @@ named_os_inituserinfo(const char *userna
 void
 named_os_changeuser(void);
 
+void
+named_os_tempuser(uid_t uid);
+
 uid_t
-ns_os_uid(void);
+named_os_uid(void);
 
 void
 named_os_adjustnofile(void);
