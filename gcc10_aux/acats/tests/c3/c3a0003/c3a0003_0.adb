

-----------------------------------------------------------------------------


package body C3A0003_0 is

   function Sine_Calc_Fast (Angle : in Real_Num) return Real_Num is
      Sine_Num : Real_Num := 1.0;
   begin
      TC_Call_Tag := 1;
      return Sine_Num;
   end Sine_Calc_Fast;


   function Sine_Calc_Acc (Angle : in Real_Num) return Real_Num is
      Sine_Num : Real_Num := 0.0;
   begin
      TC_Call_Tag := 2;
      return Sine_Num;
   end Sine_Calc_Acc;


   function Sine_Calc_Table (Angle : in Real_Num) return Real_Num is
      Sine_Num : Real_Num := -1.0;
   begin
      TC_Call_Tag := 3;
      return Sine_Num;
   end Sine_Calc_Table;

end C3A0003_0;
