

     --==================================================================--


with Report;
with ImpDef;

with F954A00;    -- Printer device abstraction.
with C954A01_0;  -- Printer server abstraction.

use  C954A01_0;
use  F954A00;

procedure C954A01 is

   Long_Enough : constant Duration := ImpDef.Switch_To_New_Task;

               --==============================================--

   task Print_Request;                       -- Send a print request.

   task body Print_Request is
      My_File : constant String := "MYFILE.DAT";
   begin
      Printer_Server.Print (My_File);          -- Invoke requeue statement.
      Report.Failed ("Task continued execution following entry call");
   exception
      when others =>
         Report.Failed ("Exception raised in Print_Request task");
   end Print_Request;

               --==============================================--

begin  -- Main program.

   Report.Test ("C954A01", "Requeue without abort - check that the abort " &
            "is deferred until after the rendezvous completes. (Task to PO)");

   --  To pass this test, the following must be true:
   -- 
   --     (A) The abort of Print_Request is deferred until after the
   --         Done_Printing entry body completes.
   --     (B) Print_Request aborts after the Done_Printing entry call
   --         completes.
   -- 
   --  Call the entry Verify_Results. The entry call will not be accepted
   --  until after Print_Request has been requeued to Done_Printing.

   Printer_Server.Verify_Results;           -- Accepted after Print_Request is
                                            -- requeued to Done_Printing.

   -- Simulate an application which needs access to the printer within
   -- a specified time, and which aborts the current printer job if time
   -- runs out.

   select
      Printer(1).Done_Printing;             -- Wait for printer to come free.
   or
      delay Long_Enough;                    -- Print job took too long.
      abort Print_Request;                  -- Abort print job.
   end select;

   Printer_Server.Verify_Results;           -- Abortion completion point: force
                                            -- abort to complete (if it's going
                                            -- to).

   --  Verify that the Done_Printing entry body has not yet completed,
   --  and thus that Print_Request has not been aborted.

   if Printer(1).Is_Done then
      Report.Failed ("Target entry of requeue executed prematurely");
   elsif Print_Request'Terminated then
      Report.Failed ("Caller was aborted before entry was complete");
   else

      Printer(1).Handle_Interrupt;          -- Simulate a printer interrupt,
                                            -- signaling that printing is
                                            -- done.

      --  The Done_Printing entry body will complete before the next protected
      --  action is called (Printer(1).Is_Done). Verify (A) and (B): that the
      --  Print_Request is aborted.

      Printer_Server.Verify_Results;        -- Abortion completion point: force
                                            -- Print_Request abort to complete.

      if not Printer(1).Is_Done then
         Report.Failed ("Target entry of requeue did not complete");
      end if;

      if not Print_Request'Terminated then
         Report.Failed ("Task not aborted following completion of entry call");
         abort Print_Request;               -- Try to kill hung task.
      end if;

   end if;

   Report.Result;

end C954A01;
