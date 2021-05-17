

     --==================================================================--


with Ada.Interrupts;
pragma Elaborate (Ada.Interrupts);

package CXC3005_1 is

   Dummy                    : Integer := 0;

   Reserved_Interrupt_Found : Boolean := False;
   Reserved_Interrupt       : Ada.Interrupts.Interrupt_ID;

   procedure Find_Reserved_Interrupt
     (Found : out Boolean;
      ID    : out Ada.Interrupts.Interrupt_ID);

   procedure Avoid_Optimization
     (ID: in out Ada.Interrupts.Interrupt_ID);

   procedure Avoid_Optimization
     (ID: in out Ada.Interrupts.Parameterless_Handler);

end CXC3005_1;
