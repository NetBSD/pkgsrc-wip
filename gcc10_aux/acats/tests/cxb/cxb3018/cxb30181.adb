
with Interfaces.C;
package body CXB30181 is

   procedure Ada_Doubler
      (InOut1 : in out Interfaces.C.int;
       InOut2 : in out Interfaces.C.Short;
       InOut3 : in out Interfaces.C.C_Float;
       InOut4 : in out Interfaces.C.Double) is
	-- Double the value of each of the parameters.
      use type Interfaces.C.int;
      use type Interfaces.C.short;
      use type Interfaces.C.C_float;
      use type Interfaces.C.double;
   begin
      InOut1 := InOut1 * 2;
      InOut2 := InOut2 * 2;
      InOut3 := InOut3 * 2.0;
      InOut4 := InOut4 * 2.0;
   end Ada_Doubler;

end CXB30181;
