

     --=================================================================--


with CB20001_0;       
with Report;
with ImpDef;

procedure CB20001 is

   package Submarine_Tracking renames CB20001_0;

   Trident       : Submarine_Tracking.Submarine_Type;   -- Declare task
   Sonar_Contact : Submarine_Tracking.Location_Type;

   TC_LEB_Error,
   TC_Main_Handler_Used : Boolean := False;

begin

   Report.Test ("CB20001", "Check that exceptions can be handled " &
                           "in accept bodies");


   Off_Screen_Block:
   begin
      Sonar_Contact := 1500;
      Trident.Contact (Sonar_Contact);  -- Cause Off_Screen_Data exception
                                        -- to be raised and handled in a task 
                                        -- accept body.
   exception                            
      when Submarine_Tracking.Off_Screen_Data =>
          TC_Main_Handler_Used := True;
          Report.Failed ("Off_Screen_Data exception improperly handled " &
                         "in calling procedure");
      when others =>
          Report.Failed ("Exception handled unexpectedly in " &
                         "Off_Screen_Block");
   end Off_Screen_Block;


   Location_Error_Block:
   begin
      Sonar_Contact := 700;
      Trident.Contact (Sonar_Contact);  -- Cause Location_Error exception
                                        -- to be raised in task accept body,
                                        -- propogated to a task block, and
                                        -- handled there.  Corresponding
                                        -- exception propagated here also.
      Report.Failed ("Expected exception not raised");
   exception                            
      when Submarine_Tracking.Location_Error =>
          TC_LEB_Error := True;
      when others =>
          Report.Failed ("Exception handled unexpectedly in " &
                         "Location_Error_Block");
   end Location_Error_Block;


   Incorrect_Data_Block:
   begin
      Sonar_Contact := 200;
      Trident.Contact (Sonar_Contact);  -- Cause Incorrect_Data exception
                                        -- to be raised in task accept body,
                                        -- propogated to calling procedure.
      Report.Failed ("Expected exception not raised");
   exception                            
      when Submarine_Tracking.Incorrect_Data =>
          Submarine_Tracking.TC_Handled_In_Caller := True;
      when others =>
          Report.Failed ("Exception handled unexpectedly in " &
                         "Incorrect_Data_Block");
   end Incorrect_Data_Block;


   if TC_Main_Handler_Used or
      not (Submarine_Tracking.TC_Handled_In_Caller     and -- Check to see that
           Submarine_Tracking.TC_Handled_In_Task_Block and -- all exceptions
           Submarine_Tracking.TC_Handled_In_Accept     and -- were handled in
           Submarine_Tracking.TC_Reraised_In_Accept    and -- proper locations.
           TC_LEB_Error)       
   then                                                    
      Report.Failed ("Exceptions handled in incorrect locations");
   end if;

   if Integer(Submarine_Tracking.Current_Position) /= 0 then
      Report.Failed ("Variable incorrectly written in task processing");
   end if;

   delay ImpDef.Minimum_Task_Switch;
   if Trident'Callable then
      Report.Failed ("Task didn't terminate with exception propagation");
   end if;

   Report.Result;

end CB20001;
