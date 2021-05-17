 -- Semaphores;


          --========================================================--


package body C940002_0 is
          -- Semaphores

  protected body Semaphore_Type is

    entry Request when Currently_Available >0 is  -- when granted, secures
    begin                                         -- a resource
      Currently_Available := Currently_Available - 1;
    end Request;

    procedure Release is                          -- when called, releases
    begin                                         -- a resource
      Currently_Available := Currently_Available + 1;
    end Release;

    function Available return Integer is          -- returns number of
    begin                                         -- available resources
      return Currently_Available;
    end Available;

  end Semaphore_Type;

end C940002_0;
