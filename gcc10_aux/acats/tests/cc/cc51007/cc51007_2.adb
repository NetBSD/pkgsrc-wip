

     --===================================================================--


with Ada.Calendar;
package body CC51007_2 is

   procedure Handle (A: in out Medium_Alert) is      -- Artificial for
   begin                                             -- testing.
      A.Action_Officer := CO;
      A.Time_Of_Arrival := Ada.Calendar.Time_Of (2001, 1, 1);
      A.Message := "Med Alert!";
   end Handle;

end CC51007_2;
