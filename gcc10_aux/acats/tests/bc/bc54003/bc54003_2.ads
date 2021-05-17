

     --===================================================================--


with BC54003_1;
generic                                            -- Template for generic
   with package Outer_FP is new BC54003_1 (<>);    -- formal package (also
   type Formal_Discrete is (<>);                   -- declares a generic formal
package BC54003_2 is end;                          -- formal package).
