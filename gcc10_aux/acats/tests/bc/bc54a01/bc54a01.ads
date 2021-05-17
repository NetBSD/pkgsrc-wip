

     --===================================================================--


with BC54A01_0;
with BC54A01_1;
package BC54A01 is

--
-- Instantiations:
--

   -- Discrete types (formal is static):

   package Instance01 is new BC54A01_0.Static_Discrete
     (ATS => BC54A01_1.Discrete_Diff_Range);                          -- ERROR:
                -- Designated types of access parameters have different bounds.

   package Instance02 is new BC54A01_0.Static_Discrete
     (ATS => BC54A01_1.Discrete_Same_Range);                          -- OK.


   package Instance03 is new BC54A01_0.Static_Discrete
     (BC54A01_1.Discrete_Nonstatic_Same_Range);                       -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.



   -- Discrete types (formal is nonstatic):

   package Instance04 is new BC54A01_0.Nonstatic_Discrete
     (ATS => BC54A01_1.Discrete_Diff_Range);                          -- ERROR:
                -- Designated type in formal is nonstatic; in actual is static.

   package Instance05 is new BC54A01_0.Nonstatic_Discrete
     (ATS => BC54A01_1.Discrete_Nonstatic_Dupl_Constr);               -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- elaboration/evaluation of constraint/range.

   package Instance06 is new BC54A01_0.Nonstatic_Discrete
     (BC54A01_1.Discrete_Nonstatic_Range_Attr);                       -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- elaboration/evaluation of constraint/range.



   -- Floating point types (formal is unconstrained):

   package Instance07 is new BC54A01_0.Unconstrained_Float
     (BC54A01_1.Float_Diff_Type);                                     -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance08 is new BC54A01_0.Unconstrained_Float
     (BC54A01_1.Float_Diff_Range);                                    -- ERROR:
                -- Designated types of access parameters have different bounds.

   package Instance09 is new BC54A01_0.Unconstrained_Float
     (BC54A01_1.Float_Nonconstrained_Subtype);                        -- OK.



   -- Floating point types (formal is constrained):

   package Instance10 is new BC54A01_0.Constrained_Float
     (BC54A01_1.Float_Diff_Range);                                    -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance11 is new BC54A01_0.Constrained_Float
     (BC54A01_1.Float_Has_Same_Range);                                -- OK.



   -- Access types (designating tagged) (formal type is unconstrained):

   package Instance12 is new BC54A01_0.Unconstrained_Tagged_Access
     (BC54A01_1.Acc_Tag_Unconstrained_Same_Type);                     -- OK.


   package Instance13 is new BC54A01_0.Unconstrained_Tagged_Access
     (BC54A01_1.Acc_Tag_Unconstrained_Class_Type);                    -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance14 is new BC54A01_0.Unconstrained_Tagged_Access
     (BC54A01_1.Acc_Tag_Constrained_A_Type);                          -- ERROR:
             -- Access parameters in profiles do not both have null constraint.


end BC54A01;
