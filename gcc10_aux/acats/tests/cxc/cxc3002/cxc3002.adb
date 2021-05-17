

     --==================================================================--


with CXC3002_0;
with CXC3002_1;

with Ada.Interrupts;

with Report;
procedure CXC3002 is

begin -- CXC3002.

   Report.Test ("CXC3002", "Check that Program_Error is raised if the " &
                "interrupt corresponding to that specified by the "     &
                "expression in pragma Attach_Handler is reserved");


   if CXC3002_1.Reserved_Interrupt_Found then

      begin
         declare
            Int_Handler : CXC3002_0.Handler_Type(CXC3002_1.ID);
         begin
            Report.Failed ("Program_Error was not raised");
         end;
      exception
         when Program_Error => -- Expected result.
            null;
         when others        =>
            Report.Failed ("Unexpected exception raised");
      end;

   else
      Report.Not_Applicable ("No reserved interrupts found");
   end if;


   Report.Result;

end CXC3002;
