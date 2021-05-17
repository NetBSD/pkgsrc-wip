
------------------------------------------------------------------- C761006_1

with Ada.Finalization;
with C761006_0;
package C761006_1 is

  type Init_Check_Root is new Ada.Finalization.Controlled with record
    Good_Component : C761006_0.Good;
    Init_Fails     : C761006_0.Bad_Initialize;
  end record;

  type Adj_Check_Root is new Ada.Finalization.Controlled with record
    Good_Component : C761006_0.Good;
    Adj_Fails      : C761006_0.Bad_Adjust;
  end record;

  type Fin_Check_Root is new Ada.Finalization.Controlled with record
    Good_Component : C761006_0.Good;
    Fin_Fails      : C761006_0.Bad_Finalize;
  end record;

end C761006_1;
