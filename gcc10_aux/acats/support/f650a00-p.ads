
--=======================================================================--

package F650A00.P is
   type Status_Kind is (Practice, Real, Dont_Care);
   type Urgency_Kind is (Low, Medium, High);

   type Practice_Alert is new Alert with record
      Status : Status_Kind := Dont_Care;
      Urgency : Urgency_Kind := Low;
   end record;

   overriding
   procedure Handle (PA : in out Practice_Alert);

   function Make_Alert_for_Time (Time : in Duration) return Practice_Alert;

end F650A00.P;
