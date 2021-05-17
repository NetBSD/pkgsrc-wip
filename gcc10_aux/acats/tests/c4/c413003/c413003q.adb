
package body C413003Q is
   procedure Prim_Proc (X: access TQ) is
   begin
      X.Data := 20;
   end Prim_Proc;

   procedure Prim_Proc (X : access TQ; Value : Integer) is
   begin
      X.Data := 2 * Value;
   end Prim_Proc;

   function Prim_Func (X : access constant TQ) return Integer is
   begin
      return 3;
   end Prim_Func;

   function Prim_Func (X : access constant TQ; Value : Integer) return Integer is
   begin
      return 2 * Value;
   end Prim_Func;

   procedure Class_Wide_Proc (X : access TQ'Class; Value : Float) is
   begin
      X.Value := 3.0 * Value;
   end Class_Wide_Proc;

   function Class_Wide_Func (X : access constant TQ'Class; Value : Float) return Float is
   begin
      return 3.0 * Value;
   end Class_Wide_Func;

   function Prim_New_Func (X : access constant TQ) return Integer is
   begin
      return -4;
   end Prim_New_Func;

   package body Local is
      procedure Prim_Proc (X : access TPP) is
      begin
         X.Data := 100;
      end Prim_Proc;

      procedure Prim_Proc (X : access TPP; Value : Integer) is
      begin
         X.Data := 4 * Value;
      end Prim_Proc;

      function Prim_Func (X : access constant TPP) return Integer is
      begin
         return 102;
      end Prim_Func;

      function Prim_Func (X : access constant TPP; Value : Integer) return Integer is
      begin
         return 4 * Value;
      end Prim_Func;
   end Local;
end C413003Q;
