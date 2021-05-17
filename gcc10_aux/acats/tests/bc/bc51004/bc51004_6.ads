
-- No body for BC51004_5.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Tagged_Constrained_Subtype is new BC51004_0.Dbl_Sq4    -- Valid
     with private;                                             -- discriminant
package BC51004_6 is                                           -- constraint is
   State_Pair : Tagged_Constrained_Subtype;                    -- 4.
end BC51004_6;
