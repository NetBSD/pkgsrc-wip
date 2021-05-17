

-- No body for BC51002_2;


     --==================================================================--


with BC51002_0;  -- Type definitions.
generic          -- Record formal types.

   type Record_Constrained_Subtype  is new BC51002_0.Square3;

package BC51002_3 is
   procedure Proc (P: Record_Constrained_Subtype);   -- This declaration could
                                                     -- be satisfied by an
                                                     -- indefinite actual.
end BC51002_3;
