$NetBSD: patch-v8_src_x64_code-stubs-x64.cc,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- v8/src/x64/code-stubs-x64.cc.orig	2011-04-13 08:24:39.000000000 +0000
+++ v8/src/x64/code-stubs-x64.cc
@@ -1699,11 +1699,14 @@ void ArgumentsAccessStub::GenerateReadEl
   Label slow;
   __ JumpIfNotSmi(rdx, &slow);
 
-  // Check if the calling frame is an arguments adaptor frame.
+  // Check if the calling frame is an arguments adaptor frame.  We look at the
+  // context offset, and if the frame is not a regular one, then we find a
+  // Smi instead of the context.  We can't use SmiCompare here, because that
+  // only works for comparing two smis.
   Label adaptor;
   __ movq(rbx, Operand(rbp, StandardFrameConstants::kCallerFPOffset));
-  __ SmiCompare(Operand(rbx, StandardFrameConstants::kContextOffset),
-                Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
+  __ Cmp(Operand(rbx, StandardFrameConstants::kContextOffset),
+         Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
   __ j(equal, &adaptor);
 
   // Check index against formal parameters count limit passed in
@@ -1758,8 +1761,8 @@ void ArgumentsAccessStub::GenerateNewObj
   // Check if the calling frame is an arguments adaptor frame.
   Label adaptor_frame, try_allocate, runtime;
   __ movq(rdx, Operand(rbp, StandardFrameConstants::kCallerFPOffset));
-  __ SmiCompare(Operand(rdx, StandardFrameConstants::kContextOffset),
-                Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
+  __ Cmp(Operand(rdx, StandardFrameConstants::kContextOffset),
+         Smi::FromInt(StackFrame::ARGUMENTS_ADAPTOR));
   __ j(equal, &adaptor_frame);
 
   // Get the length from the frame.
@@ -3518,8 +3521,8 @@ void StringAddStub::Generate(MacroAssemb
   // Look at the length of the result of adding the two strings.
   STATIC_ASSERT(String::kMaxLength <= Smi::kMaxValue / 2);
   __ SmiAdd(rbx, rbx, rcx);
-  // Use the runtime system when adding two one character strings, as it
-  // contains optimizations for this specific case using the symbol table.
+  // Use the symbol table when adding two one character strings, as it
+  // helps later optimizations to return a symbol here.
   __ SmiCompare(rbx, Smi::FromInt(2));
   __ j(not_equal, &longer_than_two);
 
@@ -3823,15 +3826,14 @@ void StringHelper::GenerateTwoCharacterS
                     FieldOperand(symbol_table, SymbolTable::kCapacityOffset));
   __ decl(mask);
 
-  Register undefined = scratch4;
-  __ LoadRoot(undefined, Heap::kUndefinedValueRootIndex);
+  Register map = scratch4;
 
   // Registers
   // chars:        two character string, char 1 in byte 0 and char 2 in byte 1.
   // hash:         hash of two character string (32-bit int)
   // symbol_table: symbol table
   // mask:         capacity mask (32-bit int)
-  // undefined:    undefined value
+  // map:          -
   // scratch:      -
 
   // Perform a number of probes in the symbol table.
@@ -3846,7 +3848,7 @@ void StringHelper::GenerateTwoCharacterS
     }
     __ andl(scratch, mask);
 
-    // Load the entry from the symble table.
+    // Load the entry from the symbol table.
     Register candidate = scratch;  // Scratch register contains candidate.
     STATIC_ASSERT(SymbolTable::kEntrySize == 1);
     __ movq(candidate,
@@ -3856,8 +3858,16 @@ void StringHelper::GenerateTwoCharacterS
                          SymbolTable::kElementsStartOffset));
 
     // If entry is undefined no string with this hash can be found.
-    __ cmpq(candidate, undefined);
+    NearLabel is_string;
+    __ CmpObjectType(candidate, ODDBALL_TYPE, map);
+    __ j(not_equal, &is_string);
+
+    __ CompareRoot(candidate, Heap::kUndefinedValueRootIndex);
     __ j(equal, not_found);
+    // Must be null (deleted entry).
+    __ jmp(&next_probe[i]);
+
+    __ bind(&is_string);
 
     // If length is not 2 the string is not a candidate.
     __ SmiCompare(FieldOperand(candidate, String::kLengthOffset),
@@ -3869,8 +3879,7 @@ void StringHelper::GenerateTwoCharacterS
     Register temp = kScratchRegister;
 
     // Check that the candidate is a non-external ascii string.
-    __ movq(temp, FieldOperand(candidate, HeapObject::kMapOffset));
-    __ movzxbl(temp, FieldOperand(temp, Map::kInstanceTypeOffset));
+    __ movzxbl(temp, FieldOperand(map, Map::kInstanceTypeOffset));
     __ JumpIfInstanceTypeIsNotSequentialAscii(
         temp, temp, &next_probe[i]);
 
