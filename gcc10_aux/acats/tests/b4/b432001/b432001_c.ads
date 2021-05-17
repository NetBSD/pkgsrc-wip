

with B432001_B;
package B432001_C is
   type Der3 is new B432001_B.Der2 with record
      D : Boolean := True;
   end record;
   function New_One return Der3;

   type Der4 is new B432001_B.Der2 with null record;
   function New_One return Der4;

   type Der6 is new B432001_B.Der2 with private;
   function New_One return Der6;
private
   type Der6 is new B432001_B.Der2 with record
      D : Boolean := True;
   end record;
end B432001_C;
