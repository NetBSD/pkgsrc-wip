

with System;
procedure BXD1001_3 is
  pragma Interrupt_Priority(System.Interrupt_Priority'First);     -- ERROR:
          -- pragma Interrupt_Priority is only allowed in a task_definition
          -- or a protected_definition.
begin 
  null; 
end BXD1001_3;
