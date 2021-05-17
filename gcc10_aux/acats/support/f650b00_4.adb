
with TCTouch;
package body F650B00_4 is
   procedure Swap( A,B: in out Mill ) is
     T: constant Mill := A;
   begin
     TCTouch.Touch('k');
     A := B;
     B := T;
   end Swap;

   function  Create return Mill is
     A_Mill : Mill;
   begin
     TCTouch.Touch('l');
     return A_Mill;
   end Create;

   procedure Stop( It: in out Mill ) is
   begin
     TCTouch.Touch('m');
     F650B00_3.Stop( It.Pump );
     F650B00_2.Stop( F650B00_2.Windmill( It ) );
   end Stop;
end F650B00_4;
