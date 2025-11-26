$NetBSD$

Handle netbsd's xdrproc_t only taking two arguments

--- src/rpc/virnetmessage.c.orig	2018-09-26 11:26:50.963410008 +0000
+++ src/rpc/virnetmessage.c
@@ -358,7 +358,11 @@ int virNetMessageEncodePayload(virNetMes
                   msg->bufferLength - msg->bufferOffset, XDR_ENCODE);
 
     /* Try to encode the payload. If the buffer is too small increase it. */
+#ifdef __NetBSD__
+    while (!(*filter)(&xdr, data)) {
+#else
     while (!(*filter)(&xdr, data, 0)) {
+#endif
         unsigned int newlen = msg->bufferLength - VIR_NET_MESSAGE_LEN_MAX;
         newlen *= 2;
 
@@ -416,7 +420,11 @@ int virNetMessageDecodePayload(virNetMes
     xdrmem_create(&xdr, msg->buffer + msg->bufferOffset,
                   msg->bufferLength - msg->bufferOffset, XDR_DECODE);
 
+#ifdef __NetBSD__
+    if (!(*filter)(&xdr, data)) {
+#else
     if (!(*filter)(&xdr, data, 0)) {
+#endif
         virReportError(VIR_ERR_RPC, "%s", _("Unable to decode message payload"));
         goto error;
     }
