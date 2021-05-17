
-- No body for CA11012_2;

     --==================================================================--

-- Declare instances of the generic complex packages for integer type.  
-- The instance of the child must itself be declared as a child of the 
-- instance of the parent.

with CA11012_0;                        -- Complex number abstraction
with CA11012_2;                        -- Package containing integer type
pragma Elaborate (CA11012_0);
package CA11012_3 is new CA11012_0 (Int_Type => CA11012_2.My_Integer);
