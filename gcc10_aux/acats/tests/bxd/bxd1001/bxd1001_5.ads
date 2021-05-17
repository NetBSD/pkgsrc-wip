

with System;
package BXD1001_5 is
  pragma Interrupt_Priority (System.Interrupt_Priority'Last);     -- ERROR:
           -- a package is not one of the allowed constructs for containing
           -- a priority declaration
  task type A_Task_Type;
end BXD1001_5;
