
     --==================================================================--

with Report;
with C730002_0;  use C730002_0;
with C730002_2;  use C730002_2;
with C730002_4;  use C730002_4;
with C730002_5;  use C730002_5;

procedure C730002 is
begin

   Report.Test ("C730002", "Check that the full view of a private "        &
                           "extension may be derived indirectly from "     &
                           "the ancestor type.  Check for a case where "   &
                           "the parent type is derived from the ancestor " &
                           "type through a series of types produced by "   &
                           "generic instantiations");

   Test_Block:
   declare
      Nuclear_Drive : Nuclear_Series;
      Warp_Drive    : Nuclear_Series;
   begin

      -- Non-Dispatching Case:
      -- Call Routine_Maintenance using formal parameter name from
      -- C730002_0.Routine_Maintenance (ancestor version).
      -- Give no second parameter so that the default expression must be
      -- used.

      Routine_Maintenance (Engine => Nuclear_Drive);

      -- The value of the Specialist component should equal "Moe",
      -- which is the default value from the ancestor's version of
      -- Routine_Maintenance, and not the default value from the parent's
      -- version of Routine_Maintenance.

      if TC_Specialist (Nuclear_Drive) /= Moe then
         Report.Failed
           ("Default expression for ancestor op not used " &
            " - non-dispatching case");
      end if;

      -- However the value of the Ave_Repair_Time and Personnel_Required 
      -- components should be those assigned in the parent type's version 
      -- of the body of Routine_Maintenance.
      -- Note: Only components associated with the ancestor type are
      --       evaluated for the purposes of this test.

      if TC_Personnel_Required (Nuclear_Drive) /= 3  or
         TC_Time_Required (Nuclear_Drive)      /= 9
      then
         Report.Failed("Wrong body was executed - non-dispatching case");
      end if;

      -- Dispatching Case:
      -- Use a dispatching subprogram to ensure that the correct body is 
      -- used at runtime.

      Maintain_The_Engine (Warp_Drive);

      -- The resulting assignments to the fields of the Warp_Drive variable
      -- should be the same as those of the Nuclear_Drive above, indicating
      -- that the body of the parent version of the inherited subprogram
      -- was used.

      if TC_Specialist (Warp_Drive) /= Moe then
         Report.Failed
           ("Default expression for ancestor op not used - dispatching case");
      end if;

      if TC_Personnel_Required (Nuclear_Drive) /= 3  or
         TC_Time_Required (Nuclear_Drive)      /= 9
      then
         Report.Failed("Wrong body was executed - dispatching case");
      end if;


   exception
      when others => Report.Failed("Exception raised in Test_Block");
   end Test_Block;

   Report.Result;

end C730002;
