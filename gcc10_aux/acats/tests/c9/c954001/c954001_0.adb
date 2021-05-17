

     --==================================================================--


package body C954001_0 is  -- Disk management abstraction.


   protected body Disk_Device is

      entry Read (Where : Disk_Address; Data : out Disk_Buffer)
        when not Operation_Pending is
      begin
         if (Where.Track = Current_Track) then      -- If the head is over the
            -- Read data from disk...               -- requested track, read
            null;                                   -- the data.

         else                                       -- Otherwise, defer read
            Operation_Pending := True;              -- while head is moved to
                                                    -- correct track (signaled
            --                        --            -- by a disk interrupt).
            -- Requeue is tested here --
            --                        --

            requeue Pending_Read;                  

         end if;
      end Read;


      procedure Disk_Interrupt is                   -- Called when the disk
      begin                                         -- interrupts, indicating
         Disk_Interrupted := True;                  -- that the head is over
      end Disk_Interrupt;                           -- the correct track.


      function TC_Track return Disk_Track is        -- Artifice required for
      begin                                         -- testing purposes.
         return (Current_Track);
      end TC_Track;


      entry Pending_Read (Where : Disk_Address; Data : out Disk_Buffer)
        when Disk_Interrupted is
      begin
         Current_Track := Where.Track;              -- Head is now over the
         -- Read data from disk...                  -- correct track; read
         Operation_Pending := False;                -- the data.
         Disk_Interrupted := False;
      end Pending_Read;

      function TC_Pending_Queued return Boolean is
      begin
         -- Return true when there is something on the Pending_Read queue
         return (Pending_Read'Count /=0);   
      end TC_Pending_Queued;

   end Disk_Device;


end C954001_0;
