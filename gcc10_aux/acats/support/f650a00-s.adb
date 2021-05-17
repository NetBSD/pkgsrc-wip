
--=======================================================================--

package body F650A00.S is

   procedure Handle (SA : in out Special_Alert) is
   begin
      F650A00.P.Practice_Alert(SA).Handle;
      SA.Display := Big_Screen;
   end Handle;


   function Make_Alert_for_Time (Time : in Duration) return Special_Alert is
   begin
       return Result : Special_Alert(Age => 39) do
           Set_Alert_Time (Result, Time);
       end return;
   end Make_Alert_for_Time;

end F650A00.S;

