

     --===================================================================--


with FC54A00;
with BC54A03_2;
with BC54A03_3;
with BC54A03_4;
package BC54A03 is

--
-- Instantiations:
--

   -- Formal derived types:

   package Instance01 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag, BC54A03_4.Tagged_Same_Type);                       -- OK.


   package Instance02 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag, BC54A03_4.Tagged_Diff_Type);                       -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance03 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag, BC54A03_4.Tagged_Class_Actual);                    -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance04 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag, BC54A03_4.Tagged_Nonconstrained_Subtype);          -- OK.


   package Instance05 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag'Class, BC54A03_4.Tagged_Class_Actual);              -- OK.


   package Instance06 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag'Class, BC54A03_4.Tagged_Same_Type);                 -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance07 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag20, BC54A03_4.Tagged_Same_Type);                     -- ERROR:
             -- Access parameters in profiles do not both have null constraint.

   package Instance08 is new BC54A03_2.Formal_Derived_Parameter
     (FC54A00.Tag20, BC54A03_4.Tagged_Diff_Constraint);               -- ERROR:
                        -- Designated types of access parameters have different
                        -- discriminant constraints.



   -- Formal tagged private types
   -- (one level of indirection through formal package):

   package Instance10 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Indef, BC54A03_4.Tagged_Diff_Type);               -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance11 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Indef, BC54A03_4.Tagged_Class_Actual);            -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance12 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Indef, BC54A03_4.Tagged_Nonconstrained_Subtype);  -- OK.


   package Instance13 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Class, BC54A03_4.Tagged_Same_Type);               -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance14 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Def, BC54A03_4.Tagged_Same_Type);                 -- ERROR:
             -- Access parameters in profiles do not both have null constraint.

   package Instance15 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Nonst,
      BC54A03_4.Tagged_Same_Constraint);                              -- ERROR:
                -- Designated type in formal is nonstatic; in actual is static.

   package Instance16 is new BC54A03_2.Formal_Tagged_Private_Parameter
     (BC54A03_3.Tag_Nonst,
      BC54A03_4.Tagged_Nonstatic_Equiv_Constraint);                   -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- evaluation/elaboration of a range/constraint.



   -- Formal discrete types
   -- (two levels of indirection through formal packages):

   package Instance17 is new BC54A03_2.Formal_Discrete_Parameter
     (BC54A03_3.Dis_Static,
      BC54A03_4.Discrete_Diff_Range);                                 -- ERROR:
                -- Designated types of access parameters have different bounds.

   package Instance18 is new BC54A03_2.Formal_Discrete_Parameter
     (BC54A03_3.Dis_Static,
      BC54A03_4.Discrete_Same_Range);                                 -- OK.


   package Instance19 is new BC54A03_2.Formal_Discrete_Parameter
     (BC54A03_3.Dis_Nonstatic,
      BC54A03_4.Discrete_Same_Type);                                  -- ERROR:
                -- Designated type in formal is nonstatic; in actual is static.

end BC54A03;
