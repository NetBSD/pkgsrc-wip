

     --===================================================================--


package body CC51007_1 is

   procedure Handle (A: in out Low_Alert) is         -- Artificial for
   begin                                             -- testing.
      A.Time_Of_Arrival := Ada.Calendar.Time_Of (1984, 1, 1);
      A.Message := "Low Alert!";
   end Handle;

end CC51007_1;
