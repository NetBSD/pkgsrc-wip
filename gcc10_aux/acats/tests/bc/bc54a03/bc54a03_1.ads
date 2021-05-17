

     --===================================================================--


with BC54A03_0;
generic                                              -- Template for generic
   with package Outer_FP is new BC54A03_0 (<>);      -- formal package (also
   type Formal_Private (<>) is tagged private;       -- declares a generic
package BC54A03_1 is end;                            -- formal package).
