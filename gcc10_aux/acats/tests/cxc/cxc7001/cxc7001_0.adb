
--------------------------------------------------------------------------

with Report;
package body CXC7001_0 is
  use type Ada.Task_Identification.Task_ID;

  task body Task_Type is
     Who_I_Am : Ada.Task_Identification.Task_ID
              := Ada.Task_Identification.Current_Task;
  begin
    loop
      select
        accept Check_Caller(ID: in Ada.Task_Identification.Task_ID) do
             if ID /= Check_Caller'Caller then
               Report.Failed("The caller is not the caller");
             end if;
           end Check_Caller;

        or accept My_ID(ID: out Ada.Task_Identification.Task_ID) do
             ID := Who_I_Am;
           end My_ID;

        or accept Shutdown;
           exit;

        or terminate;  -- don't hold up the test
      end select;
    end loop;
  end Task_Type;

end CXC7001_0;
