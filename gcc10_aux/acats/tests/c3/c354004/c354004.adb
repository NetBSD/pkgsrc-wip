


with C354004_Sim;
with Report;
with System;
procedure C354004 is
   type Addr_Reg_Type is (A0, A1, A2, A3);
begin

   Report.Test
     ("C354004",
      "Check the operation of the Mod attribute");

Case_1:
   declare
      type Addr_Type is mod System.Max_Binary_Modulus;
      type Big_Offset_Type is range System.Min_Int .. System.Max_Int;
      package Full_Sim is new C354004_Sim (Addr_Type,
                                           Big_Offset_Type,
                                           Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Full_Sim.Set_Address_Register (A0, 100);
      Full_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Full_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(1);
      if Temp_1 /= 101 or else
         Temp_1 /= Full_Sim.Calculate_Effective_Address (A0,  1) then
         Report.Failed ("Wrong result - MDM_B_1");
      end if;
      if Addr_Type'Last /= Full_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - MDM_B_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 2);
      if Temp_2 /= Full_Sim.Calculate_Effective_Address (A2,  -2) then
         Report.Failed ("Wrong result - MDM_B_3");
      end if;
      if Full_Sim.Calculate_Effective_Address (A0,  -10) /= 90 then
         Report.Failed ("Wrong result - MDM_B_4");
      end if;
      Temp_2 := Full_Sim.Address_Register_Value (A1) +
         Addr_Type'Mod(System.Max_Int);
      if Full_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - MDM_B_5");
      end if;
      Temp_2 := Full_Sim.Address_Register_Value (A1) +
         Addr_Type'Mod(System.Min_Int);
      if Full_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - MDM_B_6");
      end if;
   end Case_1;

Case_2:
   declare
      type Addr_Type is mod System.Max_Binary_Modulus;
      type Small_Offset_Type is range -128 .. 127;
      package Small_Sim is new C354004_Sim (Addr_Type,
                                            Small_Offset_Type,
                                            Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Small_Sim.Set_Address_Register (A0, 100);
      Small_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Small_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(-1);
      if Temp_1 /= 99 or else
         Temp_1 /= Small_Sim.Calculate_Effective_Address (A0,  -1) then
         Report.Failed ("Wrong result - MDM_S_1");
      end if;
      if Addr_Type'Last /=
         Small_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - MDM_S_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 4);
      if Temp_2 /= Small_Sim.Calculate_Effective_Address (A2,  -4) then
         Report.Failed ("Wrong result - MDM_S_3");
      end if;
      if Small_Sim.Calculate_Effective_Address (A0,  10) /= 110 then
         Report.Failed ("Wrong result - MDM_S_4");
      end if;
      Temp_2 := Small_Sim.Address_Register_Value (A1) + Addr_Type'Mod(127);
      if Small_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - MDM_S_5");
      end if;
      Temp_2 := Small_Sim.Address_Register_Value (A1) + Addr_Type'Mod(-128);
      if Small_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - MDM_S_6");
      end if;
   end Case_2;

Case_3:
   declare
      type Addr_Type is mod 2**8;
      type Small_Offset_Type is range -128 .. 127;
      package Tiny_Sim is new C354004_Sim (Addr_Type,
                                           Small_Offset_Type,
                                           Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Tiny_Sim.Set_Address_Register (A0, 100);
      Tiny_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Tiny_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(3);
      if Temp_1 /= 103 or else
         Temp_1 /= Tiny_Sim.Calculate_Effective_Address (A0,  3) then
         Report.Failed ("Wrong result - T_S_1");
      end if;
      if Addr_Type'Last /= Tiny_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - T_S_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 12);
      if Temp_2 /= Tiny_Sim.Calculate_Effective_Address (A2,  -12) then
         Report.Failed ("Wrong result - T_S_3");
      end if;
      if Tiny_Sim.Calculate_Effective_Address (A0, -120) /= 236 then
         Report.Failed ("Wrong result - T_S_4");
      end if;
      Temp_2 := Tiny_Sim.Address_Register_Value (A1) + Addr_Type'Mod(127);
      if Tiny_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - T_S_5");
      end if;
      Temp_2 := Tiny_Sim.Address_Register_Value (A1) + Addr_Type'Mod(-128);
      if Tiny_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - T_S_6");
      end if;
   end Case_3;

Case_4:
   declare
      type Addr_Type is mod 2**8;
      type Big_Offset_Type is range System.Min_Int .. System.Max_Int;
      package Tiny_Sim is new C354004_Sim (Addr_Type,
                                           Big_Offset_Type,
                                           Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Tiny_Sim.Set_Address_Register (A0, 100);
      Tiny_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Tiny_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(3);
      if Temp_1 /= 103 or else
         Temp_1 /= Tiny_Sim.Calculate_Effective_Address (A0,  3) then
         Report.Failed ("Wrong result - T_B_1");
      end if;
      if Addr_Type'Last /= Tiny_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - T_B_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 52);
      if Temp_2 /= Tiny_Sim.Calculate_Effective_Address (A2,  -52) then
         Report.Failed ("Wrong result - T_B_3");
      end if;
      if Tiny_Sim.Calculate_Effective_Address (A0, 250) /= 94 then
         Report.Failed ("Wrong result - T_B_4");
      end if;
      Temp_2 := Tiny_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Max_Int);
      if Tiny_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - T_B_5");
      end if;
      Temp_2 := Tiny_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Min_Int);
      if Tiny_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - T_B_6");
      end if;
   end Case_4;

Case_5:
   declare
      type Addr_Type is mod 1999; -- A prime. Not likely for this example,
                                  -- but common for modular types.
      type Small_Offset_Type is range -128 .. 127;
      package Prime_Sim is new C354004_Sim (Addr_Type,
                                            Small_Offset_Type,
                                            Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Prime_Sim.Set_Address_Register (A0, 100);
      Prime_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Prime_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(5);
      if Temp_1 /= 105 or else
         Temp_1 /= Prime_Sim.Calculate_Effective_Address (A0,  5) then
         Report.Failed ("Wrong result - P_S_1");
      end if;
      if Addr_Type'Last /=
         Prime_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - P_S_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 5);
      if Temp_2 /= Prime_Sim.Calculate_Effective_Address (A2,  -5) then
         Report.Failed ("Wrong result - P_S_3");
      end if;
      if Prime_Sim.Calculate_Effective_Address (A0, 100) /= 200 then
         Report.Failed ("Wrong result - P_S_4");
      end if;
      Temp_2 := Prime_Sim.Address_Register_Value (A1) + Addr_Type'Mod(127);
      if Prime_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - P_S_5");
      end if;
      Temp_2 := Prime_Sim.Address_Register_Value (A1) + Addr_Type'Mod(-128);
      if Prime_Sim.Calculate_Effective_Address (A1, Small_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - P_S_6");
      end if;
      if Prime_Sim.Calculate_Effective_Address (A1, 101) /= 0 then
         Report.Failed ("Wrong result - P_S_7");
      end if;
   end Case_5;

Case_6:
   declare
      type Addr_Type is mod 1999; -- A prime. Not likely for this example,
                                  -- but common for modular types.
      type Big_Offset_Type is range System.Min_Int .. System.Max_Int;
      package Prime_Sim is new C354004_Sim (Addr_Type,
                                            Big_Offset_Type,
                                            Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      Prime_Sim.Set_Address_Register (A0, 100);
      Prime_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      Prime_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(7);
      if Temp_1 /= 107 or else
         Temp_1 /= Prime_Sim.Calculate_Effective_Address (A0,  7) then
         Report.Failed ("Wrong result - P_B_1");
      end if;
      if Addr_Type'Last /=
         Prime_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - P_B_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 3);
      if Temp_2 /= Prime_Sim.Calculate_Effective_Address (A2,  -3) then
         Report.Failed ("Wrong result - P_B_3");
      end if;
      if Prime_Sim.Calculate_Effective_Address (A0, 2000) /= 101 then
         Report.Failed ("Wrong result - P_B_4");
      end if;
      Temp_2 := Prime_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Max_Int);
      if Prime_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - P_B_5");
      end if;
      Temp_2 := Prime_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Min_Int);
      if Prime_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - P_B_6");
      end if;
      if Prime_Sim.Calculate_Effective_Address (A1, 110) /= 9 then
         Report.Failed ("Wrong result - P_B_7");
      end if;
   end Case_6;


