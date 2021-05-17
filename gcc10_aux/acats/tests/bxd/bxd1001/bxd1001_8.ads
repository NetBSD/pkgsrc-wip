
with System;
package BXD1001_8 is

  task type Helper_2 is
    pragma Interrupt_Priority (System.Interrupt_Priority'Last); -- OPTIONAL ERROR:
					-- See grading criteria.
    entry Start_Work;
  end Helper_2;

  task type Helper_3 is
    entry Start_Work;
    pragma Interrupt_Priority;          -- OPTIONAL ERROR: 
					-- See grading criteria.
  end Helper_3;
  
end BXD1001_8;
