

     --==================================================================--


package body CC70B02_0 is

   procedure Double (Object : in out Discrete_Type) is
      Doubled_Position : Integer := Discrete_Type'Pos (Object) * 2;
   begin
      -- ... Error-checking code omitted for brevity.
      Object := Discrete_Type'Val (Doubled_Position);
   end Double;

end CC70B02_0;
