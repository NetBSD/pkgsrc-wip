

with TcTouch;
package body C940017_B is

   protected body Single_w_Exceptions is
      procedure Enqueue (Item : in Integer) is
      begin
         if In_Use then
            raise Full_Error;
         end if;
         In_Use := True;
         Stored_Item := Item;
         TCTouch.Touch ('E'); -------------------------------------------- E
      end Enqueue;

      procedure Dequeue (Item : out Integer) is
      begin
         if not In_Use then
            raise Empty_Error;
         end if;
         In_Use := False;
         Item := Stored_Item;
         TCTouch.Touch ('D'); -------------------------------------------- D
      end Dequeue;

      function Item_Count return Natural is
      begin
         TCTouch.Touch ('C'); -------------------------------------------- C
         if In_Use then
            return 1;
         else
            return 0;
         end if;
      end Item_Count;

   end Single_w_Exceptions;


   protected body Quad_w_Blocking is
      entry Enqueue (Item : in Integer) when Count < Stored'Last is
      begin
         Count := Count + 1;
         Stored(Count) := Item;
         TCTouch.Touch ('e'); -------------------------------------------- e
      end Enqueue;

      entry Dequeue (Item : out Integer) when Count > 0 is
      begin
         Item := Stored(1);
         Stored(1..3) := Stored(2..4);
         Count := Count - 1;
         TCTouch.Touch ('d'); -------------------------------------------- d
      end Dequeue;

      function Item_Count return Natural is
      begin
         TCTouch.Touch ('c'); -------------------------------------------- c
         return Count;
      end Item_Count;

   end Quad_w_Blocking;

end C940017_B;
