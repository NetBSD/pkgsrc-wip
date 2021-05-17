

     --===================================================================--


with CC54004_0;
use  CC54004_0;
package CC54004_1 is

   type Low_Alert is new CC54004_0.Alert with record
      C1 : String (1 .. 5) := "Dummy";
      -- ...Other components.
   end record;

   procedure Handle (A : in out Low_Alert);          -- Overrides parent's
                                                     -- operations.
   --...Other operations.


   type Medium_Alert is new Low_Alert with record
      C : Integer := 6;
      -- ...Other components.
   end record;

   procedure Handle (A : in out Medium_Alert);       -- Overrides parent's
                                                     -- operations.
   --...Other operations.

end CC54004_1;
