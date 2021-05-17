

with Report;
with ImpDef;
package body C980003_0 is
     protected body State_Manager is
         procedure Reset is
         begin
             Current_State := Unknown;
             Changed := False;
         end Reset;

         procedure Set (New_State : States) is
         begin
             Changed := True;
             Current_State := New_State;
         end Set;

         function Current return States is
         begin
             return Current_State;
         end Current;

         entry Wait_For_Change when Changed is
         begin
             Changed := False;
         end Wait_For_Change;
     end State_Manager;

     procedure Initialize (Object : in out Is_Controlled) is
     begin
        if Verbose then
            Report.Comment ("starting initialize");
        end if;
        State_Manager.Set (Start_Init);
        if Verbose then
            Report.Comment ("in initialize");
        end if;
        delay ImpDef.Switch_To_New_Task;  -- tempting place for abort
        State_Manager.Set (Finished_Init);
        if Verbose then
            Report.Comment ("finished initialize");
        end if;
        Init_Occurred := True;
     end Initialize;

     procedure Finalize   (Object : in out Is_Controlled) is
     begin
        if Verbose then
            Report.Comment ("starting finalize");
        end if;
        State_Manager.Set (Start_Final);
        if Verbose then
            Report.Comment ("in finalize");
        end if;
        delay ImpDef.Switch_To_New_Task; -- tempting place for abort
        State_Manager.Set (Finished_Final);
        if Verbose then
            Report.Comment ("finished finalize");
        end if;
     end Finalize;

     procedure Adjust     (Object : in out Is_Controlled) is
     begin
        if Verbose then
            Report.Comment ("starting adjust");
        end if;
        State_Manager.Set (Start_Adjust);
        if Verbose then
            Report.Comment ("in adjust");
        end if;
        delay ImpDef.Switch_To_New_Task; -- tempting place for abort
        State_Manager.Set (Finished_Adjust);
        if Verbose then
            Report.Comment ("finished adjust");
        end if;
     end Adjust;
end C980003_0;
