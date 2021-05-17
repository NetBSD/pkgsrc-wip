 -- Task_Pkg


          --========================================================--


with Report;
with C940002_0;
  -- Semaphores;    

package body C940002_1 is
          -- Task_Pkg is
  
  protected body Counter is

    procedure Increment is
      begin
        Count := Count + 1;
      end Increment;

    procedure Decrement is
      begin
        Count := Count - 1;
      end Decrement;

    function Number return Integer is
      begin
        return Count;
      end Number;

  end Counter;


  protected body Hold_Lock is

    procedure Lock is 
    begin
      Lock_State := true;
    end Lock;

    procedure Unlock is 
    begin
      Lock_State := false;
    end Unlock;

    function  Locked return Boolean is 
    begin
      return Lock_State;
    end Locked;

  end Hold_Lock;


  task body Requesting_Task is
  begin
    C940002_0.Resource.Request;        -- request a resource
                                       -- if resource is not available, 
                                       -- task will be queued to wait
    Counter.Increment;                 -- add to count of resources obtained
    Hold_Lock.Unlock;                  -- and unlock Lock - system is stable;
                                       -- status may now be queried

    accept Done do                     -- hold resource until Done is called
      C940002_0.Resource.Release;      -- release the resource and
      Counter.Decrement;               -- note release
    end Done;                           

  exception
    when others => Report.Failed ("Unexpected Exception in Requesting_Task");
  end Requesting_Task;

end C940002_1;
