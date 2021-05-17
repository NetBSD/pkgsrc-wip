

     --==================================================================--


with BC53001_1;
with BC53001_2;
package BC53001 is

--
-- Check static matching for index subtypes of unconstrained arrays:
--

   package I1 is new BC53001_1.Unconstrained_Formal 
                                          (BC53001_2.Unconstr_Arr1);  -- OK.


   package I2 is new BC53001_1.Unconstrained_Formal 
                                          (BC53001_2.Unconstr_Arr2);  -- OK.

   package I_SEG is new BC53001_1.Constrained_SEG_Formal
                                          (BC53001_1.Index_NonStatic);

   package II2 is new BC53001_1.Unconstrained_Formal 
                                          (I_SEG.Unconstr_Arr);       -- OK.

   package I3 is new BC53001_1.Unconstrained_Formal 
                                          (BC53001_2.Unconstr_Arr3);  -- ERROR:
                       -- Constraints of index subtypes do not result from same
                       -- evaluation/elaboration of a range/constraint.


--
-- Check static matching for index ranges of constrained arrays:
--

   package I4 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr1);      -- OK.


   package I5 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr2);      -- OK.


   package I6 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr3);      -- ERROR:
                                       -- Index subtypes have different bounds.


--
-- Check static matching for component subtypes:
--

   package I7 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr4);      -- ERROR:
        -- Component subtype in actual has null constraint; in formal does not.

   package I8 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr5);      -- ERROR:
                                              -- Component types are different.

   package I9 is new BC53001_1.Constrained_Formal 
                                        (BC53001_2.Constr_Arr6);      -- OK.


end BC53001;
