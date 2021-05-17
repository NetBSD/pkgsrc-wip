

with System;
with Report;
package BXD1002_2 is
  protected Shared_Counter is                 
    pragma Priority (12.7);                                       -- ERROR:
                 -- expression in a priority pragma must be of type Integer
    procedure Increment;
  private
    The_Counter : Integer := 2;
  end Shared_Counter;
 
  protected type Resource is
    pragma Interrupt_Priority (True);                             -- ERROR:
      -- expression in an interrupt_priority pragma must be of type Integer
    entry Sieze;
    procedure Release;
  private
    Busy : Boolean := False;
  end Resource;

  type Not_Integer is range 0 .. 100;
  NI : constant Not_Integer := 20;

  task type The_Task is
    pragma Priority (NI);                                         -- ERROR:
                 -- expression in a priority pragma must be of type Integer
  end The_Task;


  protected Shared_Counter_2 is                 
    pragma Priority (Report.Ident_Int(System.Priority'First));       -- OK.
    procedure Increment;
  private
    The_Counter : Integer := 2;
  end Shared_Counter_2;
 
  protected type Resource_2 is
    pragma Interrupt_Priority 
         (Report.Ident_Int(System.Interrupt_Priority'First))   ;     -- OK.
    entry Sieze;
    procedure Release;
  private
    Busy : Boolean := False;
  end Resource_2;

  task type Helper_1 is
    pragma Priority (Report.Ident_Int(System.Priority'Last));        -- OK.
    entry Start_Work;
  end Helper_1;

  task type Helper_2 is
    pragma Interrupt_Priority 
       (Report.Ident_Int(System.Interrupt_Priority'Last));           -- OK.
    entry Start_Work;
  end Helper_2;

  task type Helper_3 is
    -- Note D.1(17);6.0 allows any priority value to be used in
    -- an interrupt_priority pragma in a task_definition.
    pragma Interrupt_Priority (System.Any_Priority'First);           -- OK.
  end Helper_3;


  -- check the use of discrimnants in setting the priority

  protected type Has_Priority_Disc_1 (Pr : Integer := 3) is
    pragma Priority (Pr);                                            -- OK.
    procedure Twiddle;
  end Has_Priority_Disc_1;

  HPD1 : Has_Priority_Disc_1 (System.Priority'Last);

  protected type Has_Priority_Disc_2 (Pr : Integer := -3) is
    pragma Interrupt_Priority (Pr);                                  -- OK.
    procedure Twiddle;
  end Has_Priority_Disc_2;

  HPD2 : Has_Priority_Disc_2 (System.Interrupt_Priority'Last);

  task type Has_Priority_Disc_3 (Pr : Integer) is
    pragma Priority (Pr);                                            -- OK.
  end Has_Priority_Disc_3;
  HPD3 : Has_Priority_Disc_3 (System.Any_Priority'First); 

  task type Has_Priority_Disc_4 (Pr : Integer) is
    pragma Interrupt_Priority (Pr);                                  -- OK.
  end Has_Priority_Disc_4;
  HPD4 : Has_Priority_Disc_4 (System.Any_Priority'Last); 
end BXD1002_2;
