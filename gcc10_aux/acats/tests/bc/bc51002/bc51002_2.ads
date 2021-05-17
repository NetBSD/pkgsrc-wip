

     --==================================================================--


with BC51002_0;  -- Type definitions.
generic          -- Record formal types.

   type Array_Constrained_Subtype is new BC51002_0.Mat2x2;

package BC51002_2 is
   type New_Array is new Array_Constrained_Subtype;  -- This declaration could
                                                     -- be satisfied by an
                                                     -- indefinite actual.
end BC51002_2;
