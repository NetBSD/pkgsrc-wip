
-- No body for BC51003_0.


     --==================================================================--


with BC51003_0;  -- Type definitions.
generic
   type Integer_Constrained_Subtype is new Natural;            -- Valid ranges
package BC51003_1 is                                           -- are in 0 ..
   Rows : Integer_Constrained_Subtype;                         -- Integer'Last.
end BC51003_1;
