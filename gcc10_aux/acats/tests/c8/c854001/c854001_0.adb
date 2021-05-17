

     --==================================================================--


package body C854001_0 is

   procedure Root_Proc (P: in out Root) is
   begin
      P.Called := Initial_Value;
   end Root_Proc;

   ---------------------------------------
   procedure Over_Proc (P: in out Root) is
   begin
      P.Called := Op_Of_Type;
   end Over_Proc;

   ---------------------------------------
   function Root_Func return Root is
   begin
      return (Called => Op_Of_Type);
   end Root_Func;
 
   ---------------------------------------
   function Over_Func return Root is
   begin
      return (Called => Initial_Value);
   end Over_Func;

   ---------------------------------------
   function "+" (P1, P2 : Short_Int) return Short_Int is
   begin
      return 15;
   end "+";

   ---------------------------------------
   function Name (P1, P2 : Short_Int) return Short_Int is
   begin
      return 47;
   end Name;

   ---------------------------------------
   function "=" (P1, P2 : Tag_Type) return Boolean is
   begin
      return False;
   end "=";

end C854001_0;
