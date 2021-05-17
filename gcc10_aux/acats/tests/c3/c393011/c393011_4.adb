 
 package body C393011_4 is
 
   procedure Display    (FA : in Final_Alert_Type) is 
     begin
       Definitions.Display_Device := FA.Display_Dev;
     end Display;
 
   procedure Handle (FA : in out Final_Alert_Type) is
     begin
       Set_Status (FA, Definitions.Handled);
       Set_Serial (FA);
       Display (FA);
     end Handle;
 end C393011_4;
