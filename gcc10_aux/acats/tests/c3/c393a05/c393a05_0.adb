 
 with F393A00_0;
 package body C393A05_0 is
   procedure Set_Grind( It: in out Grinder; The_Grind: Coarseness ) is
   begin
     F393A00_0.TC_Touch( 'A' );
     It.Grind := The_Grind;
   end Set_Grind;
 
   function  Grind( It: Grinder ) return Coarseness is
   begin
     F393A00_0.TC_Touch( 'B' );
     return It.Grind;
   end Grind;
 
   procedure Swap( A,B: in out Grinder ) is
     T : constant Grinder := A;
   begin
     F393A00_0.TC_Touch( 'C' );
     A := B;
     B := T;
   end Swap;
 
   function  Create return Grinder is
     One: Grinder;  
   begin
     F393A00_0.TC_Touch( 'D' );
     F393A00_4.Initialize( F393A00_4.Mill( One ) );
     One.Grind := Fine;
     return One;
   end Create;
 end C393A05_0;
