$NetBSD: patch-third__party_WebKit_Source_WebCore_websockets_WebSocketHandshake.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/websockets/WebSocketHandshake.cpp.orig	2011-04-13 08:12:39.000000000 +0000
+++ third_party/WebKit/Source/WebCore/websockets/WebSocketHandshake.cpp
@@ -325,7 +325,33 @@ int WebSocketHandshake::readServerHandsh
         return len;
     }
     m_mode = Normal;
+#if defined(OS_NETBSD)
+    const char *s = header;
+    const char *find = "\r\n\r\n";
+    size_t flen;
+    char c, sc;
+    char *comma = (char *)s;
+
+    if ((c = *find++) != '\0') {
+        flen = strlen(find);
+        do {
+            do {
+                if (len-- < 1 || (sc = *s++) == '\0') {
+                    comma = NULL;
+                    break;
+                }
+            } while (sc != c);
+            if (flen > len) {
+                comma = NULL;
+                break;
+            }
+        } while (strncmp(s, find, flen) != 0);
+        s--;
+    }
+    if (comma == NULL) {
+#else
     if (!strnstr(header, "\r\n\r\n", len)) {
+#endif
         // Just hasn't been received fully yet.
         m_mode = Incomplete;
         return -1;
