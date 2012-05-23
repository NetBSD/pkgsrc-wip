$NetBSD: patch-config.c,v 1.1.1.1 2012/05/23 15:37:12 hfath Exp $

--- config.c.orig	2012-05-23 13:52:36.000000000 +0000
+++ config.c
@@ -187,12 +187,12 @@ static const char *config_def_app_versio
 
 static const char *config_def_script(void)
 {
-	return "/etc/vpnc/vpnc-script";
+	return "@PKG_SYSCONFDIR@/vpnc/vpnc-script";
 }
 
 static const char *config_def_pid_file(void)
 {
-	return "/var/run/vpnc/pid";
+	return "@VARBASE@/run/vpnc/pid";
 }
 
 static const char *config_def_vendor(void)
@@ -200,6 +200,16 @@ static const char *config_def_vendor(voi
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
@@ -469,6 +479,21 @@ static const struct config_names_s {
 		"Target network in dotted decimal or CIDR notation\n",
 		config_def_target_network
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
+
 		0, 0, 0, NULL, NULL, NULL, NULL, NULL
 	}
 };
@@ -477,7 +502,7 @@ static char *get_config_filename(const c
 {
 	char *realname;
 
-	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "/etc/vpnc/", name, add_dot_conf ? ".conf" : "");
+	asprintf(&realname, "%s%s%s", index(name, '/') ? "" : "@PKG_SYSCONFDIR@/vpnc/", name, add_dot_conf ? ".conf" : "");
 	return realname;
 }
 
@@ -696,8 +721,8 @@ void do_config(int argc, char **argv)
 	}
 
 	if (!got_conffile) {
-		read_config_file("/etc/vpnc/default.conf", config, 1);
-		read_config_file("/etc/vpnc.conf", config, 1);
+		read_config_file("@PKG_SYSCONFDIR@/vpnc/default.conf", config, 1);
+		read_config_file("@PKG_SYSCONFDIR@/vpnc.conf", config, 1);
 	}
 
 	if (!print_config) {
