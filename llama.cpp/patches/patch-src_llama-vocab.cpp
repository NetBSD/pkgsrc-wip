$NetBSD$

--- src/llama-vocab.cpp.orig	2025-05-16 09:52:44.723654390 +0000
+++ src/llama-vocab.cpp
@@ -2264,7 +2264,7 @@ void llama_vocab::impl::tokenizer_st_par
                         int64_t left_reminder_length = match - raw_text_base_offset;
 
                         if (data.attr & LLAMA_TOKEN_ATTR_LSTRIP) {
-                            while (left_reminder_length > 0 && isspace(raw_text[left_reminder_offset + left_reminder_length - 1])) {
+                            while (left_reminder_length > 0 && isspace((unsigned char)(raw_text[left_reminder_offset + left_reminder_length - 1]))) {
                                 left_reminder_length--;
                             }
                         }
@@ -2289,7 +2289,7 @@ void llama_vocab::impl::tokenizer_st_par
                         int64_t right_reminder_length = raw_text_base_length - ((match - raw_text_base_offset) + text.length());
 
                         if (data.attr & LLAMA_TOKEN_ATTR_RSTRIP) {
-                            while (right_reminder_length > 0 && isspace(raw_text[right_reminder_offset])) {
+                            while (right_reminder_length > 0 && isspace((unsigned char)(raw_text[right_reminder_offset]))) {
                                 right_reminder_offset++;
                                 right_reminder_length--;
                             }
