
     --==================================================================--

-- More operations on Bag.

generic

-- Parameters go here.

package CA11020_0.CA11020_1 is        

   -- ... Other declarations.

   generic                            -- Generic iterator procedure.
      with procedure Use_Element (E : in Element);

   procedure Iterate (B : in Bag);    -- Called once per element in the bag.

   -- ... Various other operations.

end CA11020_0.CA11020_1;
