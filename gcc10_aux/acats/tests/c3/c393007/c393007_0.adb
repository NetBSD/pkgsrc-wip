    -- Alert_System;
 
 --=======================================================================--
 
   package body C393007_0 is
             -- Alert_System
 
     function Time_Stamp return DT_Type is
       begin
         Day_Time := Day_Time + 1;
         return Day_Time;
       end Time_Stamp;
 
     procedure Set_Time (A : in out Alert_Type) is
       begin
         A.Time_Of_Arrival := Time_Stamp;
       end Set_time;
       
     function Correct_Time_Stamp ( A : Alert_Type) return Boolean is
       begin
         return (A.Time_Of_Arrival = Day_Time);
       end Correct_Time_Stamp;
 
   end C393007_0;
