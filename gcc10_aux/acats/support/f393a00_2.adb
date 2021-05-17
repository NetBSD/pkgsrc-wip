 
with F393A00_0;
package body F393A00_2 is
 
   procedure Swap( A,B: in out Windmill ) is
     T : constant Windmill := B;
   begin
     F393A00_0.TC_Touch('c');
     B := A;
     A := T;
   end Swap;
 
   function  Create return Windmill is
     A_Mill : Windmill;
   begin
     F393A00_0.TC_Touch('d');
     return A_Mill;
   end Create;
 
   procedure Add_Spin( To_Mill : in out Windmill;
 		      RPMs    : in     Rotational_Measurement ) is
   begin
     F393A00_0.TC_Touch('e');
     To_Mill.Spin := To_Mill.Spin + RPMs;
   end Add_Spin;
 
   procedure Stop( Mill : in out Windmill ) is
   begin
     F393A00_0.TC_Touch('f');
     Mill.Spin := 0;
   end Stop;
 
   function  Spin( Mill : Windmill ) return Rotational_Measurement is
   begin
     F393A00_0.TC_Touch('g');
     return Mill.Spin;
   end Spin;
 
end F393A00_2;
