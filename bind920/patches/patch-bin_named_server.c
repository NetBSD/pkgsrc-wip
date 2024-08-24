$NetBSD$

Part of fix to ("BIND relinquishes privileges too early")

https://gitlab.isc.org/isc-projects/bind9/-/issues/4793
pulled from
https://gitlab.isc.org/isc-projects/bind9/-/merge_requests/9123

--- bin/named/server.c.orig	2024-07-08 13:09:16.774268226 +0000
+++ bin/named/server.c
@@ -9281,7 +9281,7 @@ load_configuration(const char *filename,
 	 * Relinquish root privileges.
 	 */
 	if (first_time) {
-		named_os_changeuser();
+		named_os_tempuser(named_os_uid());
 	}
 
 	/*
@@ -9628,6 +9628,9 @@ load_configuration(const char *filename,
 	isc_loopmgr_resume(named_g_loopmgr);
 	exclusive = false;
 
+	/* Take back root privileges temporarily */
+	named_os_tempuser(0);
+
 	/* Configure the statistics channel(s) */
 	result = named_statschannels_configure(named_g_server, config,
 					       named_g_aclconfctx);
@@ -9655,6 +9658,13 @@ load_configuration(const char *filename,
 	(void)ns_interfacemgr_scan(server->interfacemgr, true, true);
 
 	/*
+	 * Permanently drop root privileges now.
+	 */
+	if (first_time) {
+		named_os_changeuser();
+	}
+
+	/*
 	 * These cleans up either the old production view list
 	 * or our temporary list depending on whether they
 	 * were swapped above or not.
@@ -13175,7 +13185,7 @@ nzd_env_close(dns_view_t *view) {
 	/*
 	 * Database files must be owned by the eventual user, not by root.
 	 */
-	ret = chown(dbpath_copy, ns_os_uid(), -1);
+	ret = chown(dbpath_copy, named_os_uid(), -1);
 	UNUSED(ret);
 
 	/*
