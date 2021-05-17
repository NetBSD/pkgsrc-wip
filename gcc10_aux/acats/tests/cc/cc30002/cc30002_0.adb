

     --==================================================================--


package body CC30002_0 is

   procedure Focus (C: in out Camera) is
   begin
      -- Artificial for testing purposes.
      C.TC_Focus_Called := Body_Of_Ancestor;
   end Focus;

end CC30002_0;
