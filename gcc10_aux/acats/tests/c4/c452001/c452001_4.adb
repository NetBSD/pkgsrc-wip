
with Report;
package body C452001_4 is

   procedure Change (Object : in out Tagged_Partial_Tagged_Full;
                    Value  : in Boolean) is
   begin
      Object := (Report.Ident_Bool(Value), Object.C);
   end Change;

   procedure Change (Object : in out Untagged_Partial_Tagged_Full;
                    Value  : in Integer) is
   begin
      Object := (Report.Ident_Int(Value), Object.P);
   end Change;

   procedure Change (Object : in out Untagged_Partial_Untagged_Record_Full;
                    Value  : in Duration) is
   begin
      Object := (Value, Report.Ident_Str(Object.S));
   end Change;

   procedure Change (Object : in out Untagged_Partial_Untagged_Array_Full;
                     Value  : in Character) is
   begin
      Object := (Report.Ident_Char(Object(1)), Object(2), Object(3),
         Object(4), Object(5), Object(6), Report.Ident_Char(Value), Value);
   end Change;

   function "=" (L, R : in Tagged_Partial_Tagged_Full) return Boolean is
   begin
      return L.C = R.C;
   end "=";

   function "=" (L, R : in Untagged_Partial_Tagged_Full) return Boolean is
   begin
      return L.P = R.P;
   end "=";

   function "=" (L, R : in Untagged_Partial_Untagged_Record_Full) return Boolean is
   begin
      return R.S = L.S;
   end "=";

   function "=" (L, R : in Untagged_Partial_Untagged_Array_Full) return Boolean is
   begin
      return R(1) = L(1) and R(2) = L(2) and R(3) = L(3) and R(4) = L(4);
   end "=";

end C452001_4;
