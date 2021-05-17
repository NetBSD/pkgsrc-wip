
------------------------------------------------------------------- CB40005

with Report;
with TCTouch;
with CB40005_0;
with Ada.Exceptions;
procedure CB40005 is

  type Proc_Pointer is access procedure;
  type Func_Pointer is access function return Proc_Pointer;

  package Fail_Soft is new CB40005_0(Proc_Pointer, Func_Pointer);

  procedure Cause_Standard_Exception;

  procedure Cause_Visible_Exception;

  procedure Cause_Invisible_Exception;

  Exception_Procedure_Pointer : Proc_Pointer;

  Visible_Exception : exception;

  procedure Action_On_Exception;

  function Retry_Procedure return Proc_Pointer;

  Raise_Error : Boolean;

  use type Ada.Exceptions.Exception_Occurrence_Access; -- Make "=" visible.

  -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

  procedure Cause_Standard_Exception is
  begin
    TCTouch.Touch('S');  --------------------------------------------------- S
    if Raise_Error then
      raise Constraint_Error;
    end if;
  end Cause_Standard_Exception;

  procedure Cause_Visible_Exception is
  begin
    TCTouch.Touch('V');  --------------------------------------------------- V
    if Raise_Error then
      raise Visible_Exception;
    end if;
  end Cause_Visible_Exception;

  procedure Cause_Invisible_Exception is
    Invisible_Exception : exception;
  begin
    TCTouch.Touch('I');  --------------------------------------------------- I
    if Raise_Error then
      raise Invisible_Exception;
    end if;
  end Cause_Invisible_Exception;

  procedure Action_On_Exception is
  begin
    TCTouch.Touch('A');  --------------------------------------------------- A
  end Action_On_Exception;

  function Retry_Procedure return Proc_Pointer is
  begin
    TCTouch.Touch('R');  --------------------------------------------------- R
    return Action_On_Exception'Access;
  end Retry_Procedure;

         -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

begin  -- Main test procedure.

  Report.Test ("CB40005", "Check that exceptions raised in non-generic " &
                          "code can be handled by a procedure in a generic " &
                          "package.  Check that the exception identity can " &
                          "be properly retrieved from the generic code and " &
                          "used by the non-generic code" );

  -- first, check that the no exception cases cause no action on the stack
  Raise_Error := False;

  Fail_Soft.Fail_Soft_Call( Cause_Standard_Exception'Access );    -- S

  Fail_Soft.Fail_Soft_Call( Cause_Visible_Exception'Access,       -- V
                            Action_On_Exception'Access,
                            Retry_Procedure'Access );

  Fail_Soft.Fail_Soft_Call( Cause_Invisible_Exception'Access,     -- I
                            null,
                            Retry_Procedure'Access );

  TCTouch.Assert( Fail_Soft.Event_Stack_Size = 0, "Empty stack");

  TCTouch.Validate( "SVI", "Non error case check" );

  -- second, check that error cases add to the stack
  Raise_Error := True;

  Fail_Soft.Fail_Soft_Call( Cause_Standard_Exception'Access );    -- S

  Fail_Soft.Fail_Soft_Call( Cause_Visible_Exception'Access,       -- V
                            Action_On_Exception'Access,           -- A
                            Retry_Procedure'Access );             -- RA

  Fail_Soft.Fail_Soft_Call( Cause_Invisible_Exception'Access,     -- I
                            null,
                            Retry_Procedure'Access );             -- RA

  TCTouch.Assert( Fail_Soft.Event_Stack_Size = 3, "Stack = 3");

  TCTouch.Validate( "SVARAIRA", "Error case check" );

  -- check that the exceptions and procedure were stored correctly
  -- on the stack
  Raise_Error := False;

  -- return procedure pointer from top of stack and call the procedure
  -- through that pointer:

  Fail_Soft.Top_Event_Procedure.all;

  TCTouch.Validate( "I", "Invisible case unwind" );

  declare
    Top_Exception : constant Ada.Exceptions.Exception_Occurrence_Access :=
      Fail_Soft.Top_Event_Exception;
  begin
    if Top_Exception = null then
       Report.Failed("1: Exception missing");
    else
      Ada.Exceptions.Raise_Exception(
        Ada.Exceptions.Exception_Identity(Top_Exception.all));
      Report.Failed("1: Exception not raised");
    end if;
  exception
    when Constraint_Error  => Report.Failed("1: Raised Constraint_Error");
    when Visible_Exception => Report.Failed("1: Raised Visible_Exception");
    when others            => null; -- expected case
  end;

  Fail_Soft.Pop_Event;

  -- return procedure pointer from top of stack and call the procedure
  -- through that pointer:

  Fail_Soft.Top_Event_Procedure.all;

  TCTouch.Validate( "V", "Visible case unwind" );

  declare
    Top_Exception : constant Ada.Exceptions.Exception_Occurrence_Access :=
      Fail_Soft.Top_Event_Exception;
  begin
    if Top_Exception = null then
       Report.Failed("2: Exception missing");
    else
      Ada.Exceptions.Raise_Exception(
        Ada.Exceptions.Exception_Identity(Top_Exception.all));
      Report.Failed("2: Exception not raised");
    end if;
  exception
    when Constraint_Error  => Report.Failed("2: Raised Constraint_Error");
    when Visible_Exception => null; -- expected case
    when others            => Report.Failed("2: Raised Invisible_Exception");
  end;

  Fail_Soft.Pop_Event;

  Fail_Soft.Top_Event_Procedure.all;

  TCTouch.Validate( "S", "Standard case unwind" );

  declare
    Top_Exception : constant Ada.Exceptions.Exception_Occurrence_Access :=
      Fail_Soft.Top_Event_Exception;
  begin
    if Top_Exception = null then
       Report.Failed("3: Exception missing");
    else
      Ada.Exceptions.Raise_Exception(
        Ada.Exceptions.Exception_Identity(Top_Exception.all));
      Report.Failed("3: Exception not raised");
    end if;
  exception
    when Constraint_Error  => null; -- expected case
    when Visible_Exception => Report.Failed("3: Raised Visible_Exception");
    when others            => Report.Failed("3: Raised Invisible_Exception");
  end;

  Fail_Soft.Pop_Event;

  TCTouch.Assert( Fail_Soft.Event_Stack_Size = 0, "Stack empty after pops");

  Report.Result;

end CB40005;
