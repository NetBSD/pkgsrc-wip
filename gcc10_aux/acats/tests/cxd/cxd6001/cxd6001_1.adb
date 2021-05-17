
----------------------------------------------------------

package body CXD6001_1 is

  task body Killer_Task is
    Victim : TID.Task_ID;
  begin
    loop
      select
        accept Task_To_Abort (T : in TID.Task_ID) do
           Victim := T;
        end Task_To_Abort;
      or
        terminate;
      end select;

      STC.Suspend_Until_True (Kill_Now);
      TID.Abort_Task (Victim);
    end loop;
  end Killer_Task;

end CXD6001_1;
