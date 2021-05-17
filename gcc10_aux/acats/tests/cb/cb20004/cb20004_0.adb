
     --=================================================================--

with Report;

package body CB20004_0 is               -- Package Buffer.

   protected body Bounded_Buffer is

      entry Put (Item : in Data_Item) when Count < Max_Buffer_Size is
      begin
         if Item > 10 then
            Item_Array (I) := Item * 8;  -- Constraint_Error will be raised
         elsif Item > 5 then             -- and handled in entry body.
            raise Data_Over_5;           -- Exception  handled/reraised in
         else                            -- entry body, propagated to caller.
            Item_Array (I) := Item;      -- Store data item in buffer.
            I := (I mod Max_Buffer_Size) + 1;
            Count := Count + 1;
         end if;
      exception
         when Constraint_Error =>
            Handled_In_Body := True;
         when Data_Over_5 =>
            Propagated_To_Caller := True;
            raise;    -- Propagate the exception to the caller.
      end Put;


      entry Get (Item : out Data_Item) when Count > 0 is
      begin
         Item := Item_Array(J);
         J := (J mod Max_Buffer_Size) + 1;
         Count := Count - 1;
         if Count = 0 then
            raise Data_Degradation;   -- Exception to propagate to caller.
         end if;
      end Get;

   end Bounded_Buffer;

end CB20004_0;
