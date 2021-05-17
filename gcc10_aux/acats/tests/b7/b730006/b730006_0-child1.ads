
-- Legal parts of Subtest 1:

package B730006_0.Child1 is
   type Bar is new B730006_0.Root with private;
   procedure Create (Foo : in out Bar);
private
   type Bar is new B730006_0.Root with record
      B : Boolean;
   end record;
end B730006_0.Child1;
