$NetBSD$

Avoid ambiguous function call.

--- src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp.orig	2026-08-21 10:04:43.213547864 +0000
+++ src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp
@@ -929,7 +929,7 @@ static void DumpAnnotatedInput(raw_ostream &OS, const 
   unsigned LineCount = InputFileText.count('\n');
   if (InputFileEnd[-1] != '\n')
     ++LineCount;
-  unsigned LineNoWidth = NumDigitsBase10(LineCount);
+  unsigned LineNoWidth = NumDigitsBase10((float)LineCount);
   // +3 below adds spaces (1) to the left of the (right-aligned) line numbers
   // on input lines and (2) to the right of the (left-aligned) labels on
   // annotation lines so that input lines and annotation lines are more
