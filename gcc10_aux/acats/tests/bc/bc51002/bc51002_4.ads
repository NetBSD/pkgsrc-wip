

     --==================================================================--


with BC51002_0;  -- Type definitions.
generic          -- Record formal types.

   type Record_Default_Discriminant is new BC51002_0.Square;

package BC51002_4 is
   type New_Record is new Record_Default_Discriminant; -- This decl. could
                                                       -- be satisfied by an
                                                       -- indefinite actual.
end BC51002_4;
