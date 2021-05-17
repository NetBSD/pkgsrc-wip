
     --==================================================================--

-- Public child subprogram.

-- Context clauses required for visibility needed by separate subunit.

with FA13B00_0;

with BA13B02_0.BA13B02_1;

procedure BA13B02_0.BA13B02_2 is

   function Public_Child_Func return Parent_Integer is separate;

   Child_Integer : Parent_Integer := 24;

begin
   Child_Integer := Child_Integer + 3; 
   -- Real body of procedure goes here.

end BA13B02_0.BA13B02_2;
