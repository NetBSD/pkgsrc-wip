

     --==================================================================--

-- Take advantage of some even better algorithms designed for positive
-- floating point values.

with C840001_0;
package C840001_1 is

   subtype Precision_Pos_Float is C840001_0.Precision_Float
     range 0.0 .. 100.0;

-- This is not a new type, so it has no primitives of it own. However, it
-- can declare another version of the operator and call it as long as both it
-- and the corresponding operator of the 1st subtype are not directly visible
-- in the same place.

   function "**" (Left: Precision_Pos_Float; Right: Natural'Base)
     return Precision_Pos_Float;           -- Accepts only positive exponent.

end C840001_1;
