
with B730006_0.Child1;
package B730006_0.Child2 is
   type Dock is tagged private;
   procedure Create (Bay : in out Dock);
private
   type Dock is new B730006_0.Child1.Bar with record
      C : Float; -- OK: Same name as component in Root,
                 -- but it is not visible here.
   end record;
end B730006_0.Child2;
