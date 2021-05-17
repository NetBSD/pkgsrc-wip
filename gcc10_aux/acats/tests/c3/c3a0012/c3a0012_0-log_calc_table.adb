 
 
 --=======================================================================--
 
 
 Separate (C3A0012_0)
 procedure Log_Calc_Table (Angle      : in  Float;
                           Method     : out Call_Kind) is
 begin
    C3A0012_0.Log_Result := Angle;
    Method := Table_Lookup_Call;
 end Log_Calc_Table;
 
