
-- No body for BC51003_2.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Array_Constrained_Subtype is new BC51003_0.Matrix_2x2; -- Valid index
package BC51003_3 is                                           -- constraints
   Det : Array_Constrained_Subtype;                            -- are 1..2.
end BC51003_3;
