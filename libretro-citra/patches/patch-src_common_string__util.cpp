$NetBSD$

error: invalid conversion from 'char**' to 'const char**'

--- src/common/string_util.cpp.orig	2018-05-19 11:54:21.000000000 +0000
+++ src/common/string_util.cpp
@@ -359,14 +359,26 @@ static std::string CodeToUTF8(const char
     std::string out_buffer;
     out_buffer.resize(out_buffer_size);
 
+#ifdef __NetBSD__
+    const char* src_buffer = (const char*)(&input[0]);
+    size_t src_bytes = in_bytes;
+    char* dst_buffer = (char*)(&out_buffer[0]);
+    size_t dst_bytes = out_buffer.size();
+#else
     auto src_buffer = &input[0];
     size_t src_bytes = in_bytes;
     auto dst_buffer = &out_buffer[0];
     size_t dst_bytes = out_buffer.size();
+#endif
 
     while (0 != src_bytes) {
+#ifndef __NetBSD__
         size_t const iconv_result =
             iconv(conv_desc, (char**)(&src_buffer), &src_bytes, &dst_buffer, &dst_bytes);
+#else
+        size_t const iconv_result =
+            iconv(conv_desc, &src_buffer, &src_bytes, &dst_buffer, &dst_bytes);
+#endif
 
         if (static_cast<size_t>(-1) == iconv_result) {
             if (EILSEQ == errno || EINVAL == errno) {
@@ -407,7 +419,11 @@ std::u16string UTF8ToUTF16(const std::st
     std::u16string out_buffer;
     out_buffer.resize(out_buffer_size);
 
+#ifdef __NetBSD__
+    const char* src_buffer = (const char*)(&input[0]);
+#else
     char* src_buffer = const_cast<char*>(&input[0]);
+#endif
     size_t src_bytes = in_bytes;
     char* dst_buffer = (char*)(&out_buffer[0]);
     size_t dst_bytes = out_buffer.size();
