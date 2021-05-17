
with C393013_1; use C393013_1;
with C393013_2;
with C393013_3;
with C393013_4;
with C393013_5;
with Report;
with Ada.Tags;
procedure C393013 is
   -- Static objects of each type:
   Gen : C393013_1.Generator;
   H2O : C393013_2.Water_Turbine;
   Wind: C393013_3.Windmill;
   Gas : C393013_4.Gas_Turbine;
   A_Wind : C393013_5.Alarmed_Windmill.Alarmed_Generator;
   M_H2O  : C393013_5.Monitored_Hydro.Monitored_Generator;
   M_Gas  : C393013_5.Monitored_Gas_Turbine.Monitored_Generator;
   use type Ada.Tags.Tag;

   procedure Make_Farm (First_Obj : Generator'Class;
			TC_Tag : Ada.Tags.Tag; TC_Id : String) is
     -- Clone First_Obj with dispatching calls:
     Obj1 : Generator'Class := First_Obj.Clone (New_Location => 'X');
     Obj2 : Generator'Class := First_Obj.Clone (New_Location => 'Y');
     Obj3 : Generator'Class := First_Obj.Clone (New_Location => 'Z');
   begin
     if Obj1.Location /= 'X' or else Obj2.Location /= 'Y' or else
        Obj3.Location /= 'Z' then
        Report.Failed ("Farm locations wrong - " & TC_Id);
     end if;
     if Obj1'Tag /= TC_Tag or else Obj2'Tag /= TC_Tag or else
        Obj3'Tag /= TC_Tag then
        Report.Failed ("Farm tag wrong - " & TC_Id);
     end if;
   end Make_Farm;

