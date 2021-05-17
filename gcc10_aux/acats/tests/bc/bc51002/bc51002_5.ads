

     --==================================================================--


with BC51002_0;  -- Type definitions.
generic          -- Tagged types.

   type Undiscriminated_Tagged is new BC51002_0.Vector_Pair with private;

package BC51002_5 is
   procedure Proc (P: Undiscriminated_Tagged);        -- This declaration could
                                                      -- be satisfied by an
                                                      -- indefinite actual.
end BC51002_5;
