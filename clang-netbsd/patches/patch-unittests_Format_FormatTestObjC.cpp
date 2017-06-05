$NetBSD$

--- unittests/Format/FormatTestObjC.cpp.orig	2017-05-29 10:06:52.000000000 +0000
+++ unittests/Format/FormatTestObjC.cpp
@@ -49,7 +49,7 @@ protected:
     if (CheckComplete != SC_DoNotCheck) {
       bool ExpectedCompleteFormat = CheckComplete == SC_ExpectComplete;
       EXPECT_EQ(ExpectedCompleteFormat, Status.FormatComplete)
-          << Code << "\n\n";
+          << Code.str() << "\n\n";
     }
     auto Result = applyAllReplacements(Code, Replaces);
     EXPECT_TRUE(static_cast<bool>(Result));
