


with Report;
with Ada.Finalization;
with C940016_0;
with Ada.Unchecked_Deallocation;
with ImpDef;

procedure C940016 is
   Verbose : constant Boolean := C940016_0.Verbose;

begin
 
   Report.Test ("C940016", "Check that Unchecked_Deallocation of a" &
                           " protected object finalizes the" &
                           " protected object");

   First_Check: declare
       protected type Semaphore is
           entry Wait;
           procedure Signal;
       private
           Count : Integer := 0;
       end Semaphore;
       protected body Semaphore is
           entry Wait when Count > 0 is
           begin
               Count := Count - 1;
           end Wait;

           procedure Signal is
           begin
              Count := Count + 1;
           end Signal;
       end Semaphore;

       type pSem is access Semaphore;
       procedure Zap_Semaphore is new 
           Ada.Unchecked_Deallocation (Semaphore, pSem);
       Sem_Ptr : pSem := new Semaphore;

       -- positive confirmation that Blocker got the exception
       Ok : Boolean := False;

       task Blocker;

       task body Blocker is
       begin
           Sem_Ptr.Wait;
           Report.Failed ("Program_Error not raised in waiting task");
       exception
           when Program_Error =>
               Ok := True;
               if Verbose then
                   Report.Comment ("Blocker received Program_Error");
               end if;
           when others =>
               Report.Failed ("Wrong exception in Blocker");
       end Blocker;

   begin  -- First_Check
       -- wait for Blocker to get blocked on the semaphore
       delay ImpDef.Clear_Ready_Queue;
       Zap_Semaphore (Sem_Ptr);
       -- make sure Blocker has time to complete
       delay ImpDef.Clear_Ready_Queue * 2;
       if not Ok then
           Report.Failed ("finalization not properly performed");
           -- Blocker is probably hung so kill it
           abort Blocker;
       end if;
   end First_Check;
 

   Second_Check : declare
      -- here we want to check that the raising of Program_Error
      -- occurs before the other finalization actions.
       protected type Semaphore is
           entry Wait;
           procedure Signal;
       private
           Count : Integer := 0;
           Component : C940016_0.Has_Finalization;
       end Semaphore;
       protected body Semaphore is
           entry Wait when Count > 0 is
           begin
               Count := Count - 1;
           end Wait;

           procedure Signal is
           begin
              Count := Count + 1;
           end Signal;
       end Semaphore;

       type pSem is access Semaphore;
       procedure Zap_Semaphore is new 
           Ada.Unchecked_Deallocation (Semaphore, pSem);
       Sem_Ptr : pSem := new Semaphore;

       -- positive confirmation that Blocker got the exception
       Ok : Boolean := False;

       task Blocker;

       task body Blocker is
       begin
           Sem_Ptr.Wait;
           Report.Failed ("Program_Error not raised in waiting task 2");
       exception
           when Program_Error =>
               Ok := True;
               if C940016_0.Finalization_Occurred then
                   Report.Failed ("wrong order for finalization 2");
               elsif Verbose then
                   Report.Comment ("Blocker received Program_Error 2");
               end if;
           when others =>
               Report.Failed ("Wrong exception in Blocker 2");
       end Blocker;

   begin  -- Second_Check
       -- wait for Blocker to get blocked on the semaphore
       delay ImpDef.Clear_Ready_Queue;
       Zap_Semaphore (Sem_Ptr);
       -- make sure Blocker has time to complete
       delay ImpDef.Clear_Ready_Queue * 2;
       if not Ok then
           Report.Failed ("finalization not properly performed 2");
           -- Blocker is probably hung so kill it
           abort Blocker;
       end if;
       if not C940016_0.Finalization_Occurred then
           Report.Failed ("user defined finalization didn't happen");
       end if;
   end Second_Check;
 

   Report.Result;
 
end C940016;
