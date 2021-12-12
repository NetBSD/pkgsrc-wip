$NetBSD$

--- src/nvim/message.c.orig	2021-11-30 17:20:42.000000000 +0000
+++ src/nvim/message.c
@@ -2056,7 +2056,7 @@ static void msg_puts_display(const char_
       msg_ext_last_attr = attr;
     }
     // Concat pieces with the same highlight
-    size_t len = strnlen((char *)str, maxlen);             // -V781
+    size_t len = STRNLEN(str, maxlen);             // -V781
     ga_concat_len(&msg_ext_last_chunk, (char *)str, len);
     msg_ext_cur_len += len;
     return;
