 -- Semaphores;


          --========================================================--


package C940002_1 is
     -- Task_Pkg

  task type Requesting_Task is
     entry Done;                        -- call on Done instructs the task
  end Requesting_Task;                  -- to release resource

  type Task_Ptr is access Requesting_Task;

  protected Counter is
    procedure Increment;
    procedure Decrement;
    function Number return integer;
  private
    Count : Integer := 0;
  end Counter;

  protected Hold_Lock is
    procedure Lock;
    procedure Unlock;
    function  Locked return Boolean;
  private
    Lock_State  : Boolean := true;        -- starts out locked
  end Hold_Lock;


end C940002_1;
