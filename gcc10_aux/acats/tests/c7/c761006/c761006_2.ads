
------------------------------------------------------------------- C761006_2

with C761006_1;
package C761006_2 is

  type Init_Check is new C761006_1.Init_Check_Root with null record;
  type Adj_Check is  new C761006_1.Adj_Check_Root  with null record;
  type Fin_Check is  new C761006_1.Fin_Check_Root  with null record;

end C761006_2;
