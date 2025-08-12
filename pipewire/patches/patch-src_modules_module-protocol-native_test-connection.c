$NetBSD$

--- src/modules/module-protocol-native/test-connection.c.orig	2024-10-21 17:46:33.774732133 +0000
+++ src/modules/module-protocol-native/test-connection.c
@@ -172,7 +172,11 @@ int main(int argc, char *argv[])
 	struct pw_protocol_native_connection *in, *out;
 	int fds[2];
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 	pw_init(&argc, &argv);
+#else
+	pipewire_init(&argc, &argv);
+#endif
 
 	PW_LOG_TOPIC_INIT(mod_topic);
 	PW_LOG_TOPIC_INIT(mod_topic_connection);
