$NetBSD$

Force HTTPS to download and query modules

--- src/backend/module_manager.cc.orig	2025-03-11 16:56:46.594281714 +0000
+++ src/backend/module_manager.cc
@@ -554,13 +554,13 @@ void backend_init_module_mgr_config(void
 
 	SWConfig config(confPath.c_str());
 
-	InstallSource is("FTP");
+	InstallSource is("HTTPS");
 	is.caption = "CrossWire";
-	is.source = "ftp.crosswire.org";
-	is.directory = "/pub/sword/raw";
+	is.source = "www.crosswire.org";
+	is.directory = "/ftpmirror/pub/sword/raw";
 
 	config["General"]["PassiveFTP"] = "true";
-	config["Sources"]["FTPSource"] = is.getConfEnt();
+	config["Sources"]["HTTPSSource"] = is.getConfEnt();
 	config.save();
 
 	InstallSource is_local("DIR");
