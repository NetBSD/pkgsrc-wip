
package body C452001_1 is

   function "=" (Arg1, Arg2 : in TC_Planet) return Boolean is
   begin
      return Arg1.Name = Arg2.Name;
   end "=";

end C452001_1;
