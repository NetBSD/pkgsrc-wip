
with B730006_1;
package B730006_0.Child3 is
   type Hammer is new B730006_1.Tool with record
      D : Float;
   end record;
   procedure Pound (Claw : in out Hammer);
end B730006_0.Child3;

