
package body C413005P is

   procedure Clear (X : in out TP) is
   begin
      X.Data := 0;
   end Clear;

   procedure Set  (X : in out TP; Value : Integer) is
   begin
      X.Data := Value;
   end Set;

   function Get (X : TP) return Integer is
   begin
      return X.Data;
   end Get;

   function  Prod (X : TP; Value : Integer) return Integer is
   begin
      return X.Data*Value;
   end Prod;

   procedure Class_Wide_Clear (X: in out TP'Class) is
   begin
      X.Data := 0;
   end Class_Wide_Clear;

   procedure Class_Wide_Set (X: in out TP'Class; Value : Integer) is
   begin
      X.Data := Value;
   end Class_Wide_Set;

   function Class_Wide_Get (X : TP'Class) return Integer is
   begin
      return X.Data;
   end Class_Wide_Get;

   function Class_Wide_Prod
     (X : TP'Class; Value : Integer) return Integer is
   begin
      return X.Data * Value;
   end Class_Wide_Prod;
end C413005P;
