$NetBSD$

--- unittests/ASTMatchers/Dynamic/RegistryTest.cpp.orig	2016-12-17 00:12:44.000000000 +0000
+++ unittests/ASTMatchers/Dynamic/RegistryTest.cpp
@@ -60,7 +60,7 @@ public:
     VariantMatcher Out;
     if (Ctor)
       Out = Registry::constructMatcher(*Ctor, SourceRange(), Args(Arg1), Error);
-    EXPECT_EQ("", DummyError.toStringFull()) << MatcherName;
+    EXPECT_EQ("", DummyError.toStringFull()) << MatcherName.str();
     return Out;
   }
 
