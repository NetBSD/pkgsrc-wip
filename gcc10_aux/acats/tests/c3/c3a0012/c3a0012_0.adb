 
 
 --=======================================================================--
 
 
 package body C3A0012_0 is
 
    procedure Log_Calc_Fast  (Angle      : in  Float; 
                              Method     : out Call_Kind) is separate;
 
    procedure Log_Calc_Acc   (Angle      : in  Float; 
                              Method     : out Call_Kind) is separate;
 
    procedure Log_Calc_Table (Angle      : in  Float; 
                              Method     : out Call_Kind) is separate;
 
 end C3A0012_0;
 
