$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/interpreter/bytecode-generator.cc.orig	2024-10-18 12:48:35.364422000 +0000
+++ v8/src/interpreter/bytecode-generator.cc
@@ -2353,6 +2353,9 @@ void BytecodeGenerator::VisitSwitchState
   // Are we still using any if-else bytecodes to evaluate the switch?
   bool use_jumps = n_comp_cases != 0;
 
+  // Does the comparison for non-jump table jumps need an elision scope?
+  bool jump_comparison_needs_hole_check_elision_scope = false;
+
   SwitchBuilder switch_builder(builder(), block_coverage_builder_, stmt,
                                n_comp_cases, jump_table);
   ControlScopeForBreakable scope(this, stmt, &switch_builder);
@@ -2410,6 +2413,10 @@ void BytecodeGenerator::VisitSwitchState
                                          info.covered_cases);
 
     if (use_jumps) {
+      // When using a jump table, the first jump comparison is conditionally
+      // executed if the discriminant wasn't matched by anything in the jump
+      // table, and so needs its own elision scope.
+      jump_comparison_needs_hole_check_elision_scope = true;
       builder()->LoadAccumulatorWithRegister(r1);
     }
   }
@@ -2430,16 +2437,14 @@ void BytecodeGenerator::VisitSwitchState
       // The comparisons linearly dominate, so no need to open a new elision
       // scope for each one.
       base::Optional<HoleCheckElisionScope> elider;
-      bool first_jump_emitted = false;
       for (int i = 0; i < clauses->length(); ++i) {
         CaseClause* clause = clauses->at(i);
         if (clause->is_default()) {
           info.default_case = i;
         } else if (!info.CaseExists(clause->label())) {
-          // The first non-default label is
-          // unconditionally executed, so we only need to emplace it before
-          // visiting the second non-default label.
-          if (first_jump_emitted) elider.emplace(this);
+          if (jump_comparison_needs_hole_check_elision_scope && !elider) {
+            elider.emplace(this);
+          }
 
           // Perform label comparison as if via '===' with tag.
           VisitForAccumulatorValue(clause->label());
@@ -2450,7 +2455,9 @@ void BytecodeGenerator::VisitSwitchState
 #endif
           switch_builder.JumpToCaseIfTrue(ToBooleanMode::kAlreadyBoolean,
                                           case_compare_ctr++);
-          first_jump_emitted = true;
+          // The second and subsequent non-default comparisons are always
+          // conditionally executed, and need an elision scope.
+          jump_comparison_needs_hole_check_elision_scope = true;
         }
       }
     }
