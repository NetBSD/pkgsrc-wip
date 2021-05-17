 
 
 --=======================================================================--
 
 
 Separate (C3A0012_0)
 procedure Log_Calc_Acc (Angle    : in  Float;
                         Method   : out Call_Kind) is
 begin
    C3A0012_0.Log_Result := Angle;
    Method := Accurate_Call;
 end Log_Calc_Acc;
