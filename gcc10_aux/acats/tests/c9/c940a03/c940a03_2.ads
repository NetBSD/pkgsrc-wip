 -- Semaphores;

--=========================================================--

with C940A03_0;    -- Resource_Pkg,
with C940A03_1;    -- Semaphores;

package C940A03_2 is
     -- Task_Pkg

  package Semaphores renames C940A03_1;

  task type User_Task_Type is

     entry Login  (user_id : C940A03_0.Resource_Id_Type);
                      -- instructs the task to ask for a login
     entry Logout;    -- instructs the task to release the login
     --=======================--
     -- this entry is used to get information to verify test operation
     entry Get_Status (User_Record : out Semaphores.Login_Record_Type);

  end User_Task_Type;

end C940A03_2;
