
package body FXAIB00 is

   Id_Generator : Natural := 0;

   function Get_Id return Natural is
      -- Return a different Id with each call.
   begin
      if Id_Generator > Natural'Last - 10 then
          -- Let the generator wrap. We use "mod 7" so the
          -- Ids stay unique as long as possible.
          Id_Generator := Id_Generator mod 7;
      end if;
      Id_Generator := Id_Generator + 7;
      return Id_Generator;
   end Get_Id;

end FXAIB00;
