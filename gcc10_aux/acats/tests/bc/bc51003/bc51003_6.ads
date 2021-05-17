
-- No body for BC51003_5.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Tagged_Constrained_Subtype is new BC51003_0.Dbl_Sq4    -- Valid
     with private;                                             -- discriminant
package BC51003_6 is                                           -- constraint is
   State_Pair : Tagged_Constrained_Subtype;                    -- 4.
end BC51003_6;
