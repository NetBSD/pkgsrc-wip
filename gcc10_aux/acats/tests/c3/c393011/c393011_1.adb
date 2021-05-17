  -- Alert
 
 --=======================================================================--
 
 with C393011_0;
 package body C393011_1 is
           -- Alert
   procedure Set_Status ( A : in out Alert_Type;
                         To : Definitions.Status_Enum) is
     begin
       A.Status := To;
     end Set_Status;
 
 end C393011_1;
