 
with F393A00_0;
package body F393A00_4 is
   procedure Swap( A,B: in out Mill ) is
     T: constant Mill := A;
   begin
     F393A00_0.TC_Touch('k');
     A := B;
     B := T;
   end Swap;
 
   function  Create return Mill is
     A_Mill : Mill;
   begin
     F393A00_0.TC_Touch('l');
     return A_Mill;
   end Create;
 
   procedure Stop( It: in out Mill ) is
   begin
     F393A00_0.TC_Touch('m');
     F393A00_3.Stop( It.Pump ); 
     F393A00_2.Stop( F393A00_2.Windmill( It ) ); 
   end Stop;
end F393A00_4;
