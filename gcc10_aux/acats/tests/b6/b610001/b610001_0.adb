
     --==================================================================--

package body B610001_0 is

   procedure Acc_Float_Proc (P : access Float) is 
   begin
      null;
   end Acc_Float_Proc;

   --------------------------------------------------------------------------
   procedure Acc_Rec_Proc (P : access Rec) is 
   begin
      null;
   end Acc_Rec_Proc;

   --------------------------------------------------------------------------
   procedure Acc_NTag_Proc (P : access NewTag) is
   begin
      null;
   end Acc_NTag_Proc;

   --------------------------------------------------------------------------
   procedure Acc_CW_Tag_Proc (P : access Tag'Class) is
   begin
      null;
   end Acc_CW_Tag_Proc;

   --------------------------------------------------------------------------
   procedure Acc_CW_NTag_Proc (P : access NewTag'Class) is
   begin
      null;
   end Acc_CW_NTag_Proc;

   --------------------------------------------------------------------------
   function Acc_W_Default (P : access Rec := new Rec'(C => 25))      -- OK.
     return Integer is
   begin
      return 12;
   end Acc_W_Default;

end B610001_0;
