

     --==================================================================--


package body CXC3002_1 is

   procedure Find_Reserved_Interrupt
     (Found  : out Boolean;
      Int_ID : out Ada.Interrupts.Interrupt_ID) is
   begin
      Found  := False;
      Int_ID := Ada.Interrupts.Interrupt_ID'First;
      for I in Ada.Interrupts.Interrupt_ID loop
         if Ada.Interrupts.Is_Reserved(I) then
            Int_ID := I;
            Found  := True;
            exit;
         end if;
      end loop;
   end Find_Reserved_Interrupt;

begin -- CXC3002_1.
   Find_Reserved_Interrupt (Reserved_Interrupt_Found, ID);
end CXC3002_1;
