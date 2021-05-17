

     --==================================================================--

with Ada.Exceptions;

procedure B810001_5 is

begin

   declare
   begin
      null;

   exception
      when Choice_Param : Constraint_Error => null;
      when others                      =>
         if Ada.Exceptions.Exception_Name (Choice_Param)              -- ERROR:
            /= "Constraint_Error" then null;    -- Choice_Param is not visible.
         end if;

   end;

end B810001_5;
