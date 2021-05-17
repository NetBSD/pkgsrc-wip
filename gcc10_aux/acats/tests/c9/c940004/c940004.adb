
--==========================================================--

with Report;
with ImpDef;

with C940004_0; -- Resource_Pkg,
with C940004_2; -- Printer_Mgr_Pkg,
with C940004_3; -- User_Task_Pkg;

procedure C940004 is
   Verbose : constant Boolean := False;
   package Resource_Pkg    renames C940004_0;
   package Printer_Mgr_Pkg renames C940004_2;
   package User_Task_Pkg   renames C940004_3;

   Task1 : User_Task_Pkg.User_Task_Type (1);
   Task2 : User_Task_Pkg.User_Task_Type (2);
   Task3 : User_Task_Pkg.User_Task_Type (3);

   User_Rec_1,
   User_Rec_2,
   User_Rec_3 : Printer_Mgr_Pkg.Instantiation.User_Rec_Type;

begin

   Report.Test ("C940004", "Check that a protected record can be used to " &
                           "control access to resources");

   if    (User_Task_Pkg.TC_Times_Obtained /= 0)
      or (User_Task_Pkg.TC_Times_Released /= 0)
      or  Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_1)
      or  Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_2)
      or  Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_3) then
         Report.Failed ("Wrong initial conditions");
   end if;

   Task1.Get_Printer;           -- ask for resource
                                -- request for resource should be granted
   Task1.TC_Get_Descriptor (User_Rec_1);-- wait here 'til task gets resource

   if        (User_Task_Pkg.TC_Times_Obtained /= 1)
      or     (User_Task_Pkg.TC_Times_Released /= 0)
      or not Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_1) then
         Report.Failed ("Resource not assigned to task 1");
   end if;

   Task2.Get_Printer;              -- ask for resource
                                   -- request for resource should be denied
                                   -- and task queued to wait

   -- Task 1 still waiting to accept Release_Printer, still holds resource
   -- Task 2 queued on Semaphore.Request

   -- Ensure that Task2 is queued before continuing to make checks and queue
   -- Task3. We use a for loop here to avoid hangs in broken implementations.
   for TC_Cnt in 1 .. 20 loop
      exit when Printer_Mgr_Pkg.Printer_Access_Mgr.TC_Count >= 1;
      delay Impdef.Minimum_Task_Switch;
   end loop;

   if    (User_Task_Pkg.TC_Times_Obtained /= 1)
      or (User_Task_Pkg.TC_Times_Released /= 0) then
        Report.Failed ("Resource assigned to task 2");
   end if;

   Task3.Get_Printer;        -- ask for resource
                             -- request for resource should be denied
                             -- and task 3 queued on Semaphore.Request

   Task1.Release_Printer (User_Rec_1);-- task 1 releases resource
                                      -- released resource should be given to
                                      -- queued task 2.

   Task2.TC_Get_Descriptor (User_Rec_2);-- wait here for task 2

   -- Task 1 has released resource and completed
   -- Task 2 has seized the resource
   -- Task 3 is queued on Semaphore.Request

   if        (User_Task_Pkg.TC_Times_Obtained /= 2)
      or     (User_Task_Pkg.TC_Times_Released /= 1)
      or     Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_1)
      or not Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_2) then
          Report.Failed ("Resource not properly released/assigned" &
                         " to task 2");
          if Verbose then
             Report.Comment ("TC_Times_Obtained: " &
                 Integer'Image (User_Task_Pkg.TC_Times_Obtained));
             Report.Comment ("TC_Times_Released: " &
                 Integer'Image (User_Task_Pkg.TC_Times_Released));
             Report.Comment ("User 1 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_1)));
             Report.Comment ("User 2 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_2)));
          end if;
   end if;

   Task2.Release_Printer (User_Rec_2);-- task 2 releases resource

   -- task 3 is released from queue, and is given resource

   Task3.TC_Get_Descriptor (User_Rec_3);-- wait for task 3

   if        (User_Task_Pkg.TC_Times_Obtained /= 3)
      or     (User_Task_Pkg.TC_Times_Released /= 2)
      or     Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_2)
      or not Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_3) then
        Report.Failed ("Resource not properly released/assigned " &
                       "to task 3");
          if Verbose then
             Report.Comment ("TC_Times_Obtained: " &
                Integer'Image (User_Task_Pkg.TC_Times_Obtained));
             Report.Comment ("TC_Times_Released: " &
                Integer'Image (User_Task_Pkg.TC_Times_Released));
             Report.Comment ("User 1 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_1)));
             Report.Comment ("User 2 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_2)));
             Report.Comment ("User 3 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_3)));
          end if;
   end if;

   Task3.Release_Printer (User_Rec_3);-- task 3 releases resource

   if    (User_Task_Pkg.TC_Times_Obtained /=3)
      or (User_Task_Pkg.TC_Times_Released /=3)
      or Printer_Mgr_Pkg.Instantiation.Has_Access (User_Rec_3) then
         Report.Failed ("Resource not properly released by task 3");
         if Verbose then
             Report.Comment ("TC_Times_Obtained: " &
                Integer'Image (User_Task_Pkg.TC_Times_Obtained));
             Report.Comment ("TC_Times_Released: " &
                Integer'Image (User_Task_Pkg.TC_Times_Released));
             Report.Comment ("User 1 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_1)));
             Report.Comment ("User 2 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_2)));
             Report.Comment ("User 3 Has_Access:" &
                Boolean'Image (Printer_Mgr_Pkg.Instantiation.
                               Has_Access (User_Rec_3)));
         end if;

   end if;

   -- Ensure that all tasks have terminated before reporting the result
   while not (Task1'terminated
              and Task2'terminated
              and Task3'terminated) loop
      delay ImpDef.Minimum_Task_Switch;
   end loop;

   Report.Result;

end C940004;
