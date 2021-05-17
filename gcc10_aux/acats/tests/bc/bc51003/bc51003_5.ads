
-- No body for BC51003_4.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Access_Constrained_Subtype is new BC51003_0.Sq2_Ptr;   -- Valid
package BC51003_5 is                                           -- discriminant
   State_Ptr : Access_Constrained_Subtype;                     -- constraint is
end BC51003_5;                                                 -- 2.
