
     --==================================================================--

with C730001_0; use C730001_0;
with C730001_1; use C730001_1;
with C730001_2; use C730001_2;
with C730001_3; use C730001_3;

with Report;

procedure C730001 is
begin

   Report.Test ("C730001","Check that the full view of a private extension " &
                          "may be derived indirectly from the ancestor "     &
                          "type. Check that, for a primitive subprogram "    &
                          "of the private extension that is inherited from " &
                          "the ancestor type and not overridden, the "       &
                          "formal parameter names and default expressions "  &
                          "come from the corresponding primitive "           &
                          "subprogram of the ancestor type, while the body " &
                          "comes from that of the parent type");

   Test_Block:
   declare

      Alarm                : Alarm_Clock;
      Hot_Line             : Secure_Phone_Type;
      TeleConference_Phone : Auditorium_Phone_Type;

   begin

   -- Evaluate non-dispatching case:

      -- Call Set_Display using formal parameter name from 
      -- C730001_0.Set_Display.
      -- Give no 2nd parameter so that default expression must be used.

      Set_Display (C => Alarm);
    
      -- The value of the Display component should equal Digital, which is
      -- the default value from the ancestor's version of Set_Display,
      -- and not the default value from the parent's version of Set_Display.

      if TC_Get_Display (Alarm) /= Digital then
         Report.Failed ("Default expression for ancestor op not used " &
                        "in non-dispatching case");
      end if;

      -- However, the value of the Illumination component should equal
      -- Phosphorescence, which is assigned in the parent type's version of
      -- the body of Set_Display.

      if TC_Get_Display_Illumination (Alarm) /= Phosphorescence then
         Report.Failed ("Wrong body was executed in non-dispatching case");
      end if;


   -- Evaluate dispatching case:
      declare

         Hot_Line             : Secure_Phone_Type;
         TeleConference_Phone : Auditorium_Phone_Type;

         procedure Answer_The_Phone (P : in out Phone'Class) is
         begin
            -- Give no 2nd parameter so that default expression must be used.
            Answer (P);
         end Answer_The_Phone;

      begin

         Answer_The_Phone (Hot_Line);
         Answer_The_Phone (TeleConference_Phone);

         -- The value of the Indicator field shold equal "Light", the default
         -- value from the ancestor's version of Answer, and not the default
         -- from either of the parent versions of Answer.

         if TC_Get_Indicator(Hot_Line)             /= Light   or
            TC_Get_Indicator(TeleConference_Phone) /= Light
         then
            Report.Failed("Default expression from ancestor operation " &
                          "not used in dispatching case");
         end if;

         -- However, the value of the Status component should equal
         -- Call_Waiting or Conference respectively, based on the assignment
         -- in the parent type's version of the body of Answer.

         if TC_Get_Phone_Status(Hot_Line)  /=  Call_Waiting then
            Report.Failed("Wrong body executed in dispatching case - 1");
         end if;

         if TC_Get_Phone_Status(TeleConference_Phone) /= Conference then
            Report.Failed("Wrong body executed in dispatching case - 2");
         end if;

      end;

   exception
      when others => Report.Failed ("Exception raised in Test_Block");
   end Test_Block;


   Report.Result;

end C730001;
