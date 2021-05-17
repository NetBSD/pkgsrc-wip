
     --=================================================================--

package body B392004_0 is

   function No_Parm return Tagged_Type'class is
   begin
      return Tagged_Type'(Field => False);
   end No_Parm;
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
   procedure Proc_Specific_Type_Parms (P1, P2 : Tagged_Type) is
   begin
      null;
   end Proc_Specific_Type_Parms;
   -----------------------------------------
   procedure Proc_Specific_Type_Parms (P1, P2 : New_Tagged_Type) is
   begin
      null;
   end Proc_Specific_Type_Parms;

end B392004_0;
