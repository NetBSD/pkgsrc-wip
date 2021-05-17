

with Report;
with ImpDef;
with C930001_0;   use C930001_0;
procedure C930001 is
begin
 
    Report.Test ("C930001", "Check that dependent tasks are terminated" &
                            " before the remaining finalization");

    declare
        task Level_1;
        task body Level_1 is
            V1a : C930001_0.Has_Finalization;        -------> 4
            task Level_2 is
                entry Not_Taken;
            end Level_2;
            task body Level_2 is
                V2 : C930001_0.Has_Finalization;     -------> 2
            begin
                V2.Id := 2;
                C930001_0.Note.Done (1);             -------> 1
                select
                    accept Not_Taken;
                or
                    terminate;
                    -- cooperative termination at this point of
                    -- both tasks
                end select;
            end Level_2;

            -- 7.6.1(11) requires that V1b be finalized before V1a
            V1b : C930001_0.Has_Finalization;        -------> 3
        begin
            V1a.Id := 4;
            V1b.Id := 3;
        end Level_1;
    begin  -- declare
        while not Level_1'Terminated loop
             delay ImpDef.Switch_To_New_Task;
        end loop;
        C930001_0.Note.Done (5);                     -------> 5
        
        -- now check the order
        for I in Ids range 1..5 loop
            if Verbose then
                Report.Comment (Ids'Image (I) & 
                       Ids'Image (Finalization_Order (I)));
            end if;
            if Finalization_Order (I) /= I then
                Report.Failed ("Finalization occurred out of order" &
                   " expected:" &
                   Ids'Image (I) &
                   " actual:" &
                   Ids'Image (Finalization_Order (I)));
            end if;
        end loop;
    end;

    Report.Result;
end C930001;
