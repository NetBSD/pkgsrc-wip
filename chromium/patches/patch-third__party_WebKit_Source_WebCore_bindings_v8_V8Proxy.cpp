$NetBSD: patch-third__party_WebKit_Source_WebCore_bindings_v8_V8Proxy.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/bindings/v8/V8Proxy.cpp.orig	2011-04-13 08:12:33.000000000 +0000
+++ third_party/WebKit/Source/WebCore/bindings/v8/V8Proxy.cpp
@@ -812,7 +812,34 @@ int V8Proxy::contextDebugId(v8::Handle<v
     if (!context->GetData()->IsString())
         return -1;
     v8::String::AsciiValue ascii(context->GetData());
+#if defined(OS_NETBSD)
+    const char *s = *ascii;
+    const char *find = ",";
+    size_t flen, len = ascii.length();
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
+    if (comma != NULL)
+        comma = (char *)s;
+#else
     char* comma = strnstr(*ascii, ",", ascii.length());
+#endif
     if (!comma)
         return -1;
     return atoi(comma + 1);
