$NetBSD: patch-flower_string-convert.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- flower/string-convert.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ flower/string-convert.cc
@@ -37,8 +37,8 @@ string
 String_convert::bin2hex (Byte bin_char)
 {
   string str;
-  str += to_string ((char) nibble2hex_byte ((Byte) (bin_char >> 4)));
-  str += to_string ((char) nibble2hex_byte (bin_char++));
+  str += ::to_string ((char) nibble2hex_byte ((Byte) (bin_char >> 4)));
+  str += ::to_string ((char) nibble2hex_byte (bin_char++));
   return str;
 }
 
@@ -49,8 +49,8 @@ String_convert::bin2hex (const string &b
   Byte const *byte = (Byte const *)bin_string.data ();
   for (ssize i = 0; i < bin_string.length (); i++)
     {
-      str += to_string ((char)nibble2hex_byte ((Byte) (*byte >> 4)));
-      str += to_string ((char)nibble2hex_byte (*byte++));
+      str += ::to_string ((char)nibble2hex_byte ((Byte) (*byte >> 4)));
+      str += ::to_string ((char)nibble2hex_byte (*byte++));
     }
   return str;
 }
@@ -127,7 +127,7 @@ String_convert::hex2bin (string hex_stri
       int low_i = hex2nibble (*byte++);
       if (high_i < 0 || low_i < 0)
         return 1; // invalid char
-      bin_string_r += to_string ((char) (high_i << 4 | low_i), 1);
+      bin_string_r += ::to_string ((char) (high_i << 4 | low_i), 1);
       i += 2;
     }
   return 0;
@@ -165,10 +165,10 @@ String_convert::int2dec (int i, size_t l
     fill_char = '0';
 
   // ugh
-  string dec_string = to_string (i);
+  string dec_string = ::to_string (i);
 
   // ugh
-  return to_string (fill_char, ssize_t (length_i - dec_string.length ())) + dec_string;
+  return ::to_string (fill_char, ssize_t (length_i - dec_string.length ())) + dec_string;
 }
 
 // stupido.  Should use int_string ()
@@ -182,14 +182,14 @@ String_convert::unsigned2hex (unsigned u
 #if 1 // both go...
   while (u)
     {
-      str = to_string ((char) ((u % 16)["0123456789abcdef"])) + str;
+      str = ::to_string ((char) ((u % 16)["0123456789abcdef"])) + str;
       u /= 16;
     }
 #else
   str += int_string (u, "%x");  // hmm. %lx vs. %x -> portability?
 #endif
 
-  str = to_string (fill_char, ssize_t (length - str.length ())) + str;
+  str = ::to_string (fill_char, ssize_t (length - str.length ())) + str;
   while ((str.length () > length) && (str[ 0 ] == 'f'))
     str = str.substr (2);
 
@@ -299,7 +299,7 @@ String_convert::pointer_string (void con
 string
 String_convert::precision_string (double x, int n)
 {
-  string format = "%." + to_string (max (0, n - 1)) + "e";
+  string format = "%." + ::to_string (max (0, n - 1)) + "e";
   string str = double_string (abs (x), format.c_str ());
 
   int exp = dec2int (str.substr (str.length () - 3));
@@ -316,9 +316,9 @@ String_convert::precision_string (double
   str = str.substr (0, 1) + str.substr (2);
   ssize dot = 1 + exp;
   if (dot <= 0)
-    str = "0." + to_string ('0', -dot) + str;
+    str = "0." + ::to_string ('0', -dot) + str;
   else if (dot >= str.length ())
-    str += to_string ('0', dot - str.length ());
+    str += ::to_string ('0', dot - str.length ());
   else if ((dot > 0) && (dot < str.length ()))
     str = str.substr (0, dot) + "." + str.substr (dot);
   else
