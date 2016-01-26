$NetBSD$

Use PKG_SYSCONFDIR.

--- libbeat/cfgfile/cfgfile.go.orig	2015-12-17 14:53:41.000000000 +0000
+++ libbeat/cfgfile/cfgfile.go
@@ -15,7 +15,7 @@ var testConfig *bool
 func init() {
 	// The default config cannot include the beat name as it is not initialised when this
 	// function is called, but see ChangeDefaultCfgfileFlag
-	configfile = flag.String("c", "/etc/beat/beat.yml", "Configuration file")
+	configfile = flag.String("c", "@PKG_SYSCONFDIR@/beat.yml", "Configuration file")
 	testConfig = flag.Bool("configtest", false, "Test configuration and exit.")
 }
 
@@ -26,7 +26,7 @@ func ChangeDefaultCfgfileFlag(beatName s
 	if cliflag == nil {
 		return fmt.Errorf("Flag -c not found")
 	}
-	cliflag.DefValue = fmt.Sprintf("/etc/%s/%s.yml", beatName, beatName)
+	cliflag.DefValue = fmt.Sprintf("@PKG_SYSCONFDIR@/%s.yml", beatName)
 	return cliflag.Value.Set(cliflag.DefValue)
 }
 
