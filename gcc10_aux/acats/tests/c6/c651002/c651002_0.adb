

package body C651002_0 is -- OS_Interface

   procedure Do_Something (Oper : in Natural; Result : out Error_Code) is
   begin
      -- Our "system call"; for our purposes, it just returns
      -- a different error code for each Oper(ation) value.
      Result := Oper;
   end Do_Something;


   procedure Raise_Error (Error : in Error_Code) is
   begin
      if Error = 1 then
         raise Not_Found_Error;
      elsif Error = 2 then
         raise Invalid_Error;
      elsif Error >= 3 then
         raise OS_Error with " code" & "-"(Error)'Image;
      end if;
      -- We fall out if Error = SUCCESS.
   end Raise_Error;


   procedure Generic_Raise_Error (Error : in Error_Code) is
   begin
      if Error = 1 then
         raise Not_Found_Error with Message (Error);
      elsif Error = 2 then
         raise Invalid_Error with Message (Error);
      elsif Error >= 3 then
         raise OS_Error with Message (Error);
      end if;
      -- We fall out if Error = SUCCESS.
   end Generic_Raise_Error;

end C651002_0;
