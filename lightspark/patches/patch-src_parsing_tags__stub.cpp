$NetBSD: patch-src_parsing_tags__stub.cpp,v 1.1 2014/03/03 08:12:25 nsloss Exp $

Comment out function declaration as this will beak when built with clang - out of line definition.

--- src/parsing/tags_stub.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/parsing/tags_stub.cpp
@@ -25,7 +25,7 @@
 using namespace std;
 using namespace lightspark;
 
-void lightspark::ignore(istream& i, int count);
+//void lightspark::ignore(istream& i, int count);
 
 ProtectTag::ProtectTag(RECORDHEADER h, istream& in):ControlTag(h)
 {
