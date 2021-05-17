-- C954001.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check that a requeue statement within an entry_body with parameters
--      may requeue the entry call to a protected entry with a subtype-
--      conformant parameter profile. Check that, if the call is queued on the
--      new entry's queue, the original caller remains blocked after the
--      requeue, but the entry_body containing the requeue is completed.
--
-- TEST DESCRIPTION:
--      Declare a protected object which simulates a disk device. Declare an
--      entry that requeues the caller to a second entry if the disk head is
--      not in the proper location, but first sets the second entry's barrier
--      to false. Declare a procedure which sets the second entry's barrier
--      to true.
--
--      Declare a task which calls the first entry such that the requeue is
--      called. This task should be queued on the second entry and remain
--      blocked, and the first entry should be complete. Call the procedure
--      which releases the second entry's queue. The second entry should
--      complete, after which the task should complete.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C954001_0 is  -- Disk management abstraction.


   -- Simulate a read-only disk device with a head that may be moved to
   -- different tracks. If a read request is issued for the current
   -- track, the request can be satisfied immediately. Otherwise, the head
   -- must be moved to the correct track, during which time the calling task
   -- is blocked. When the head reaches the correct track, the disk generates
   -- an interrupt, after which the request can be satisfied, and the
   -- calling task can proceed.

   Buffer_Size : constant := 100;

   type Disk_Buffer is new String (1 .. Buffer_Size);
   type Disk_Track  is new Natural;

   type Disk_Address is record
      Track : Disk_Track;
      -- Additional components.
   end record;

   Initial_Track : constant Disk_Track := 0;
   New_Track     : constant Disk_Track := 5;

               --==============================================--

   protected Disk_Device is

      entry Read (Where :     Disk_Address;            -- Read data from disk
                  Data  : out Disk_Buffer);            -- track.

      procedure Disk_Interrupt;                        -- Handle interrupt 
                                                       -- from disk.

      function TC_Track return Disk_Track;             -- Return current track.

      function TC_Pending_Queued return Boolean;       -- True when there is
                                                       -- an entry in queue

   private

      entry Pending_Read (Where :     Disk_Address;    -- Wait for head to 
                          Data  : out Disk_Buffer);    -- move then read data.

      Current_Track     : Disk_Track := Initial_Track; -- Current disk track.
      Operation_Pending : Boolean    := False;         -- Vis.  entry barrier.
      Disk_Interrupted  : Boolean    := False;         -- Priv. entry barrier.

   end Disk_Device;


end C954001_0;
