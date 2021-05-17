

     --==================================================================--


with CC51006_1; -- Generic weight operations.
with CC51006_2; -- Extensions to weight class.

with Report;
procedure CC51006 is

   package Metric_Wts_G  is new CC51006_1 (CC51006_2.Grams);      -- Unconstr.
   package Metric_Wts_MG is new CC51006_1 (CC51006_2.Milligrams); -- Constr.
   package US_Wts        is new CC51006_1 (CC51006_2.Pounds);     -- Constr.

   Gms : CC51006_2.Grams      := 113.451;
   Mgm : CC51006_2.Milligrams := 0.549;
   Lbs : CC51006_2.Pounds     := 24.52;


   subtype TC_Buffers is String (1 .. 33);

   TC_Expected : constant TC_Buffers := "Root type's implementation called";
   TC_Buffer   :          TC_Buffers;

begin
   Report.Test ("CC51006", "Check that, in an instance, each implicit "  &
                "declaration of a primitive subprogram of a formal "     &
                "(nontagged) type declares a view of the corresponding " &
                "primitive subprogram of the ancestor type");


   Metric_Wts_G.Output_Weight (Gms, TC_Buffer);

   if TC_Buffer /= TC_Expected then
      Report.Failed ("Root operation not called for unconstrained derivative");
   end if;


   Metric_Wts_MG.Output_Weight (Mgm, TC_Buffer);

   if TC_Buffer /= TC_Expected then
      Report.Failed ("Root operation not called for constrained subtype");
   end if;


   US_Wts.Output_Weight (Lbs, TC_Buffer);

   if TC_Buffer /= TC_Expected then
      Report.Failed ("Root operation not called for constrained derivative");
   end if;

   Report.Result;
end CC51006;
