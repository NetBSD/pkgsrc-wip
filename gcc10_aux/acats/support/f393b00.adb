 
 --=======================================================================--
 
 package body F393B00 is
 
      procedure Handle (PA : in out Practice_Alert) is
        begin
          PA.Status := Real;
          PA.Urgency := Medium;
        end Handle;
 
 end F393B00;
 
