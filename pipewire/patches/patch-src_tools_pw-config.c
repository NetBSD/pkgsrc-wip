$NetBSD$

--- src/tools/pw-config.c.orig	2024-10-21 17:01:05.914242136 +0000
+++ src/tools/pw-config.c
@@ -158,7 +158,11 @@ int main(int argc, char *argv[])
 		d.opt_colors = true;
 	d.opt_cmd = "paths";
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	while ((c = getopt_long(argc, argv, "hVn:p:LrNC", long_options, NULL)) != -1) {
 		switch (c) {
@@ -249,6 +253,10 @@ done:
 	pw_properties_free(d.assemble);
 	pw_properties_free(props);
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_deinit();
+#else
+	pipewire_deinit();
+#endif
 	return res;
 }
