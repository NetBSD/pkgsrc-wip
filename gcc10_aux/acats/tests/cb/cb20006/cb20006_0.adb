
     --=================================================================--

with Report;

package body CB20006_0 is                 -- Package Semaphore.

   protected body Counting_Semaphore is

      procedure Secure is
      begin
         if (Count = 0) then              -- No resources left to secure.
            raise Resource_Underflow;      
            Report.Failed 
              ("Program control not transferred by raise in Procedure Secure");
         else
            Count := Count - 1;           -- Available resources decremented.
         end if;                          
      exception
         when Resource_Underflow =>
            Reraised_In_Procedure := True; 
            raise;                        -- Exception propagated to caller.
            Report.Failed ("Exception not propagated to caller from Secure");
         when others =>
            Report.Failed ("Unexpected exception raised in Secure");
      end Secure;


      function Resource_Limit_Exceeded return Boolean is
      begin
         if (Count > Max_Resources) then   
            raise Resource_Overflow;      -- Exception used as control flow
                                          -- mechanism.
            Report.Failed 
              ("Specific raise did not alter program control" &
               " from Resource_Limit_Exceeded");
         else                              
            return (False);
         end if;
      exception
         when others =>
            Reraised_In_Function := True; 
            raise;                         -- Exception propagated to caller.
            Report.Failed ("Exception not propagated to caller" & 
                           " from Resource_Limit_Exceeded");
      end Resource_Limit_Exceeded;


      procedure Release is
      begin
         Count := Count + 1;               -- Count of resources available 
                                           -- incremented.
         if Resource_Limit_Exceeded then   -- Call to protected operation
            Count := Count - 1;            -- function that raises/reraises
                                           -- an exception.
            Report.Failed("Resource limit exceeded");
         end if;                          

      exception
         when others =>
            raise;                         -- Reraised and propagated again.
             Report.Failed ("Exception not reraised by procedure Release");
      end Release;


   end Counting_Semaphore;

end CB20006_0;
