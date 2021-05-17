

     --==================================================================--


with B731A02_1;
use  B731A02_1;
package body F731A00.B731A02 is

   procedure Dummy is   
   begin
      null;
   end Dummy;


   package body Nested2 is

      -- function Pri_Op (P: Derived4) return Boolean implicitly declared here.

      Operand4 : Derived4;

      Object4A : Boolean := Pri_Op(Operand4);                         -- OK.
      Object4B : Integer := Operand4.Component;                       -- OK.

   end Nested2;


   type Derived5 is new Derived3 with null record; 
   -- function Vis_Op (P: Derived5) return Boolean implicitly declared here.

   Operand5 : Derived5;

   Object5A : Boolean := Vis_Op(Operand5);                            -- OK.


   Object5B : Boolean := Pri_Op(Operand5);                            -- ERROR:
                                           -- Pri_Op not declared for Derived5.

   Object5C : Integer := Operand5.Component;                          -- ERROR:
                                        -- Component not declared for Derived5.

end F731A00.B731A02;
