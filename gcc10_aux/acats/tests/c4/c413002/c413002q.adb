
package body C413002Q is
   procedure Prim_Proc (X: in out TQ) is
   begin
      X.Data := 20;
   end Prim_Proc;

   procedure Prim_Proc (X : in out TQ; Value : Integer) is
   begin
      X.Data := 2 * Value;
   end Prim_Proc;

   function Prim_Func (X : TQ) return Integer is
   begin
      return 3;
   end Prim_Func;

   function Prim_Func (X : TQ; Value : Integer) return Integer is
   begin
      return 2 * Value;
   end Prim_Func;

   procedure Class_Wide_Proc (X : in out TQ'Class; Value : Float) is
   begin
      X.Value := 3.0 * Value;
   end Class_Wide_Proc;

   function Class_Wide_Func (X : TQ'Class; Value : Float) return Float is
   begin
      return 3.0 * Value;
   end Class_Wide_Func;

   function Prim_New_Func (X : TQ) return Integer is
   begin
      return -4;
   end Prim_New_Func;

   package body Local is
      procedure Prim_Proc (X : in out TPP) is
      begin
         X.Data := 100;
      end Prim_Proc;

      procedure Prim_Proc (X : in out TPP; Value : Integer) is
      begin
         X.Data := 4 * Value;
      end Prim_Proc;

      function Prim_Func (X : TPP) return Integer is
      begin
         return 102;
      end Prim_Func;

      function Prim_Func (X : TPP; Value : Integer) return Integer is
      begin
         return 4 * Value;
      end Prim_Func;
   end Local;
end C413002Q;
