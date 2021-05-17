 -- Task_Pkg;


          --========================================================--


with Report;
with ImpDef;
with C940002_0,
  -- Semaphores, 
     C940002_1;
  -- Task_Pkg;

procedure C940002 is

  package Semaphores renames C940002_0;
  package Task_Pkg renames C940002_1;

  Ptr1,
  Ptr2, 
  Ptr3 : Task_Pkg.Task_Ptr;
  Num  : Integer;

  procedure Spinlock is
    begin
      -- loop until unlocked
      while Task_Pkg.Hold_Lock.Locked loop
        delay ImpDef.Minimum_Task_Switch;   
      end loop;
      Task_Pkg.Hold_Lock.Lock;
    end Spinlock;

begin

  Report.Test ("C940002", "Check that a protected record can be used to " &
                          "control access to resources");

  if (Task_Pkg.Counter.Number /=0)
  or (Semaphores.Resource.Available /= 2) then
    Report.Failed ("Wrong initial conditions");
  end if;
                                  
  Ptr1 := new Task_Pkg.Requesting_Task;   -- newly allocated task requests 
                                   -- resource; request for resource should 
                                   -- be granted
  Spinlock;                        -- ensure that task obtains resource

                                   -- Task 1 waiting for call to Done
                                   -- One resource assigned to task 1
                                   -- One resource still available
  if (Task_Pkg.Counter.Number /= 1) 
  or (Semaphores.Resource.Available /= 1) then
    Report.Failed ("Resource not assigned to task 1");
  end if;

  Ptr2 := new Task_Pkg.Requesting_Task;   -- newly allocated task requests 
                                   -- resource; request for resource should 
                                   -- be granted
  Spinlock;                        -- ensure that task obtains resource  

                                   -- Task 1 waiting for call to Done
                                   -- Task 2 waiting for call to Done
                                   -- Resources held by tasks 1 and 2
                                   -- No resources available
  if (Task_Pkg.Counter.Number /= 2) 
  or (Semaphores.Resource.Available /= 0) then
    Report.Failed ("Resource not assigned to task 2");
  end if;

  Ptr3 := new Task_Pkg.Requesting_Task;   -- newly allocated task requests 
                                   -- resource; request for resource should 
                                   -- be denied and task queued to wait for 
                                   -- next available resource


  Ptr1.all.Done;                   -- Task 1 releases resource and lock
                                   -- Resource should be given to queued task
  Spinlock;                        -- ensure that resource is released


                                   -- Task 1 holds no resource
                                   -- One resource still assigned to task 2
                                   -- One resource assigned to task 3
                                   -- No resources available
  if (Task_Pkg.Counter.Number /= 2) 
  or (Semaphores.Resource.Available /= 0) then
    Report.Failed ("Resource not properly released/assigned to task 3");
  end if;

  Ptr2.all.Done;                   -- Task 2 releases resource and lock
                                   -- No outstanding request for resource

                                   -- Tasks 1 and 2 hold no resources
                                   -- One resource assigned to task 3
                                   -- One resource available
  if (Task_Pkg.Counter.Number /= 1)
  or (Semaphores.Resource.Available /= 1) then 
    Report.Failed ("Resource not properly released from task 2");
  end if;

  Ptr3.all.Done;                   -- Task 3 releases resource and lock

                                   -- All resources released
                                   -- All tasks terminated (or close)
                                   -- Two resources available
  if (Task_Pkg.Counter.Number /=0) 
  or (Semaphores.Resource.Available /= 2) then 
    Report.Failed ("Resource not properly released from task 3");
  end if;

  Report.Result;

end C940002;
