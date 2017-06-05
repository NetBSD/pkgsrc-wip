$NetBSD$

--- unittests/Format/FormatTestComments.cpp.orig	2017-05-29 10:06:52.000000000 +0000
+++ unittests/Format/FormatTestComments.cpp
@@ -47,7 +47,7 @@ protected:
     if (CheckComplete != SC_DoNotCheck) {
       bool ExpectedCompleteFormat = CheckComplete == SC_ExpectComplete;
       EXPECT_EQ(ExpectedCompleteFormat, Status.FormatComplete)
-          << Code << "\n\n";
+          << Code.str() << "\n\n";
     }
     ReplacementCount = Replaces.size();
     auto Result = applyAllReplacements(Code, Replaces);
