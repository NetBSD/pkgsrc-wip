

-----------------------------------------------------------------------------


package body C3A0002_0 is

   procedure Log_Calc_Fast (Angle : in Float) is
   begin
      TC_Call_Tag := 1;
      Return_Num := Angle;
   end Log_Calc_Fast;


   procedure Log_Calc_Acc (Angle : in Float) is
   begin
      TC_Call_Tag  := 2;
      Return_Num := Angle;
   end Log_Calc_Acc;


   procedure Log_Calc_Table (Angle : in Float) is
   begin
      TC_Call_Tag := 3;
      Return_Num := Angle;
   end Log_Calc_Table;

end C3A0002_0;
