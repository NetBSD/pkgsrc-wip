

     --==================================================================--


with Ada.Interrupts;
pragma Elaborate (Ada.Interrupts);

package CXC3002_1 is

   Reserved_Interrupt_Found : Boolean := False;
   ID                       : Ada.Interrupts.Interrupt_ID;

   procedure Find_Reserved_Interrupt
     (Found  : out Boolean;
      Int_ID : out Ada.Interrupts.Interrupt_ID);

end CXC3002_1;
