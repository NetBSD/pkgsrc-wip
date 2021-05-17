

with B431004_Root;
package B431004_B is
   type Short_Int is range 0 .. 99;
   type Der2 is new B431004_Root.Base with record
      B : Short_Int := 0;
   end record;
end B431004_B;
