

     --==================================================================--

procedure B810001_4 is

begin

   null;

exception

   when Choice_Param : Constraint_Error => null;

   when Choice_Param : others           => null;                      -- OK.

end B810001_4;
