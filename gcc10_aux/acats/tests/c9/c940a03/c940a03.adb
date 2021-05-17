 -- Task_Pkg

--=========================================================--

with Report;
with ImpDef;
with C940A03_1;   -- Semaphores, 
with C940A03_2;   -- Task_Pkg,
with F940A00;     -- Interlock_Foundation;

procedure C940A03 is

  package Semaphores renames C940A03_1;
  package Users      renames C940A03_2;  

  Task1, Task2, Task3 : Users.User_Task_Type;
  User_Rec            : Semaphores.Login_Record_Type;

begin      -- Tasks start here

  Report.Test ("C940A03", "Check that a protected object can coordinate " &
                          "shared data access using procedure parameters");

  if F940A00.Counter.Number /=0 then
    Report.Failed ("Wrong initial conditions");
  end if;
                                 
  Task1.Login (1);               -- request resource; request should be granted
  Semaphores.TC_Control_Message.Consume;  
                                 -- ensure that task obtains resource by
                                 -- waiting for task to post message

                                 -- Task 1 waiting for call to Logout
                                 -- Others still available
  Task1.Get_Status (User_Rec);
  if (F940A00.Counter.Number /= 1)
  or (Semaphores.Login_Semaphore.Available /=1)
  or (Semaphores.TC_Key_Val (User_Rec) /= 1) then
    Report.Failed ("Resource not assigned to task 1");
  end if;
 
  Task2.Login (2);               -- Request for resource should be granted  
  Semaphores.TC_Control_Message.Consume;  
                                 -- ensure that task obtains resource by
                                 -- waiting for task to post message
 
  Task2.Get_Status (User_Rec);
  if (F940A00.Counter.Number /= 2)
  or (Semaphores.Login_Semaphore.Available /=0)
  or (Semaphores.TC_Key_Val (User_Rec) /= 2) then
    Report.Failed ("Resource not assigned to task 2");
  end if;
 

  Task3.Login (3);               -- request for resource should be denied
                                 -- and task queued


                                 -- Tasks 1 and 2 holds resources
                                 -- and are waiting for a call to Logout
                                 -- Task 3 is queued

  if (F940A00.Counter.Number /= 2)
  or (Semaphores.Login_Semaphore.Available /=0) then
    Report.Failed ("Resource incorrectly assigned to task 3");
  end if;

  Task1.Logout;                  -- released resource should be given to
                                 -- queued task
  Semaphores.TC_Control_Message.Consume;  
                                 -- wait for confirming message from task

                                 -- Task 1 holds no resources
                                 --   and is terminated (or will soon)
                                 -- Tasks 2 and 3 hold resources
                                 --   and are waiting for a call to Logout

  Task3.Get_Status (User_Rec);
  if (F940A00.Counter.Number /= 2)
                      or (Semaphores.Login_Semaphore.Available /=0)
                      or (Semaphores.TC_Key_Val (User_Rec) /= 3) then
    Report.Failed ("Resource not properly released/assigned to task 3");
  end if;

  Task2.Logout;                  -- no outstanding request for released
                                 -- resource
                                 -- Tasks 1 and 2 hold no resources
                                 -- Task 3 holds a resource
                                 --   and is waiting for a call to Logout

  if (F940A00.Counter.Number /= 1)
                        or (Semaphores.Login_Semaphore.Available /=1) then
    Report.Failed ("Resource not properly released from task 2");
  end if;

  Task3.Logout;

                                 -- all resources have been returned
                                 -- all tasks have terminated or will soon

  if (F940A00.Counter.Number /=0)
                          or (Semaphores.Login_Semaphore.Available /=2) then
    Report.Failed ("Resource not properly released from task 3");
  end if;

  -- Ensure all tasks have terminated before calling Result
  while not (Task1'terminated and     
             Task2'terminated and
             Task3'terminated)     loop
    delay ImpDef.Minimum_Task_Switch;   
  end loop;

  Report.Result;

end C940A03;
