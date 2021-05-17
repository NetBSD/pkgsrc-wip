

     --==================================================================--


with Report;
package body CXC3005_1 is

   procedure Find_Reserved_Interrupt                -- Check all values of
     (Found : out Boolean;                          -- type Interrupt_ID for
      ID    : out Ada.Interrupts.Interrupt_ID) is   -- a reserved interrupt.
   begin                                            -- If one is found, exit
      Found := False;                               -- the loop and return
      ID    := Ada.Interrupts.Interrupt_ID'First;   -- True for Found.
      for I in Ada.Interrupts.Interrupt_ID loop     -- Otherwise return False
         if Ada.Interrupts.Is_Reserved(I) then      -- for Found.
            ID    := I;
            Found := True;
            exit;
         end if;
      end loop;
   end Find_Reserved_Interrupt;


   procedure Avoid_Optimization
     (ID: in out Ada.Interrupts.Interrupt_ID) is
   begin
      -- Condition is always false:
      if not Report.Equal (Report.Ident_Int(Dummy), Dummy) then
         ID := Ada.Interrupts.Interrupt_ID'Last;         -- Never executed.
      end if;
   end Avoid_Optimization;


   procedure Avoid_Optimization
     (ID: in out Ada.Interrupts.Parameterless_Handler) is
   begin
      -- Condition is always false:
      if not Report.Equal (Report.Ident_Int(Dummy), Dummy) then
         ID := null;                                     -- Never executed.
      end if;
   end Avoid_Optimization;


begin -- CXC3005_1.
   Find_Reserved_Interrupt (Reserved_Interrupt_Found, Reserved_Interrupt);
end CXC3005_1;
