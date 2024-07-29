$NetBSD$

Cast argument to isspace to unsigned char, as required by POSIX, else this
breaks with UTF-8 chars on NetBSD.

--- src/graphic/text/textstream.cc.orig	2024-03-28 10:12:05.000000000 +0000
+++ src/graphic/text/textstream.cc
@@ -49,12 +49,12 @@ void TextStream::consume(size_t cnt) {
  * r* means skip_ws starting from the back of the string
  */
 void TextStream::skip_ws() {
-	while (pos_ < end_ && (isspace(text_[pos_]) != 0)) {
+	while (pos_ < end_ && (isspace(static_cast<unsigned char>(text_[pos_])) != 0)) {
 		consume(1);
 	}
 }
 void TextStream::rskip_ws() {
-	while (pos_ < end_ && (isspace(text_[end_ - 1]) != 0)) {
+	while (pos_ < end_ && (isspace(static_cast<unsigned char>(text_[end_ - 1])) != 0)) {
 		--end_;
 	}
 }