Case_7:
   declare
      type Addr_Type is mod System.Max_Nonbinary_Modulus;
      type Big_Offset_Type is range System.Min_Int .. System.Max_Int;
      package MNM_Sim is new C354004_Sim (Addr_Type,
                                            Big_Offset_Type,
                                            Addr_Reg_Type);
      Temp_1, Temp_2 : Addr_Type;
   begin
      MNM_Sim.Set_Address_Register (A0, 100);
      MNM_Sim.Set_Address_Register (A1, Addr_Type'Last - 100);
      MNM_Sim.Set_Address_Register (A2, 0);
      Temp_1 := 100 + Addr_Type'Mod(2);
      if Temp_1 /= 102 or else
         Temp_1 /= MNM_Sim.Calculate_Effective_Address (A0,  2) then
         Report.Failed ("Wrong result - MNM_B_1");
      end if;
      if Addr_Type'Last /= MNM_Sim.Calculate_Effective_Address (A1,  100) then
         Report.Failed ("Wrong result - MNM_B_2");
      end if;
      Temp_2 := Addr_Type'Val(Addr_Type'Modulus - 6);
      if Temp_2 /= MNM_Sim.Calculate_Effective_Address (A2,  -6) then
         Report.Failed ("Wrong result - MNM_B_3");
      end if;
      if MNM_Sim.Calculate_Effective_Address (A0, 2100) /= 2200 then
         Report.Failed ("Wrong result - MNM_B_4");
      end if;
      Temp_2 := MNM_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Max_Int);
      if MNM_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'Last) /=
         Temp_2 then
         Report.Failed ("Wrong result - MNM_B_5");
      end if;
      Temp_2 := MNM_Sim.Address_Register_Value (A1) +
                Addr_Type'Mod(System.Min_Int);
      if MNM_Sim.Calculate_Effective_Address (A1, Big_Offset_Type'First) /=
         Temp_2 then
         Report.Failed ("Wrong result - MNM_B_6");
      end if;
      if MNM_Sim.Calculate_Effective_Address (A1, 181) /= 80 then
         Report.Failed ("Wrong result - MNM_B_7");
      end if;
   end Case_7;

   Report.Result;

end C354004;
