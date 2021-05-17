
-- No body for BC51004_3.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Record_Constrained_Subtype is new BC51004_0.Square2;   -- Valid
package BC51004_4 is                                           -- discriminant
   State : Record_Constrained_Subtype;                         -- constraint is
end BC51004_4;                                                 -- 2.
