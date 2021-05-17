 -- Task_Pkg

--=========================================================--

with Report;
with C940A03_0;   -- Resource_Pkg,
with C940A03_1;   -- Semaphores,
with F940A00;     -- Interlock_Foundation;
    
package body C940A03_2 is
          -- Task_Pkg 

  -- This task models a user requesting a login from the system
  -- For control of this test, we can ask the task to login, logout, or
  -- give us the current user record (containing login information)

  task body User_Task_Type is
    Rec  : Semaphores.Login_Record_Type;
  begin
    loop
      select
        accept Login (user_id : C940A03_0.Resource_Id_Type) do
          Rec.Id := user_id;
        end Login;

        Semaphores.Login_Semaphore.Request_Login (Rec);
                      -- request a resource; if resource is not available, 
                      -- task will be queued to wait

        --== following is test control machinery ==--
        F940A00.Counter.Increment;
        Semaphores.TC_Control_Message.Post;   
               -- after resource is obtained, post message

      or
        accept Logout do  
          Semaphores.Login_Semaphore.Release_Login;
                      -- release the resource
          --== test control machinery ==--
          F940A00.Counter.Decrement;
        end Logout;
        exit;

      or
        accept Get_Status (User_Record : out Semaphores.Login_Record_Type) do
          User_Record := Rec;
        end Get_Status;

      end select;  
    end loop;

  exception
    when others => Report.Failed ("Exception raised in model user task");
  end User_Task_Type;

end C940A03_2;
