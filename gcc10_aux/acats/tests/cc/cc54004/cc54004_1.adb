

     --===================================================================--

package body CC54004_1 is

   procedure Handle (A : in out Low_Alert) is
   begin
      A.TC_Code := Low;
   end Handle;

   procedure Handle (A : in out Medium_Alert) is
   begin
      A.TC_Code := Medium;
   end Handle;

end CC54004_1;
