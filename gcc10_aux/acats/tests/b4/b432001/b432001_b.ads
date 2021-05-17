

with B432001_Root;
package B432001_B is
   type Der2 is new B432001_Root.Base with record
      B : Boolean := True;
   end record;
   function New_One return Der2;
end B432001_B;
