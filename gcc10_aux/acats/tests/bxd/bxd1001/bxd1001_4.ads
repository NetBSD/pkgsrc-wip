

with System;
package BXD1001_4 is
  task type Helper_1 is
    pragma Priority (System.Priority'Last);
    pragma Priority (System.Priority'Last);                       -- ERROR:
            -- only one priority pragma is allowed within a given construct
    entry Start_Work;
  end Helper_1;

  protected type Resource is
    pragma Interrupt_Priority (System.Interrupt_Priority'First);
    pragma Priority (System.Priority'Last);                       -- ERROR:
            -- only one priority pragma is allowed within a given construct
    entry Sieze;
    procedure Release;
  private
    Busy : Boolean := False;
  end Resource;
end BXD1001_4;
