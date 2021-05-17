

     --==================================================================--

procedure B810001_1 is

   Choice : Integer := 0;

begin
   null;

exception

   when My_Error : Constraint_Error =>
      declare
         I : Integer := Choice;                                       -- OK.
      begin
         null;
      exception
         when Choice : others =>                                      -- OK.
         declare
            K : Integer := Choice;                                    -- ERROR:
                                         -- Type mismatch: Homograph of Choice.
         begin
            null;
         end;
      end;
    
end B810001_1;
