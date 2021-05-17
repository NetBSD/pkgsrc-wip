 
with Report;
package body F393A00_0 is
   Expectation : String(1..20);
   Finger      : Natural := 0;
 
   procedure TC_Touch ( A_Tag : Character ) is
   begin
     Finger := Finger+1;
     Expectation(Finger) := A_Tag;
   end TC_Touch;
 
   procedure TC_Validate( Expected: String; Message: String ) is
   begin
     if Expectation(1..Finger) /= Expected then
       Report.Failed( Message & " Expecting: " & Expected 
 			     & " Got: " & Expectation(1..Finger) );
     end if;
     Finger := 0;
   end TC_Validate;
end F393A00_0;
