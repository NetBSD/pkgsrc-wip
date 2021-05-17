
     --==================================================================--


package F731A00.B731A02 is

   package Nested2 is
      type Derived4 is new Parent with null record;
      -- function Vis_Op (P: Derived4) return Boolean implicitly declared here.

      Operand3 : Derived4;
      Object3A : Boolean := Vis_Op (Operand3);                        -- OK.

   end Nested2;

   procedure Dummy;   -- Forces this unit to have a body.

end F731A00.B731A02;
