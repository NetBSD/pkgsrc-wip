
     --=================================================================--

with Report;

package body CB20005_0 is               -- Package Semaphore.

   protected body Counting_Semaphore is

      procedure Secure is
      begin
         if (Count = 0) then               -- No resources left to secure.
            raise Resource_Underflow;      
            Report.Failed 
              ("Program control not transferred by raise in Secure");
         else
            Count := Count - 1;             -- Avail resources decremented.
         end if;                          
      exception
         when Resource_Underflow =>         -- Exception handled locally in
            Handled_In_Procedure := True;   -- this protected operation.
         when others =>
            Report.Failed ("Unexpected exception raised in Secure");
      end Secure;


      function Resource_Limit_Exceeded return Boolean is
      begin
         if (Count > Max_Resources) then   
            raise Resource_Overflow;       -- Exception used as control flow
                                           -- mechanism.
            Report.Failed 
              ("Program control not transferred by raise in " &
               "Resource_Limit_Exceeded");
         else                              
            return (False);
         end if;
      exception
         when Resource_Overflow =>         -- Handle its own raised
            Handled_In_Function := True;   -- exception.
            return (True);                 
         when others =>
            Report.Failed 
              ("Unexpected exception raised in Resource_Limit_Exceeded");
      end Resource_Limit_Exceeded;


      procedure Release is
      begin
         Count := Count + 1;               -- Count of resources available 
                                           -- incremented.
         if Resource_Limit_Exceeded then   -- Call to protected operation
            Count := Count - 1;            -- function that raises/handles
         end if;                           -- an exception.
      exception
         when Resource_Overflow =>
            Handled_In_Function := False;
            Report.Failed ("Exception propagated to Function Release");
         when others =>
            Report.Failed ("Unexpected exception raised in Function Release");
      end Release;


   end Counting_Semaphore;

end CB20005_0;
