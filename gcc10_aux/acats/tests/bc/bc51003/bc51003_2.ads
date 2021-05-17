
-- No body for BC51003_1.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Float_Constrained_Subtype is new BC51003_0.My_Float;   -- Valid ranges
package BC51003_2 is                                           -- are in
   Val : Float_Constrained_Subtype;                            -- 1.0..100.0.
end BC51003_2;
