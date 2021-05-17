
----------------------------------------------------------

with ImpDef;
with Report;
package body CXD1008_0 is
    Verbose : constant Boolean := False;

    task Cyclic is
       pragma Priority (Task_Priority);
       entry Start;
       entry Stop;
    end Cyclic;

    task body Cyclic is
       -- allow drift in the periodic tasks - works better for this test
    begin
        accept Start;
        -- sit quietly until all the tasks have gotten started
        delay ImpDef.Clear_Ready_Queue;

        loop
            select
                accept Stop;
                exit;  -- out of task loop
            or
                delay Task_Period;
                -- if we get here then it is not time to stop
                Periodic_Activity (Task_Id);
            end select;
        end loop;
    end Cyclic;


    procedure Start is
    begin
        Cyclic.Start;
    end Start;

    procedure Stop is
    begin
        -- if the task is waiting then allow it to die gracefully.
        -- otherwise, kill it.
        select
            Cyclic.Stop;
            if Verbose then
                Report.Comment ("stop issued for" &
                                Integer'Image (Task_Id));
            end if;
        else
            abort Cyclic;
            if Verbose then
                Report.Comment ("abort issued for" &
                                Integer'Image (Task_Id));
            end if;
        end select;
    end Stop;
end CXD1008_0;
