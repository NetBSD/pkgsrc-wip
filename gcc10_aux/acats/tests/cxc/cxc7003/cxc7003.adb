

------------------------------------------------------------------

with CXC7003_0;
with ImpDef;
with Report;
with Ada.Task_Identification;
with Ada.Task_Attributes;
with Ada.Exceptions;
procedure CXC7003 is
   Verbose : constant Boolean := False;
   Not_Supported_Error : exception;
begin
   Report.Test ("CXC7003",
                "Check that Set_Value and Reinitialize" &
                " finalize the previous attribute value");

   begin
      declare
         package TID renames Ada.Task_Identification;
         generic package TA  renames Ada.Task_Attributes;
         package FTA is new TA (CXC7003_0.Notes_Finalization,
                                CXC7003_0.Object_4);
      begin
         declare

            -- The following task doesn't really do anything.  It is just around
            -- so we can set its attribute.

            task Check_It is
               entry Get_Id (Id : out TID.Task_Id);
               entry Ok_To_Terminate;
            end Check_It;

            task body Check_It is
            begin
               accept Get_Id (Id : out TID.Task_Id) do
                  Id := TID.Current_Task;
               end Get_Id;
               accept Ok_To_Terminate;
            end Check_It;
      
            Check_It_TID : TID.Task_ID;
         begin
            Check_It.Get_Id (Check_It_TID);

            begin
               -- set Check_It's attribute to 1 and the environment task's to 2
               FTA.Set_Value (CXC7003_0.Object_1, Check_It_TID);
               FTA.Set_Value (CXC7003_0.Object_2);
            exception
               when Info:others => 
                  Report.Not_Applicable("System not capable of supporting a " &
                               "task attribute of a controlled type -- " &
                               "exception during Set_Value");
                  if Verbose then
                     Report.Comment ("Exception raised was" &
                                     Ada.Exceptions.Exception_Name(Info));
                  end if;
                  raise Not_Supported_Error;
            end;

            -- set a new value for Check_It's attribute and make sure that 
            -- the object with Id 1 was finalized.
            CXC7003_0.Last_Finalized := 9; -- state known not to be 
                                           -- produced by finalize
            FTA.Set_Value (CXC7003_0.Object_3, Check_It_TID);
            case CXC7003_0.Last_Finalized is
               when 1 => if Verbose then
                             Report.Comment ("Set_value finalization ok");
                         end if;
               when 2 => Report.Failed ("Wrong task's attribute finalized");
               when 9 =>Report.Failed("No finalization occurred for set_value");
               when others => Report.Failed ("Unexpected result for set_value:"
                                  & Integer'Image (CXC7003_0.Last_Finalized));
            end case;

            -- restore the default value for the environment task.  This should 
            -- finalize the object with Id 2
            CXC7003_0.Last_Finalized := 9; -- state known not to be 
                                           -- produced by finalize
            FTA.Reinitialize; 
            case CXC7003_0.Last_Finalized is
               when 2 => if Verbose then
                              Report.Comment ("Reinitialize finalization ok");
                         end if;
               when 3 => Report.Failed ("Wrong task's attribute finalized" &
                                        " in reinitialize");
               when 9 => Report.Failed ("No finalization occurred" &
                                        " for reinitialize");
               when others => Report.Failed ("Unexpected result for" &
                                  " reinitialize:" &
                                  Integer'Image (CXC7003_0.Last_Finalized));
            end case;

            -- let the task terminate
            Check_It.Ok_To_Terminate;
   
        exception
            when Not_Supported_Error => raise;
            when others => Report.Failed ("Unexpected exception (1)");
        end;
      exception
         when Not_Supported_Error => raise;
         when others => Report.Failed ("Unexpected exception (2)");
      end;
   exception
      when Not_Supported_Error => 
         null; -- Not Supported already reported.
      when Info:others => 
         -- This handler should be reachable only for exceptions raised
         -- during the instantiation of task attributes.
         Report.Not_Applicable("System not capable of supporting a task " &
                               "attribute of a controlled type -- exception " &
                               "during instantiation");
         if Verbose then
               Report.Comment ("Exception raised was" &
                               Ada.Exceptions.Exception_Name(Info));
         end if;
   end;

   Report.Result;
end CXC7003;
