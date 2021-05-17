 
with F393A00_0;
package body F393A00_1 is
   procedure Initialize( An_Object: in out Object ) is
   begin
     An_Object.Initialized := True;
     F393A00_0.TC_Touch('a');
   end Initialize;
 
   function  Initialized( An_Object: Object'Class ) return Boolean is
   begin
     F393A00_0.TC_Touch('b');
     return An_Object.Initialized;
   end Initialized;
end F393A00_1;
