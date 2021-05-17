

     --===================================================================--


with CC51007_1;
package CC51007_2 is

   type Person is (OOD, CO, CinC);

   type Medium_Alert is new CC51007_1.Low_Alert with record
      Action_Officer : Person := OOD;
   end record;

   procedure Handle (A: in out Medium_Alert);        -- Overrides parent's
                                                     -- implementation.
   Med : Medium_Alert;

end CC51007_2;
