

     --==================================================================--


with Report;
with ImpDef;

with F954A00;    -- Printer device abstraction.
with C954A02_0;  -- Printer server abstraction.

use  C954A02_0;
use  F954A00;

procedure C954A02 is

   -- Length of time which simulates a very long process
   Long_Enough : constant Duration := ImpDef.Clear_Ready_Queue;

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

   Report.Test ("C954A02", "Abort a requeue on a Protected entry");

   -- To pass this test, the following must be true:
   --
   --    (A) The abort of Print_Request takes place immediately.
   --    (B) The Done_Printing entry call is canceled, and the corresponding
   --        entry body is not executed.
   --
   -- Call the entry Verify_Results. The entry call will not be accepted
   -- until after Print_Request has been requeued to Done_Printing.

   Printer_Server.Verify_Results;           -- Accepted after Print_Request is
                                            -- requeued to Done_Printing.

   -- Verify that the Done_Printing entry call has not been completed.
   --
   if Printer(1).Is_Done then
      Report.Failed ("Target entry of requeue executed prematurely");
   else

      -- Simulate an application which needs access to the printer within
      -- a specified time, and which aborts the current printer job if time
      -- runs out.

      select
         Printer(1).Done_Printing;          -- Wait for printer to come free.
      or
         delay Long_Enough;                 -- Print job took too long.
         abort Print_Request;               -- Abort print job.
      end select;

      Printer_Server.Verify_Results;        -- Abortion completion point: force
                                            -- Print_Request abort to complete.

      -- Verify (A): that Print_Request has been aborted.
      -- Note: the test will hang if the task as not been aborted
      --
      while not Print_Request'Terminated loop
         delay ImpDef.Minimum_Task_Switch;  
      end loop;

      -- Verify (B): that the Done_Printing entry call was canceled, and
      -- the corresponding entry body was not executed.
      --
      -- Set the barrier of the entry to true, then check that the entry
      -- body is not executed. If the entry call is NOT canceled, the
      -- entry body will execute when the barrier is set true.

      Printer(1).Handle_Interrupt;       -- Simulate a printer interrupt,
                                         -- signaling that printing is
                                         -- done.
      if Printer(1).Is_Done then
         Report.Failed ("Entry call was not canceled");
      end if;


   end if;


   Report.Result;

end C954A02;
