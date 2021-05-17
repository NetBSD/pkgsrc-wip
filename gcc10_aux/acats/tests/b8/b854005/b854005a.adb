
package body B854005A is

   function Count (Obj : in Counter) return Natural is
   begin
      return Obj.Num;
   end Count;

   procedure Set (Obj : in out Counter; Num : in Natural) is
   begin
      Obj.Num := Num;
   end Set;

   procedure Bump (Obj : in out Counter) is
   begin
      Obj.Num := Obj.Num + 1;
   end Bump;

end B854005A;
