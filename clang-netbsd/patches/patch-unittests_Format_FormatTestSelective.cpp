$NetBSD$

--- unittests/Format/FormatTestSelective.cpp.orig	2017-05-29 10:06:52.000000000 +0000
+++ unittests/Format/FormatTestSelective.cpp
@@ -27,7 +27,7 @@ protected:
     FormattingAttemptStatus Status;
     tooling::Replacements Replaces =
         reformat(Style, Code, Ranges, "<stdin>", &Status);
-    EXPECT_TRUE(Status.FormatComplete) << Code << "\n\n";
+    EXPECT_TRUE(Status.FormatComplete) << Code.str() << "\n\n";
     auto Result = applyAllReplacements(Code, Replaces);
     EXPECT_TRUE(static_cast<bool>(Result));
     DEBUG(llvm::errs() << "\n" << *Result << "\n\n");
