
with F650A00.P, F650A00.S;
package C650A01_Alerts is
    Practice : aliased F650A00.P.Practice_Alert :=
             F650A00.P.Make_Alert_for_Time (8.0);
    Trial : aliased F650A00.P.Practice_Alert :=
             (F650A00.Alert with Status => F650A00.P.Real,
                 Urgency => F650A00.P.Low);
    Special : aliased F650A00.S.Special_Alert :=
             F650A00.S.Make_Alert_for_Time (54.0);
end C650A01_Alerts;
