
-- No body for BC51004_0.


     --==================================================================--


with BC51004_0;  -- Type definitions.
generic
   type Integer_Constrained_Subtype is new Natural;            -- Valid ranges
package BC51004_1 is                                           -- are in
   Rows : Integer_Constrained_Subtype;                         -- 0..
end BC51004_1;                                                 -- Integer'Last.
