$NetBSD: patch-v8_src_x64_full-codegen-x64.cc,v 1.1.1.1 2011/05/03 19:53:18 genolopolis Exp $

--- deps/v8/src/x64/full-codegen-x64.cc.orig	2011-04-13 08:24:39.000000000 +0000
+++ deps/v8/src/x64/full-codegen-x64.cc
@@ -865,7 +865,7 @@ void FullCodeGenerator::VisitForInStatem
   __ push(rcx);  // Enumerable.
   __ push(rbx);  // Current entry.
   __ InvokeBuiltin(Builtins::FILTER_KEY, CALL_FUNCTION);
-  __ SmiCompare(rax, Smi::FromInt(0));
+  __ Cmp(rax, Smi::FromInt(0));
   __ j(equal, loop_statement.continue_target());
   __ movq(rbx, rax);
 
@@ -2300,15 +2300,15 @@ void FullCodeGenerator::EmitIsConstructC
 
   // Skip the arguments adaptor frame if it exists.
   Label check_frame_marker;
-  __ SmiCompare(Operand(rax, StandardFrameConstants::kContextOffset),
-                Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
+  __ Cmp(Operand(rax, StandardFrameConstants::kContextOffset),
+         Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
   __ j(not_equal, &check_frame_marker);
   __ movq(rax, Operand(rax, StandardFrameConstants::kCallerFPOffset));
 
   // Check the marker in the calling frame.
   __ bind(&check_frame_marker);
-  __ SmiCompare(Operand(rax, StandardFrameConstants::kMarkerOffset),
-                Smi::FromInt(StackFrame::CONSTRUCT));
+  __ Cmp(Operand(rax, StandardFrameConstants::kMarkerOffset),
+         Smi::FromInt(StackFrame::CONSTRUCT));
   PrepareForBailoutBeforeSplit(TOS_REG, true, if_true, if_false);
   Split(equal, if_true, if_false, fall_through);
 
@@ -2362,8 +2362,8 @@ void FullCodeGenerator::EmitArgumentsLen
 
   // Check if the calling frame is an arguments adaptor frame.
   __ movq(rbx, Operand(rbp, StandardFrameConstants::kCallerFPOffset));
-  __ SmiCompare(Operand(rbx, StandardFrameConstants::kContextOffset),
-                Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
+  __ Cmp(Operand(rbx, StandardFrameConstants::kContextOffset),
+         Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
   __ j(not_equal, &exit);
 
   // Arguments adaptor case: Read the arguments length from the
