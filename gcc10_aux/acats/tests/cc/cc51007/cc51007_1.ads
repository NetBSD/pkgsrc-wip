
-- No body for CC51007_0;


     --===================================================================--


with CC51007_0;

with Ada.Calendar;
pragma Elaborate (Ada.Calendar);

package CC51007_1 is

   type Low_Alert is new CC51007_0.Alert with record
      Time_Of_Arrival : Ada.Calendar.Time := Ada.Calendar.Time_Of (1901, 8, 1);
   end record;

   procedure Handle (A: in out Low_Alert);           -- Overrides parent's
                                                     -- implementation.
   Low : Low_Alert;

end CC51007_1;
