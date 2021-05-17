
with Ada.Interrupts;
package body BXC3002 is

  protected body Type_0 is
    procedure Parameterless_Procedure_1 is
    begin null; end;
  end Type_0;

  protected body Object_2 is

    pragma Interrupt_Handler( Parameterless_Procedure_2 );        -- ERROR:
                              -- must be within protected object definition

    pragma Attach_Handler( Parameterless_Procedure_2,
                           Ada.Interrupts.Interrupt_ID'First );   -- ERROR:
                              -- must be within protected object definition

    procedure Parameterless_Procedure_2 is
    begin
      null;
    end Parameterless_Procedure_2;
  end Object_2;

  procedure Nested is
    Nested_Object : Type_0;                                       -- OK

    protected Object_X is
      procedure Parameterless_Procedure_3;
      pragma Interrupt_Handler( Parameterless_Procedure_3 );      -- ERROR:
                                            -- must be library level object

      pragma Attach_Handler( Parameterless_Procedure_3,
                             Ada.Interrupts.Interrupt_ID'First ); -- ERROR:
                                            -- must be library level object

    end Object_X;

    protected body Object_X is
      procedure Parameterless_Procedure_3 is
      begin null; end Parameterless_Procedure_3;
    end Object_X;

  begin
    Ada.Interrupts.Attach_Handler (New_Handler =>
      Nested_Object.Parameterless_Procedure_1'Access,             -- ERROR:
                      -- Accessibility error: handler must be library level
      Interrupt => Ada.Interrupts.Interrupt_ID'Last);
  end Nested;

end BXC3002;
