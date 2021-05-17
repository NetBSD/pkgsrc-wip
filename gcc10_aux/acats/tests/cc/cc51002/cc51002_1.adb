

     --==================================================================--


function CC51002_1 (M : in Msg_Block) return Boolean is
   Okay : Boolean := False;
begin

   -- The call to Send below uses the ancestor type's parameter name, which
   -- should be legal even if the actual subprogram called does not have a
   -- parameter of that name. Furthermore, it uses the ancestor type's default
   -- expression for the second parameter, which should be legal even if the
   -- the actual subprogram called has no such default expression.

   Okay := Send (Msg => M);
   -- ...Other processing.
   return Okay;

end CC51002_1;
