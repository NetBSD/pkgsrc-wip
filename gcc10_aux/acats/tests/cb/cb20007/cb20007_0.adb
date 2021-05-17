
     --=================================================================--

with Report;

package body CB20007_0 is                  -- Package Semaphore.

   protected body Counting_Semaphore is

      procedure Secure is
      begin
         if (Count = 0) then               -- No resources left to secure.
            raise Resource_Underflow;      
            Report.Failed ("Program control not transferred by raise");
         else
            Count := Count - 1;            -- Available resources decremented.
         end if;                          
         -- No exception handlers here, direct propagation to calling unit.
      end Secure;


      function Resource_Limit_Exceeded return Boolean is
      begin
         if (Count > Max_Resources) then   
            raise Resource_Overflow;       -- Exception used as control flow
                                           -- mechanism.
            Report.Failed ("Program control not transferred by raise");
         else                              
            return (False);
         end if;
         -- No exception handlers here, direct propagation to calling unit.
      end Resource_Limit_Exceeded;


      procedure Release is
      begin
         Count := Count + 1;               -- Count of resources available 
                                           -- incremented.
         if Resource_Limit_Exceeded then   -- Call to protected operation
            Count := Count - 1;            -- function that raises an
                                           -- exception.
            Report.Failed("Resource limit exceeded");
         end if;                           
         -- No exception handler here for exception raised in function.
         -- Exception will propagate directly to calling unit.
      end Release;


   end Counting_Semaphore;

end CB20007_0;
