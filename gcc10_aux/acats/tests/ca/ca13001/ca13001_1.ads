
-- No bodies required for CA13001_0.

     --==================================================================--

-- Public parent.

package CA13001_1 is                     

   type Transportation is (Bicycle, Clunker, New_Car);
   type Key_Type is private;
   Walking : boolean := false;

   -- Other type definitions and procedure declarations in real application.

private
   type Key_Type 
     is range Transportation'pos(Bicycle) .. Transportation'pos(New_Car);

end CA13001_1;
