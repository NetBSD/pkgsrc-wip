
-- No body for BC51003_3.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Record_Constrained_Subtype is new BC51003_0.Square2;   -- Valid
package BC51003_4 is                                           -- discriminant
   State : Record_Constrained_Subtype;                         -- constraint is
end BC51003_4;                                                 -- 2.
