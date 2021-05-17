
----------------------------------------------------------

with Report;
package body CXD1008_1 is
    Verbose : constant Boolean := False;

    -- how many times must a computation be preempted before we
    -- will allow it to complete
    Desired_Preemptions : constant := 10;

    -- The purpose of the manager is to keep track of how many times
    -- a particular computation has been preempted.  This is done by
    -- having each computation register that it is starting.  Whenever
    -- a computation starts, it preempts anything running at a lower
    -- priority (or lower id).
    -- The condition for the termination of a computation depends upon
    -- the preemption count.
    -- The count of the number of tests started at each priority level
    -- is kept and used for determining when to terminate the test

    subtype Valid_Id is Integer range 1..7;
    type Counters is array (Valid_Id) of Natural;
    Test_Counts : Counters := (Valid_Id => 0);

    protected Manager is
        procedure Start (Id : Valid_Id);
        function Preemption_Count (Id : Valid_Id) return Natural;
        entry Test_Done;
    private
        Preemptions : Counters := (Valid_Id => 0); 
        Starts : Natural := 0;
    end Manager;

    protected body Manager is
       procedure Start (Id : Valid_Id) is
       begin
           for I in Valid_Id'First .. Id - 1 loop
               Preemptions (I) := Preemptions (I) + 1;
           end loop;
           Preemptions (Id) := 0;
           Test_Counts (Id) := Test_Counts (Id) + 1;
           -- only count the tests of each type that are below
           -- the highest priority for that type
           if Id <= Valid_Id'Last - 3 then
               Starts := Starts + 1;
           end if;
       end Start;

       function Preemption_Count (Id : Valid_Id) return Natural is
       begin
           return Preemptions (Id);
       end Preemption_Count;

       entry Test_Done when Starts > 50 is
       begin
           null;  -- just finish
       end Test_Done;
    end Manager;


    procedure Do_Float (Id : Integer) is
       -- hopefully, some of these variables will be allocated
       -- to registers.
       A, B, C, D, E, F : Float;
       -- two values that are the same as Id but not obvious to the compiler
       Id2 : Integer := Report.Ident_Int (Id);
       Id1 : Integer := Report.Ident_Int (Id);
    begin
       Manager.Start (Id);
       F := 1.0;
       while Manager.Preemption_Count (Id) < Desired_Preemptions loop
          A := Float (Id1) + F;
          B := Float (Id1 + 1);
          C := A ** Id1;
          D := B ** (- Id1) + F;
          E := F ** (Id1 + 3);

          if A /= Float (Id2) + F then
             Report.Failed ("Do_Float A = " & Float'Image (A) &
                            " for Id = " & Integer'Image (Id) &
                            " and F = " & Float'Image (F));
          end if;

          if B /= Float (Id2 + 1) then
             Report.Failed ("Do_Float B = " & Float'Image (B) &
                            " for Id = " & Integer'Image (Id) &
                            " and F = " & Float'Image (F));
          end if;

          if C /= A ** Id2 then
             Report.Failed ("Do_Float C = " & Float'Image (C) &
                            " for Id = " & Integer'Image (Id) &
                            " and F = " & Float'Image (F));
          end if;


          if E /= F ** (Id2 + 3)  then
             Report.Failed ("Do_Float E = " & Float'Image (E) &
                            " for Id = " & Integer'Image (Id) &
                            " and F = " & Float'Image (F));
          end if;

          -- optimization thwarting - make it look like the values
          -- computed in the loop might change.
          if Report.Ident_Bool (False) then
             F := F * 10.0;
             Id1 := Id1 + 2;
          end if;
       end loop;

    end Do_Float;


    procedure Do_Exceptions (Id : Integer) is
        Count : Integer := 0;
        My_Exception : exception;
        procedure Recurse (Levels : Integer) is
        begin
            if Levels > Report.Ident_Int (1) then
                Recurse (Levels - 1);
            else
                if Id < 4 then
                     -- note that constraint_error will be raised in
                     -- the following line (divide by 0)
                     Report.Comment ("shouldn't print" &
                                     Integer'Image (5 / Report.Ident_Int(0)));
                else
                     raise My_Exception;
                end if;
            end if;
        exception
           when others => 
               Count := Count + 1;
               raise;
        end Recurse;
    begin
        Manager.Start (Id);
        Recurse (Id);
        Report.Failed ("No exception for Id=" & Integer'Image (Id));
    exception
        when Constraint_Error | My_Exception =>
            if Id /= Count then
                Report.Failed ("Exception test  Id =" & Integer'Image (Id) &
                               " Count =" & Integer'Image (Count));
            end if;
        when others =>
            Report.Failed ("unexpected exception for Id=" & 
                           Integer'Image (Id));
    end Do_Exceptions;


    procedure Preemption (Id : Integer) is
    begin
       -- just note that everything running has been preempted.
       Manager.Start (Id); 
    end Preemption;


    procedure Wait_Till_Done is
    begin
        Manager.Test_Done;
        if Verbose then
            Report.Comment ("Id   Tests");
            for I in Valid_Id loop
                Report.Comment (Integer'Image (I) & "  " &
                                Integer'Image (Test_Counts (I)));
            end loop;
        end if;
    end Wait_Till_Done;
end CXD1008_1;
