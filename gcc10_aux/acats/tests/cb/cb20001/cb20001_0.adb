

     --=================================================================--


package body CB20001_0 is


   task body Submarine_Type is
   begin
      loop

         Task_Block:
         begin
            select
               accept Contact (Location : in Location_Type) do
                  if Location > 1000 then
                     raise Off_Screen_Data;
                  elsif (Location > 500) and (Location <= 1000) then
                     raise Location_Error;
                  elsif (Location > 100) and (Location <= 500) then
                     raise Incorrect_Data;
                  else
                     Current_Position := Location;
                  end if;
               exception
                  when Off_Screen_Data =>
                     TC_Handled_In_Accept := True;
                  when Location_Error =>
                     TC_Reraised_In_Accept := True;
                     raise;   -- Reraise the Location_Error exception
                              -- in the task block.
               end Contact;
            or
               terminate;
            end select;

         exception

            when Off_Screen_Data =>
                TC_Handled_In_Accept := False;
                Report.Failed ("Off_Screen_Data exception " &
                               "improperly handled in task block");

            when Location_Error =>
                TC_Handled_In_Task_Block := True;
         end Task_Block;

      end loop;

   exception

      when Location_Error | Off_Screen_Data =>
         TC_Handled_In_Accept := False;
         TC_Handled_In_Task_Block := False;
         Report.Failed ("Exception improperly propagated out to task body"); 
      when others =>
         null;
   end Submarine_Type;

end CB20001_0;
