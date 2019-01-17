$NetBSD$

Fix format string handling (Patch from Debian).

--- fltk/main.cxx.orig	2017-12-03 16:13:05.000000000 +0000
+++ fltk/main.cxx
@@ -241,12 +241,12 @@ static int fltk_cmd_handler(pinentry_t p
 				if (pe->one_button)
 				{
 					fl_ok = ok.c_str();
-					fl_message(message);
+					fl_message("%s", message);
 					result = 1; // OK
 				}
 				else if (pe->notok)
 				{
-					switch (fl_choice(message, ok.c_str(), cancel.c_str(), pe->notok))
+					switch (fl_choice("%s", ok.c_str(), cancel.c_str(), pe->notok, message))
 					{
 					case 0: result = 1; break;
 					case 2: result = 0; break;
@@ -256,7 +256,7 @@ static int fltk_cmd_handler(pinentry_t p
 				}
 				else
 				{
-					switch (fl_choice(message, ok.c_str(), cancel.c_str(), NULL))
+					switch (fl_choice("%s", ok.c_str(), cancel.c_str(), NULL, message))
 					{
 					case 0: result = 1; break;
 					default:
