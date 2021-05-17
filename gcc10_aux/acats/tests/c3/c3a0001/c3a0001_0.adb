

-----------------------------------------------------------------------------


package body C3A0001_0 is

   function Sine_Calc_Fast (Angle : in Float) return Float is
   begin
      TC_Call_Tag := 1;
      return 1.0;
   end Sine_Calc_Fast;


   function Sine_Calc_Acc (Angle : in Float) return Float is
   begin
      TC_Call_Tag := 2;
      return 0.0;
   end Sine_Calc_Acc;


   function Sine_Calc_Table (Angle : in Float) return Float is
   begin
      TC_Call_Tag := 3;
      return -1.0;         
   end Sine_Calc_Table;

end C3A0001_0;
