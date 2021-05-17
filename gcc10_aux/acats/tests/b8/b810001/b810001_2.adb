

     --==================================================================--

procedure B810001_2 is

   My_Error : exception;

begin
   null;

exception

   when My_Error : Constraint_Error =>
      declare
         Exc : exception renames My_Error;                            -- ERROR:
                                       -- Type mismatch: Homograph of My_Error.
      begin
         null;
      end;
 
end B810001_2;
