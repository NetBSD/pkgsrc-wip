

     --==================================================================--


with Report;
package body C3A2004A is

   function Zap (Val : Int_Ptr) return Float is
   begin
      Val.all := Val.all + 2;
      return Float(Val.all-2);
   end Zap;

   function Zap (Val : Float_Ptr) return Float is
   begin
      Report.Failed("Wrong Zap (Float) called");
      return Val.all;
   end Zap;

   procedure Zip (Val : Access_Proc) is
   begin
      Val (True); -- OK
   end Zip;

   procedure Zip (Val : Access_Func) is
   begin
      Report.Failed("Wrong Zip (Func) called");
      if Val (10) then
         null;
      end if;
   end Zip;

   function Zep (Val : Int_Ptr) return Float is
   begin
      Val.all := Val.all + 4;
      return Float(Val.all-4);
   end Zep;

   function Zep (Val : Access_Func) return Float is
   begin
      if Val (10) then -- OK
         return 2.0;
      else
         return 0.0;
      end if;
   end Zep;

   Result : aliased Integer := 32;

   function Zyp return Int_Ptr is
   begin
      return Result'access;
   end Zyp;

   function Zyp return Char_Ptr is
   begin
      Report.Failed("Wrong Zyp (Char) called");
      return null;
   end Zyp;

   procedure Set_Flag (Flag : Boolean) is
   begin
      if Flag then
         TC_Set_Flag_Count := TC_Set_Flag_Count + 1;
      else
         TC_Set_Flag_Count := TC_Set_Flag_Count + 5;
      end if;
   end Set_Flag;


   procedure Set_Flag (Value : Integer) is
   begin
      Report.Failed("Wrong Set_Flag (Integer) called");
   end Set_Flag;


   package body Pkg is
      procedure My_Op (Val : access My_Tagged) is
      begin
         Val.TC_Count := Val.TC_Count + 1;
      end My_Op;
   end Pkg;

   package body Pkg2 is
      procedure My_Op (Val : access New_Tagged) is
      begin
         Val.TC_Count := Val.TC_Count + 5;
      end My_Op;
   end Pkg2;

end C3A2004A;
