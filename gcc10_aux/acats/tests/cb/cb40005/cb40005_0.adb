
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- CB40005_0

with Report;
package body CB40005_0 is

  type History_Event is record
    Exception_Event  : Ada.Exceptions.Exception_Occurrence_Access;
    Procedure_Called : Proc_Pointer;
  end record;

  procedure Store_Event( Proc_Called : Proc_Pointer;
                         Error       : Ada.Exceptions.Exception_Occurrence );

  procedure Fail_Soft_Call( Proc_To_Call : Proc_Pointer;
                            Proc_To_Call_On_Exception : Proc_Pointer := null;
                            Retry_Routine : Func_Pointer := null ) is

    Current_Proc_To_Call : Proc_Pointer := Proc_To_Call;

  begin
    while Current_Proc_To_Call /= null loop
      begin
        Current_Proc_To_Call.all;  -- call procedure through pointer
        Current_Proc_To_Call := null;
      exception
        when Capture: others =>
          Store_Event( Current_Proc_To_Call, Capture );
          if Proc_To_Call_On_Exception /= null then
            Proc_To_Call_On_Exception.all;
          end if;
          if Retry_Routine /= null then
            Current_Proc_To_Call := Retry_Routine.all;
          else
            Current_Proc_To_Call := null;
          end if;
      end;
    end loop;
  end Fail_Soft_Call;

  Stack : array(1..10) of History_Event;  -- minimal, sufficient for testing

  Stack_Top : Natural := 0;

  procedure Store_Event( Proc_Called : Proc_Pointer;
                         Error       : Ada.Exceptions.Exception_Occurrence )
  is
  begin
    Stack_Top := Stack_Top +1;
    Stack(Stack_Top) := ( Ada.Exceptions.Save_Occurrence(Error),
                          Proc_Called );
  end Store_Event;

  function Top_Event_Exception return Ada.Exceptions.Exception_Occurrence_Access is
  begin
    if Stack_Top > 0 then
      return Stack(Stack_Top).Exception_Event;
    else
      return null;
    end if;
  end Top_Event_Exception;

  function Top_Event_Procedure return Proc_Pointer is
  begin
    if Stack_Top > 0 then
      return Stack(Stack_Top).Procedure_Called;
    else
      return null;
    end if;
  end Top_Event_Procedure;

  procedure Pop_Event is
  begin
    if Stack_Top > 0 then
      Stack_Top := Stack_Top -1;
    else
      Report.Failed("Stack Error");
    end if;
  end Pop_Event;

  function Event_Stack_Size return Natural is
  begin
    return Stack_Top;
  end Event_Stack_Size;

end CB40005_0;
