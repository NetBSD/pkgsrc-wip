
     --==================================================================--

-- Declare instances of the generic complex packages for real type.  
-- The instance of the child must itself be declared as a child of the 
-- instance of the parent.

with CA11013_0;                       -- Complex number.
with CA11013_2;                       -- Random number generator.
pragma Elaborate (CA11013_0);
package CA11013_3 is new 
  CA11013_0 (Random_Generator => CA11013_2.Random_Complex,
             Real_Type        => CA11013_2.My_Float);
