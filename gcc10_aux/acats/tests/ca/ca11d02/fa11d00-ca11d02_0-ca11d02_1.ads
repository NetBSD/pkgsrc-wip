
--=======================================================================--

-- Child package of FA11D00.CA11D02_0.
-- Grandchild package of FA11D00.

package FA11D00.CA11D02_0.CA11D02_1 is     -- Array_Complex

   Inverse_Error : exception renames Divide_Error;   -- Reference to exception 
                                                     -- in grandparent package.
   Array_Size    : constant := 2;

   type Complex_Array_Type is                        
      array (1 .. Array_Size) of Complex_Type;       -- Reference to type
                                                     -- in parent package.

   function Multiply (Left  : Complex_Array_Type;    -- Multiply two complex
                      Right : Complex_Array_Type)    -- arrays.
     return Complex_Array_Type;

   function Add (Left, Right : Complex_Array_Type)   -- Add two complex
     return Complex_Array_Type;                      -- arrays.

   procedure Inverse (Right : in     Complex_Array_Type;  -- Invert a complex
                      Left  : in out Complex_Array_Type); -- array.
 
end FA11D00.CA11D02_0.CA11D02_1;     -- Array_Complex
