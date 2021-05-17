

     --===================================================================--


package body BC30001_0 is

   function Func return Tagged_Type is
   begin
      return (Bool => True);
   end Func;


   function Func return Rec_Ext is
   begin
      return (Bool => True);
   end Func;


   function Func return Pri_Ext is
   begin
      return (Bool => True);
   end Func;

end BC30001_0;
