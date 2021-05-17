
with C393013_1;
with C393013_2;
with C393013_3;
with C393013_4;
with C393013_G1;
with C393013_G2;
package C393013_5 is

   package Alarmed_Windmill is new C393013_G1 (C393013_3.Windmill);

   package Monitored_Hydro is new C393013_G2 (C393013_2.Water_Turbine);

   package Monitored_Gas_Turbine is new C393013_G2 (C393013_4.Gas_Turbine);

end C393013_5;
