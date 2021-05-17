
-- No body for BC51004_4.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Access_Constrained_Subtype is new BC51004_0.Sq2_Ptr;   -- Valid
package BC51004_5 is                                           -- discriminant
   State_Ptr : Access_Constrained_Subtype;                     -- constraint is
end BC51004_5;                                                 -- 2.
