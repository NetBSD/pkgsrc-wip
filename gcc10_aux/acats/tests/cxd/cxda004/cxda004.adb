
------------------------------------------------------------------

with Ada.Synchronous_Task_Control;
with Ada.Interrupts;
with System;
with Report;
with ImpDef;
with ImpDef.Annex_C;
with CXDA004_1;
procedure CXDA004 is
   Verbose : constant Boolean := CXDA004_1.Verbose;
   In_Suspension : Boolean := False;
   pragma Volatile (In_Suspension);
   package STC renames Ada.Synchronous_Task_Control;
   Check_SO : STC.Suspension_Object;

   procedure Check_For_Ref (S : in out STC.Suspension_Object) is
      -- this procedure is called with Check_SO as a parameter
   begin
     STC.Set_True (S);
     if not STC.Current_State (Check_SO) then
       Report.Failed ("Suspension_Object is not a by-reference type (1)");
     end if;
     STC.Set_False (S);
     if STC.Current_State (Check_SO) then
       Report.Failed ("Suspension_Object is not a by-reference type (2)");
     end if;
   end Check_For_Ref;

begin

   Report.Test ("CXDA004", "Check that a suspension_object can be changed" &
                           " by an interrupt handler");
   
   declare -- encapsulate the test
      task Does_Suspension is
	 entry Do_PE_Test;
         entry Do_Int_Test;
      end Does_Suspension;


      task body Does_Suspension is 
      begin
	 accept Do_PE_Test;
	 STC.Suspend_Until_True (Check_SO);

         accept Do_Int_Test;
         -- time to wait
         In_Suspension := True;
         STC.Suspend_Until_True (CXDA004_1.SO);
         In_Suspension := False;
      exception
         when others =>
               Report.Failed ("Unexpected Exception in Does_Suspension");
      end Does_Suspension; 


   begin
      -- the test for suspension objects being passed by reference
      Check_For_Ref (Check_SO);     

      -- check for program_error if a suspend_until_true is done on a 
      -- suspension object that already has a task waiting on it.
      STC.Set_False (Check_SO);
      Does_Suspension.Do_PE_Test;
      delay Impdef.Switch_To_New_Task;   -- let Does_Suspension suspend
      begin
	 STC.Suspend_Until_True (Check_SO);
	 Report.Failed ("no exception on double suspend");
      exception
	 when Program_Error =>
		 if Verbose then
		    Report.Comment ("exception properly raised");
		 end if;
	 when others =>
		 Report.Failed ("wrong exception on double suspend");
      end;
      STC.Set_True (Check_SO);  -- let Does_Suspension continue

 
      -- interrupt test
      STC.Set_False (CXDA004_1.SO);
      Does_Suspension.Do_Int_Test;
      delay Impdef.Switch_To_New_Task;  -- to allow Does_Suspension to block
      ImpDef.Annex_C.Enable_Interrupts;
      ImpDef.Annex_C.Generate_Interrupt;

      delay ImpDef.Annex_C.Wait_For_Interrupt;

      if In_Suspension then
         Report.Failed ("Task was not unblocked");
         abort Does_Suspension;  -- so test will terminate
      end if;

      if CXDA004_1.Interrupt_Count = 0 then
         Report.Failed ("interrupt never occurred");
      else
         if Verbose then
            Report.Comment ("interrupt count is" & 
                  Integer'Image (CXDA004_1.Interrupt_Count));
         end if;
      end if;

   exception
      when others =>
         Report.Failed ("Unexpected Exception in main procedure");
   end;  -- encapsulation

   Report.Result;

end CXDA004;
