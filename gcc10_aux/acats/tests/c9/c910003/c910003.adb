

with Report;
with C910003_Pack;

procedure C910003 is

begin -- C910003

   Report.Test ("C910003", "Check that tasks discriminants of access types can be dereferenced");


   declare     -- encapsulate the test

      Buffer_Access : C910003_Pack.Buffer_Access_Type :=
         new C910003_Pack.Buffer;

      TC_Results : C910003_Pack.TC_Item_Array_Access_Type :=
         new C910003_Pack.Item_Array (1 .. C910003_Pack.PRODUCE_COUNT*2);

      Producer_1 : C910003_Pack.Producer (Buffer_Access, 12);
      Producer_2 : C910003_Pack.Producer (Buffer_Access, 23);

      Consumer : C910003_Pack.Consumer (Buffer_Access, TC_Results);

      use type C910003_Pack.Item_Array; -- For /=.

   begin
      Consumer.Wait_until_Done;
      if TC_Results.all /= Buffer_Access.TC_Items_Buffered then
           Report.Failed ("Different items buffered than returned - Main");
      end if;
      if (TC_Results.all /= (12, 14, 23, 25) and
          TC_Results.all /= (12, 23, 14, 25) and
          TC_Results.all /= (12, 23, 25, 14) and
          TC_Results.all /= (23, 12, 14, 25) and
          TC_Results.all /= (23, 12, 25, 14) and
          TC_Results.all /= (23, 25, 12, 14)) then
          -- Above are the only legal results.
           Report.Failed ("Wrong results");
      end if;
   end;     -- encapsulation

   Report.Result;

end C910003;
