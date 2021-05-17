
with Report;
with Ada.Task_Identification;
pragma Elaborate_All (Ada.Task_Identification);
package body CXC7004_0 is

    -- This package represents the pre-packaged subprogram library.

    Environment_Task_Id : constant Ada.Task_Identification.Task_ID :=
       Ada.Task_Identification.Current_Task;

    task Processor is
        entry Operation (Caller_Id : out Ada.Task_Identification.Task_ID);
    end Processor;

    task body Processor is
        -- Emulates an active processing task.
        Main_Terminated : Boolean := False;
       Any_Calls_of_Operation : Boolean := False;
    begin
       for I in 1 .. 60 loop
          -- Note: We use a for loop here so the test will terminate if
          -- Is_Callable fails. In a real application, this would be
          -- an unconditional, infinite loop.
          select
             accept Operation (Caller_Id : out Ada.Task_Identification.Task_ID) do
                Caller_Id := Operation'Caller;
                Any_Calls_of_Operation := True;
                -- A real application would do the processing for
                -- "Operation" here.
                Report.Comment ("Operation called");
             end Operation;
          or
             delay 1.0;
                -- A real application would do needed background processing
                -- here. For instance, a GUI might check for messages here.
          end select;

          -- Check if the main subprogram is waiting for tasks to terminate.
          if not Ada.Task_Identification.Is_Callable (Environment_Task_Id)
          then
             -- The main subprogram has exited. Exit this task.
             Main_Terminated := True;
             Report.Comment ("Is_Callable (Environment_Task) is False");
             exit;
          end if;

       end loop;

       if not Main_Terminated then
          -- Is_Callable has not gone False after 50 seconds. But Is_Callable
          -- must go False when the main subprogram starts waiting for tasks.
          Report.Failed ("Is_Callable (Environment_Task) never became False");
       elsif not Any_Calls_of_Operation then
          -- Is_Callable was False before Operation was called. But the main
          -- subprogram was still running at that point.
          Report.Failed ("Is_Callable (Environment_Task) is False while the " &
                         "environment task is running");
       end if;

       Report.Result;

    end Processor;


    protected Could_Have_Been_a_Lock is
       -- We're using this object to test 'Caller in a protected entry.
       entry Get_Lock (Caller_Id : out Ada.Task_Identification.Task_ID);
    end Could_Have_Been_a_Lock;


    protected body Could_Have_Been_a_Lock is
       entry Get_Lock (Caller_Id : out Ada.Task_Identification.Task_ID) when True is
       begin
          Caller_Id := Get_Lock'Caller;
       end Get_Lock;
    end Could_Have_Been_a_Lock;


    procedure Operate_On_It (A : in out Integer) is
        -- An operation requiring the use of the (internal) task.
       use type Ada.Task_Identification.Task_Id;
       Task_Caller_Id : Ada.Task_Identification.Task_ID;
       Processor_Task_Id : Ada.Task_Identification.Task_ID;
       PT_Caller_Id : Ada.Task_Identification.Task_ID;
       My_Caller_Id : Ada.Task_Identification.Task_ID;
    begin
       -- Have the task do the operation:
       select
          Processor.Operation (Task_Caller_Id);
       or
          delay 15.0; return; -- Processor terminated prematurely.
       end select;

       -- Check that the various ways to get a task_id all have the
       -- same result:
       Processor_Task_Id := Processor'Identity;
       Could_Have_Been_a_Lock.Get_Lock (PT_Caller_Id);
       My_Caller_Id := Ada.Task_Identification.Current_Task;
       if My_Caller_Id = Processor_Task_Id then
          Report.Failed ("Environment Task Id not correctly returned");
       end if;
       if My_Caller_Id /= Environment_Task_Id then
          Report.Failed ("Environment Task Id not correctly returned at" &
                         " elaboration");
       end if;
       if My_Caller_Id /= Task_Caller_Id then
          Report.Failed ("Task entry Caller not correctly returned");
       end if;
       if My_Caller_Id /= PT_Caller_Id then
          Report.Failed ("Protected object entry Caller not correctly" &
                         " returned");
       end if;

       -- Set the result:
       A := A ** 2;
    end Operate_On_It;

end CXC7004_0;
