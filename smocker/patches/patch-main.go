$NetBSD$

Adjust paths to pkgsrc.

--- main.go.orig	2022-04-27 09:42:26.000000000 +0000
+++ main.go
@@ -28,12 +28,12 @@ func parseConfig() (c config.Config) {
 	flag.StringVar(&c.ConfigBasePath, "config-base-path", "/", "Base path applied to Smocker UI")
 	flag.IntVar(&c.ConfigListenPort, "config-listen-port", 8081, "Listening port of Smocker administration server")
 	flag.IntVar(&c.MockServerListenPort, "mock-server-listen-port", 8080, "Listening port of Smocker mock server")
-	flag.StringVar(&c.StaticFiles, "static-files", ".", "Location of the static files to serve (index.html, etc.)")
+	flag.StringVar(&c.StaticFiles, "static-files", "@PREFIX@/share/smocker", "Location of the static files to serve (index.html, etc.)")
 	flag.IntVar(&c.HistoryMaxRetention, "history-retention", 0, "Maximum number of calls to keep in the history per session (0 = no limit)")
 	flag.StringVar(&c.PersistenceDirectory, "persistence-directory", "", "If defined, the directory where the sessions will be synchronized")
 	flag.BoolVar(&c.TLSEnable, "tls-enable", false, "Enable TLS using the provided certificate")
-	flag.StringVar(&c.TLSCertFile, "tls-cert-file", "/etc/smocker/tls/certs/cert.pem", "Path to TLS certificate file ")
-	flag.StringVar(&c.TLSKeyFile, "tls-private-key-file", "/etc/smocker/tls/private/key.pem", "Path to TLS key file")
+	flag.StringVar(&c.TLSCertFile, "tls-cert-file", "@PKG_SYSCONFDIR@/tls/certs/cert.pem", "Path to TLS certificate file ")
+	flag.StringVar(&c.TLSKeyFile, "tls-private-key-file", "@PKG_SYSCONFDIR@/tls/private/key.pem", "Path to TLS key file")
 	flag.Parse()
 	return
 }
