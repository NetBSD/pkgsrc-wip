$NetBSD: patch-src_read_kafka.c $

Adapt to newer librdkafka.
From collect commit 7536b41b8dee524307d3f9d4bf8773b7ec8314f0.

--- src/write_kafka.c.orig
+++ src/write_kafka.c
@@ -77,6 +77,14 @@ static void kafka_log(const rd_kafka_t *rkt, int level, const char *fac,
 }
 #endif
 
+static rd_kafka_resp_err_t kafka_error() {
+#if RD_KAFKA_VERSION >= 0x000b00ff
+  return rd_kafka_last_error();
+#else
+  return rd_kafka_errno2err(errno);
+#endif
+}
+
 static uint32_t kafka_hash(const char *keydata, size_t keylen) {
   uint32_t hash = 5381;
   for (; keylen > 0; keylen--)
@@ -147,7 +155,7 @@ static int kafka_handle(struct kafka_topic_context *ctx) /* {{{ */
     if ((ctx->topic = rd_kafka_topic_new(ctx->kafka, ctx->topic_name,
                                          topic_conf)) == NULL) {
       ERROR("write_kafka plugin: cannot create topic : %s\n",
-            rd_kafka_err2str(rd_kafka_errno2err(errno)));
+            rd_kafka_err2str(kafka_error()));
       return errno;
     }
 
