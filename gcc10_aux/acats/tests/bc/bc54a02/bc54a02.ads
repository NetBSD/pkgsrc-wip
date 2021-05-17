

     --===================================================================--


with BC54A02_0;
with BC54A02_1;
package BC54A02 is

--
-- Instantiations:
--

   -- Array types (formal type is static/constrained):

   package Instance01 is new BC54A02_0.Static_Array
     (BC54A02_1.Array_Unconstrained_Same_Type);                       -- ERROR:
             -- Access parameters in profiles do not both have null constraint.

   package Instance02 is new BC54A02_0.Static_Array
     (BC54A02_1.Array_Constrained_Same_Range);                        -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance03 is new BC54A02_0.Static_Array
     (BC54A02_1.Array_Constrained_Diff_Range);                        -- ERROR:
                  -- Index constraints of designated types of access parameters
                  -- have different ranges.

   package Instance04 is new BC54A02_0.Static_Array
     (BC54A02_1.Array_Constrained_Nonstatic_Type);                    -- ERROR:
                -- Designated type in formal is static; in actual is nonstatic.



   -- Array types (formal type is nonstatic/constrained):

   package Instance05 is new BC54A02_0.Nonstatic_Array
     (BC54A02_1.Array_Constrained_Nonstatic_Type);                    -- OK.


   package Instance06 is new BC54A02_0.Nonstatic_Array
     (BC54A02_1.Array_Constrained_Nonstatic_Dupl_Constr);             -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- elaboration/evaluation of a range/constraint.



   -- Tagged types (formal is unconstrained):

   package Instance07 is new BC54A02_0.Unconstrained_Tagged
     (ATS => BC54A02_1.Tagged_Diff_Type);                             -- ERROR:
             -- Access parameters in profiles do not have same designated type.

   package Instance08 is new BC54A02_0.Unconstrained_Tagged
     (ATS => BC54A02_1.Tagged_Nonconstrained_Subtype);                -- OK.



   -- Tagged types (formal is class-wide):

   package Instance09 is new BC54A02_0.Class_Wide
     (ATS => BC54A02_1.Tagged_Class_Actual);                          -- OK.


   package Instance10 is new BC54A02_0.Class_Wide
     (ATS => BC54A02_1.Tagged_Same_Type);                             -- ERROR:
             -- Access parameters in profiles do not have same designated type.



   -- Tagged types (formal is nonstatic):

   package Instance11 is new BC54A02_0.Nonstatic_Tagged
     (ATS => BC54A02_1.Tagged_Nonstatic_Same_Type);                   -- OK.


   package Instance12 is new BC54A02_0.Nonstatic_Tagged
     (ATS => BC54A02_1.Tagged_Nonstatic_Dupl_Constraint);             -- ERROR:
                     -- Constraints of designated types do not result from same
                     -- evaluation/elaboration of a range/constraint.

   package Instance13 is new BC54A02_0.Nonstatic_Tagged
     (ATS => BC54A02_1.Tagged_Nonstatic_No_Constraint);               -- OK.


end BC54A02;