begin
   Report.Test ("C393013", "Check that a non-abstract function with a " &
                           "controlling result of type T is inherited " &
                           "as non-abstract and does not require " &
                           "overriding for a null extension of T " &
                           "and that the result of calling the inherited " &
                           "function has the tag of the extension");

   begin
      Gen := C393013_1.Create (10);
      if Gen.Power_Output /= Report.Ident_Int(10) then
          Report.Failed ("Wrong value for Gen");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for Gen.Create");
   end;

   begin
      H2O := C393013_2.Create (65);
      if H2O.Power_Output /= Report.Ident_Int(65) then
          Report.Failed ("Wrong value for H2O");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for H2O.Create");
   end;

   begin
      Wind := C393013_3.Create (23);
      if Wind.Power_Output /= Report.Ident_Int(23) then
          Report.Failed ("Wrong value for Wind");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for Wind.Create");
   end;

   begin
      Gas := C393013_4.Create (135);
      if Gas.Power_Output /= Report.Ident_Int(135) then
          Report.Failed ("Wrong value for Gas");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for Gas.Create");
   end;

   begin
      A_Wind := C393013_5.Alarmed_Windmill.Create (90);
      if A_Wind.Power_Output /= Report.Ident_Int(90) then
          Report.Failed ("Wrong value for A_Wind");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for A_Wind.Create");
   end;

   begin
      M_H2O := C393013_5.Monitored_Hydro.Create (43);
      if M_H2O.Power_Output /= Report.Ident_Int(43) then
          Report.Failed ("Wrong value for M_H2O");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for M_H2O.Create");
   end;

   begin
      M_Gas := C393013_5.Monitored_Gas_Turbine.Create (850);
      if M_Gas.Power_Output /= Report.Ident_Int(850) then
          Report.Failed ("Wrong value for M_Gas");
      end if;
   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised; tag wrong for M_Gas.Create");
   end;

   declare
      G1 : Generator'Class := C393013_1.Create (20);
      G2 : Generator'Class := C393013_2.Create (55);
      G3 : Generator'Class := C393013_3.Create (16);
      G4 : Generator'Class := C393013_4.Create (134);
      G5 : Generator'Class := C393013_5.Alarmed_Windmill.Create (40);
      G6 : Generator'Class := C393013_5.Monitored_Hydro.Create (1200);
      G7 : Generator'Class := C393013_5.Monitored_Gas_Turbine.Create (450);
      -- Test cloning; these are dispatching calls:
      G11 : Generator'Class := G1.Clone (New_Location => 'B');
      G12 : Generator'Class := G2.Clone (New_Location => 'C');
      G13 : Generator'Class := G3.Clone (New_Location => 'D');
      G14 : Generator'Class := G4.Clone (New_Location => 'E');
      G15 : Generator'Class := G5.Clone (New_Location => 'F');
      G16 : Generator'Class := G6.Clone (New_Location => 'G');
      G17 : Generator'Class := G7.Clone (New_Location => 'H');
   begin
      if G1.Power_Output /= Report.Ident_Int(20) or else
         G1.Location /= 'A' then
          Report.Failed ("Wrong values for G1");
      end if;
      if G1'Tag /= C393013_1.Generator'Tag then
          Report.Failed ("Wrong tag for G1");
      end if;

      if G2.Power_Output /= Report.Ident_Int(55) or else
         G2.Location /= 'A' then
          Report.Failed ("Wrong values for G2");
      end if;
      if G2'Tag /= C393013_2.Water_Turbine'Tag then
          Report.Failed ("Wrong tag for G2");
      elsif G2'Tag = G1'Tag then
          Report.Failed ("Tags same for objects of different types - G2");
      end if;

      if G3.Power_Output /= Report.Ident_Int(16) or else
         G3.Location /= 'A' then
          Report.Failed ("Wrong values for G3");
      end if;
      if G3'Tag /= C393013_3.Windmill'Tag then
          Report.Failed ("Wrong tag for G3");
      elsif G3'Tag = G1'Tag then
          Report.Failed ("Tags same for objects of different types - G3");
      end if;

      if G4.Power_Output /= Report.Ident_Int(134) or else
         G4.Location /= 'A' then
          Report.Failed ("Wrong values for G4");
      end if;
      if G4'Tag /= C393013_4.Gas_Turbine'Tag then
          Report.Failed ("Wrong tag for G4");
      elsif G4'Tag = G1'Tag then
          Report.Failed ("Tags same for objects of different types - G4");
      end if;

      if G5.Power_Output /= Report.Ident_Int(40) or else
         G5.Location /= 'A' then
          Report.Failed ("Wrong values for G5");
      end if;
      if G5'Tag /= C393013_5.Alarmed_Windmill.Alarmed_Generator'Tag then
          Report.Failed ("Wrong tag for G5");
      elsif G5'Tag = G1'Tag or else G5'Tag = G3'Tag then
          Report.Failed ("Tags same for objects of different types - G5");
      end if;

      if G6.Power_Output /= Report.Ident_Int(1200) or else
         G6.Location /= 'A' then
          Report.Failed ("Wrong values for G6");
      end if;
      if G6'Tag /= C393013_5.Monitored_Hydro.Monitored_Generator'Tag then
          Report.Failed ("Wrong tag for G6");
      elsif G6'Tag = G1'Tag or else G6'Tag = G2'Tag then
          Report.Failed ("Tags same for objects of different types - G6");
      end if;

      if G7.Power_Output /= Report.Ident_Int(450) or else
         G7.Location /= 'A' then
          Report.Failed ("Wrong values for G7");
      end if;
      if G7'Tag /= C393013_5.Monitored_Gas_Turbine.Monitored_Generator'Tag then
          Report.Failed ("Wrong tag for G7");
      elsif G7'Tag = G1'Tag or else G7'Tag = G4'Tag then
          Report.Failed ("Tags same for objects of different types - G7");
      end if;

      if G11.Power_Output /= Report.Ident_Int(20) or else
         G11.Location /= 'B' then
          Report.Failed ("Wrong values for G11");
      end if;
      if G11'Tag /= C393013_1.Generator'Tag then
          Report.Failed ("Wrong tag for G11");
      end if;

      if G12.Power_Output /= Report.Ident_Int(55) or else
         G12.Location /= 'C' then
          Report.Failed ("Wrong values for G12");
      end if;
      if G12'Tag /= C393013_2.Water_Turbine'Tag then
          Report.Failed ("Wrong tag for G12");
      end if;

      if G13.Power_Output /= Report.Ident_Int(16) or else
         G13.Location /= 'D' then
          Report.Failed ("Wrong values for G13");
      end if;
      if G13'Tag /= C393013_3.Windmill'Tag then
          Report.Failed ("Wrong tag for G13");
      end if;

      if G14.Power_Output /= Report.Ident_Int(134) or else
         G14.Location /= 'E' then
          Report.Failed ("Wrong values for G14");
      end if;
      if G14'Tag /= C393013_4.Gas_Turbine'Tag then
          Report.Failed ("Wrong tag for G14");
      end if;

      if G15.Power_Output /= Report.Ident_Int(40) or else
         G15.Location /= 'F' then
          Report.Failed ("Wrong values for G15");
      end if;
      if G15'Tag /= C393013_5.Alarmed_Windmill.Alarmed_Generator'Tag then
          Report.Failed ("Wrong tag for G15");
      end if;

      if G16.Power_Output /= Report.Ident_Int(1200) or else
         G16.Location /= 'G' then
          Report.Failed ("Wrong values for G16");
      end if;
      if G16'Tag /= C393013_5.Monitored_Hydro.Monitored_Generator'Tag then
          Report.Failed ("Wrong tag for G16");
      end if;

      if G17.Power_Output /= Report.Ident_Int(450) or else
         G17.Location /= 'H' then
          Report.Failed ("Wrong values for G17");
      end if;
      if G17'Tag /= C393013_5.Monitored_Gas_Turbine.Monitored_Generator'Tag then
          Report.Failed ("Wrong tag for G17");
      end if;

      -- Create a hydropower farm:
      Make_Farm (G2, C393013_2.Water_Turbine'Tag, "Hydro Farm");
      -- and a wind farm:
      Make_Farm (G3, C393013_3.Windmill'Tag,      "Wind Farm");
      -- and Hoover Dam (lots of hydropower, to light Las Vegas):
      Make_Farm (G6, C393013_5.Monitored_Hydro.Monitored_Generator'Tag, "Hoover Dam");
   end;

   Report.Result;

end C393013;
