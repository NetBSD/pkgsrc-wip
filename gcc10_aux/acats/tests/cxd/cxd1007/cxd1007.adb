

with System;
with Report;
with Ada.Dynamic_Priorities;
with CXD1007_1;
procedure CXD1007 is
  Verbose : constant Boolean := False;
  This_Procedure_Priority : constant System.Priority 
        := System.Default_Priority - 2;
  Real_Main_Priority : constant System.Priority
        := System.Default_Priority + 3;
  pragma Priority (Real_Main_Priority);

  Check_2_Priority : System.Any_Priority;

begin
  Report.Test ("CXD1007",
               "Check the priority of the environment task" &
               " and priorities set with dynamic expressions");

  -- check the priority of the main procedure.
  CXD1007_1;

  declare
    task Check_1 is
        pragma Priority (Report.Ident_Int (System.Default_Priority + 5));
    end Check_1;

    task body Check_1 is
      P : System.Any_Priority;
    begin
      P := Ada.Dynamic_Priorities.Get_Priority;
      if P /= System.Default_Priority + 5 then
        Report.Failed ("expected task priority to be" &
               System.Any_Priority'Image (System.Default_Priority + 5) &
               " but the priority was" &
               System.Any_Priority'Image (P) );
      else
        if Verbose then
          Report.Comment ("Check_1 priority is" &
                          System.Any_Priority'Image (P) &
                          " which is System.Default_Priority + 5" );
        end if;
      end if;
    end Check_1;

    task Check_2 is
        pragma Interrupt_Priority (
            Report.Ident_Int (System.Interrupt_Priority'First));
    end Check_2;

    task body Check_2 is
    begin
      Check_2_Priority := Ada.Dynamic_Priorities.Get_Priority;
    end Check_2;

  begin
    null;
  end;

  if Check_2_Priority /= System.Interrupt_Priority'First then
    Report.Failed ("expected task priority to be" &
           System.Any_Priority'Image (System.Interrupt_Priority'First) &
           " but the priority was" &
           System.Any_Priority'Image (Check_2_Priority) );
  else
    if Verbose then
      Report.Comment ("Check_2 priority is" &
                      System.Any_Priority'Image (Check_2_Priority) &
                      " which is System.Interrupt_Priority'First" );
    end if;
  end if;

  Report.Result;
end CXD1007;
