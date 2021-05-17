

     --==================================================================--


with Report;
with ImpDef;

with F954A00;    -- Printer device abstraction.
with C954A03_0;  -- Printer server abstraction.

use  C954A03_0;
use  F954A00;

procedure C954A03 is

   Long_Enough : constant Duration := ImpDef.Clear_Ready_Queue;


               --==============================================--

   Task_Completed : Boolean := False;          -- Testing flag.

   protected Interlock is                      -- Artifice for test purposes.
      entry Wait;                              -- Wait for lock to be released.
      procedure Release;                       -- Release the lock.
   private
      Locked : Boolean := True;
   end Interlock;


   protected body Interlock is

      entry Wait when not Locked is            -- Calls are queued until after
      --                                       -- Release is called.
      begin
         Task_Completed := True;               
      end Wait;

      procedure Release is                     -- Called by Print_Request.
      begin
         Locked := False;
      end Release;

   end Interlock;

               --==============================================--

   task Print_Request is                       -- Send a print request.
   end Print_Request;

   task body Print_Request is
      My_File : constant String := "MYFILE.DAT";
   begin
      Printer_Server.Print (My_File);          -- Invoke requeue statement.
      Interlock.Release;                       -- Allow main to continue.
   exception
      when others =>
         Report.Failed ("Exception raised in Print_Request task");
   end Print_Request;

               --==============================================--

begin  -- Main program.

   Report.Test ("C954A03", "Requeue from an Accept with parameters" &
                              " to a Protected Entry without parameters");

   -- To pass this test, the following must be true:
   --
   --    (A) The Print entry call made by the task Print_Request must be
   --        completed by the requeue statement.
   --    (B) Print_Request must remain blocked following the requeue.
   --    (C) Print_Request must be queued on the Done_Printing queue of
   --        Printer(1).
   --    (D) Print_Request must continue execution after Done_Printing is
   --        complete.
   --
   -- First, verify (A): that the Print entry call is complete.
   --
   -- Call the entry Verify_Results. If the requeue statement completed the
   -- entry call to Print, the entry call to Verify_Results should be
   -- accepted. Since the main will hang if this is NOT the case, make this
   -- a timed entry call.

   select
      Printer_Server.Verify_Results;        -- Accepted if requeue completed
                                            -- entry call to Print.
   or
      delay Long_Enough;                    -- Time out otherwise.
      Report.Failed ("Requeue did not complete entry call");
   end select;

   -- Now verify (B): that Print_Request remains blocked following the
   -- requeue. Also verify that Done_Printing (the entry to which
   -- Print_Request should have been queued) has not yet executed.

   if Printer(1).Is_Done then
      Report.Failed ("Target entry of requeue executed prematurely");
   elsif Print_Request'Terminated then
      Report.Failed ("Caller did not remain blocked after the requeue");
   else

      -- Verify (C): that Print_Request is queued on the
      -- Done_Printing queue of Printer(1).
      --
      -- Set the barrier for Printer(1).Done_Printing to true. Check
      -- that the Done flag is updated and that Print_Request terminates.

      Printer(1).Handle_Interrupt;             -- Simulate a printer interrupt,
                                               -- signaling that printing is
                                               -- done.

      -- The Done_Printing entry body will complete before the next
      -- protected action is called (Printer(1).Is_Done).

      if not Printer(1).Is_Done then
         Report.Failed ("Caller was not requeued on target entry");
      end if;

      -- Finally, verify (D): that Print_Request continues after Done_Printing
      -- completes.
      --
      -- After Done_Printing completes, there is a potential race condition
      -- between the main program and Print_Request. The protected object
      -- Interlock is provided to ensure that the check of whether
      -- Print_Request continued is made *after* it has had a chance to do so.
      -- The main program waits until the statement in Print_Request following
      -- the requeue-causing statement has executed, then checks to see
      -- whether Print_Request did in fact continue executing.
      --
      -- Note that the test will hang here if Print_Request does not continue
      -- executing following the completion of the requeued entry call.

      Interlock.Wait;                          -- Wait until Print_Request is
                                               -- done.
      if not Task_Completed then
         Report.Failed ("Caller remained blocked after target " &
                        "entry released");
      end if;

      -- Wait for Print_Request to finish before calling Report.Result.
      while not Print_Request'Terminated loop
         delay ImpDef.Minimum_Task_Switch;   
      end loop;                             

   end if;

   Report.Result;

end C954A03;
