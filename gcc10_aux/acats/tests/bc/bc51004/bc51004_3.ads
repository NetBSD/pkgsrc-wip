
-- No body for BC51004_2.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Array_Constrained_Subtype is new BC51004_0.Matrix_2x2; -- Valid index
package BC51004_3 is                                           -- constraints
   Det : Array_Constrained_Subtype;                            -- are 1..2.
end BC51004_3;
