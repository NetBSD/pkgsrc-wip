$NetBSD: patch-config.c,v 1.3 2014/02/20 20:53:59 hfath Exp $

--- config.c.orig	2014-09-05 20:53:13.000000000 +0000
+++ config.c
@@ -362,12 +362,12 @@ static const char *config_def_app_versio
 
 static const char *config_def_script(void)
 {
-	return "/etc/vpnc/vpnc-script";
+	return "@PKG_SYSCONFDIR@/vpnc/vpnc-script";
 }
 
 static const char *config_def_pid_file(void)
 {
-	return "/var/run/vpnc.pid";
+	return "@VARBASE@/run/vpnc.pid";
 }
 
 static const char *config_def_vendor(void)
@@ -375,6 +375,16 @@ static const char *config_def_vendor(voi
 	return "cisco";
 }
 
+static const char *config_def_networks_list(void)
+{
+	return "";
+}
+
+static const char *config_def_dns_update(void)
+{
+	return "Yes";
+}
+
 static const char *config_def_target_network(void)
 {
 	return "0.0.0.0/0.0.0.0";
@@ -650,6 +660,20 @@ static const struct config_names_s {
 		"path to password program or helper name\n",
 		NULL
 	}, {
+		CONFIG_DNS_UPDATE, 1, 1,
+		"--dns-update",
+		"DNSUpdate",
+		"",
+		"DEPRECATED extension from Debian",
+		config_def_dns_update
+	}, {
+		CONFIG_TARGET_NETWORKS, 1, 1,
+		"--target-networks",
+		"Target Networks",
+		NULL,
+		"DEPRECATED extension from Debian",
+		config_def_networks_list
+	}, {
 		0, 0, 0, NULL, NULL, NULL, NULL, NULL
 	}
 };
@@ -658,7 +682,7 @@ static char *get_config_filename(const c
 {
 	char *realname;
 
-	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
+	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "@PKG_SYSCONFDIR@/vpnc/", name, add_dot_conf ? ".conf" : "");
 	return realname;
 }
 
@@ -894,8 +918,8 @@ void do_config(int argc, char **argv)
 	}
 
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("@PKG_SYSCONFDIR@/vpnc/default.conf", config, 1);
+		read_config_file("@PKG_SYSCONFDIR@/vpnc.conf", config, 1);
 	}
 
 	if (!print_config) {
@@ -1034,7 +1058,7 @@ void do_config(int argc, char **argv)
 	}
 
 	if (!config[CONFIG_IPSEC_GATEWAY])
-		error(1, 0, "missing IPSec gatway address");
+		error(1, 0, "missing IPSec gateway address");
 	if (!config[CONFIG_IPSEC_ID])
 		error(1, 0, "missing IPSec ID");
 	if (!config[CONFIG_IPSEC_SECRET])
