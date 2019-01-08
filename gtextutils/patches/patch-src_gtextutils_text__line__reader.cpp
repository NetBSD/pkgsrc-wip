$NetBSD$

# Modern C++ compilers don't implicitly convert istream to bool

--- src/gtextutils/text_line_reader.cpp.orig	2014-01-05 14:09:32.000000000 -0600
+++ src/gtextutils/text_line_reader.cpp	2019-01-07 19:39:57.233565835 -0600
@@ -44,6 +44,7 @@ bool TextLineReader::next_line()
 	if (input_stream.eof())
 		return false;
 
-	return input_stream ;
+        // Fix based on the only code change since 0.7
+	return input_stream.good() ;
 }
 
