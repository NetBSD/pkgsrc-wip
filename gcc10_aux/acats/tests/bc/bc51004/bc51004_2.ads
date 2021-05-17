
-- No body for BC51004_1.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Float_Constrained_Subtype is new BC51004_0.My_Float;   -- Valid ranges
package BC51004_2 is                                           -- are in
   Val : Float_Constrained_Subtype;                            -- 1.0..100.0.
end BC51004_2;
