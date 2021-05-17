

with Report;
package body C910003_Pack is

    protected body Buffer is
       entry Put (Item  : in Item_Type) when Empty is
       begin
           Empty := False;
           Saved_Item := Item;
           TC_Last := TC_Last + 1;
           TC_Items(TC_Last) := Item;
       end Put;

       entry Get (Item  : out Item_Type) when not Empty is
       begin
           Empty := True;
           Item := Saved_Item;
       end Get;

       function TC_Items_Buffered return Item_Array is
       begin
           return TC_Items(1..TC_Last);
       end TC_Items_Buffered;

    end Buffer;


    task body Producer is
        -- Produces PRODUCE_COUNT items. Starts when activated.
    begin
        for I in 1 .. Report.Ident_Int(PRODUCE_COUNT) loop
           Buffer_Access.Put (Start_At + (Item_Type(I)-1)*2);
        end loop;
    end Producer;


    task body Consumer is
        -- Stores PRODUCE_COUNT*2 items consumed in Results. Starts when
        -- activated.
    begin
        for I in 1 .. Report.Ident_Int(PRODUCE_COUNT*2) loop
            Buffer_Access.Get (Results (I));
            -- Buffer_Access and Results are both dereferenced.
        end loop;

        -- Check the results (and function call with a prefix dereference).
        if Results.all(Report.Ident_Int(1)) /= Buffer_Access.all.TC_Items_Buffered(Report.Ident_Int(1)) then
           Report.Failed ("First item mismatch");
        end if;
        if Results(Report.Ident_Int(2)) /= Buffer_Access.TC_Items_Buffered(Report.Ident_Int(2)) then
           Report.Failed ("Second item mismatch");
        end if;
        accept Wait_until_Done; -- Tell main that we're done.
    end Consumer;

end C910003_Pack;
