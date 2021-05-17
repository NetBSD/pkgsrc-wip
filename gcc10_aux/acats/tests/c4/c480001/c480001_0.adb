
package body C480001_0 is
   procedure Set_Val (Obj : in out Root; Val : in Natural) is
   begin
      Obj.My_Val := Val;
   end Set_Val;

   function Val (Obj : in Root) return Natural is
   begin
      return Obj.My_Val;
   end Val;

   procedure Bump (Obj : in out Root) is
   begin
      Obj.My_Val := Obj.My_Val + 1;
   end Bump;
end C480001_0;
