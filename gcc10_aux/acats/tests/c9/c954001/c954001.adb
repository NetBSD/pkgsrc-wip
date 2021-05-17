

     --==================================================================--


with Report;
with ImpDef;

with C954001_0;  -- Disk management abstraction.
use  C954001_0;

procedure C954001 is


   task type Read_Task is        -- an unusual (but legal) declaration
   end Read_Task;
   --
   --
   task body Read_Task is
      Location : constant Disk_Address := (Track => New_Track);
      Data     :          Disk_Buffer  := (others => ' ');
   begin
      Disk_Device.Read (Location, Data);   -- Invoke requeue statement.
   exception
      when others =>
         Report.Failed ("Exception raised in task");
   end Read_Task;

               --==============================================--

begin  -- Main program.

   Report.Test ("C954001", "Requeue from an entry within a P.O. " &
                           "to a private entry within the same P.O.");


   declare

      IO_Request : Read_Task;                  -- Request a read from other
                                               -- than the current track.
                                               -- IO_Request will be requeued
                                               -- from Read to Pending_Read.
   begin

      -- To pass this test, the following must be true:
      --
      --    (A) The Read entry call made by the task IO_Request must be
      --        completed by the requeue.
      --    (B) IO_Request must remain blocked following the requeue.
      --    (C) IO_Request must be queued on the Pending_Read entry queue.
      --    (D) IO_Request must continue execution after the Pending_Read
      --        entry completes.
      --
      -- First, verify (A): that the Read entry call is complete.
      --
      -- Call a protected operation (Disk_Device.TC_Track). Since no two
      -- protected actions may proceed concurrently unless both are protected
      -- function calls, a call to a protected operation at this point can
      -- proceed only if the Read entry call is already complete.
      --
      -- Note that if Read is NOT complete, the test will likely hang here.
      --
      -- Next, verify (B): that IO_Request remains blocked following the
      -- requeue. Also verify that Pending_Read (the entry to which
      -- IO_Request should have been queued) has not yet executed.

      -- Wait until the task had made the call and the requeue has been
      -- effected.  
      while not Disk_Device.TC_Pending_Queued loop
         delay ImpDef.Minimum_Task_Switch;
      end loop;

      if Disk_Device.TC_Track /= Initial_Track then
         Report.Failed ("Target entry of requeue executed prematurely");
      elsif IO_Request'Terminated then
         Report.Failed ("Caller did not remain blocked after " &
                        "the requeue or was never requeued");
      else

         -- Verify (C): that IO_Request is queued on the
         -- Pending_Read entry queue.
         --
         -- Set the barrier for Pending_Read to true. Check that the
         -- current track is updated and that IO_Request terminates.

         Disk_Device.Disk_Interrupt;           -- Simulate a disk interrupt,
                                               -- signaling that the head is
                                               -- over the correct track.

         -- The Pending_Read entry body will complete before the next
         -- protected action is called (Disk_Device.TC_Track).

         if Disk_Device.TC_Track /= New_Track then
            Report.Failed ("Caller was not requeued on target entry");
         end if;

         -- Finally, verify (D): that Read_Task continues after Pending_Read
         -- completes.
         -- 
         -- Note that the test will hang here if Read_Task does not continue
         -- executing following the completion of the requeued entry call.

      end if;

   end;  -- We will not exit the declare block until the task completes

   Report.Result;

end C954001;
