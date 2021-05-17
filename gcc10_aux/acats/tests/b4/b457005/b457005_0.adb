
     --=================================================================--

package body B457005_0 is

   function No_Parm return Tagged_Type'class is
   begin
      return Tagged_Type'(Field => False);
   end No_Parm;
   -----------------------------------------
   function Indeterminate return Tagged_Type is
   begin
      return (Field => False);
   end Indeterminate;
   -----------------------------------------
   function Indeterminate return New_Tagged_Type is
   begin
      return (Field => True, New_Field => 12);
   end Indeterminate;
   -----------------------------------------
   function One_Parm (P : Tagged_Type) return Tagged_Type is
   begin
      return (Field => False);
   end One_Parm;
   -----------------------------------------
   function One_Parm (P : New_Tagged_Type) return New_Tagged_Type is
   begin
      return P;
   end One_Parm;
   -----------------------------------------
   procedure Proc_One_Parm (P : Tagged_Type) is null;
   -----------------------------------------
   procedure Proc_One_Parm (P : New_Tagged_Type) is null;

end B457005_0;
