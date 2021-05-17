

     --===================================================================--


with BC54A06_0;
with BC54A06_1;
package BC54A06 is

--
-- Instantiations:
--

   -- Tagged designated type:

   package Instance01 is new BC54A06_0.Pool_Access_To_Var_Tagged
     (BC54A06_1.Acc_Tag);                                             -- OK.


   package Instance02 is new BC54A06_0.Pool_Access_To_Var_Tagged
     (BC54A06_1.Acc_Same_Tag);                                        -- OK.


   package Instance03 is new BC54A06_0.Pool_Access_To_Var_Tag_Static
     (BC54A06_1.Acc_Tag);                                             -- ERROR:
                       -- Designated subtypes do not both have null constraint.

   package Instance04 is new BC54A06_0.Pool_Access_To_Var_Tag_Static
     (BC54A06_1.Acc_Tag20);                                           -- OK.


   package Instance05 is new BC54A06_0.Pool_Access_To_Var_Tag_Static
     (BC54A06_1.Acc_Tag25);                                           -- ERROR:
                -- Designated subtypes have different discriminant constraints.

   package Instance06 is new BC54A06_0.Pool_Access_To_Var_Tag_Nonstat
     (BC54A06_1.Acc_Tag_Nonstat);                                     -- OK.


   package Instance07 is new BC54A06_0.Pool_Access_To_Var_Tag_Nonstat
     (BC54A06_1.Acc_Tag_Du_Nonstat);                                  -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- evaluation/elaboration of a range/constraint.

   package Instance08 is new BC54A06_0.Pool_Access_To_Var_Tag_Nonstat
     (BC54A06_1.Acc_Tag_Va_Nonstat);                                  -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- evaluation/elaboration of a range/constraint.



   -- Formal discrete designated type:
   -- Two levels of indirection through formal packages:

   package Instance09 is new BC54A06_0.Pool_Access_To_Var_Form_Disc
     (BC54A06_0.In_Desig_Num, BC54A06_1.Acc_Num);                     -- OK.


   package Instance10 is new BC54A06_0.Pool_Access_To_Var_Form_Disc
     (BC54A06_0.In_Desig_Num, BC54A06_1.Acc_New_Num);                 -- ERROR:
                                             -- Designated types are different.

   package Instance11 is new BC54A06_0.Pool_Access_To_Var_Form_Disc
     (BC54A06_0.In_Desig_Num, BC54A06_1.Acc_Pos);                     -- ERROR:
                                     -- Designated types have different bounds.

   package Instance12 is new BC54A06_0.Pool_Access_To_Var_Form_Disc
     (BC54A06_0.In_Desig_Num, BC54A06_1.Acc_Num_Nonstat);             -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.


end BC54A06;
