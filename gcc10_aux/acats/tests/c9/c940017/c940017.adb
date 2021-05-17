
with Report;
with TcTouch;
with C940017_A;
with C940017_B;
procedure C940017 is

   S : C940017_B.Single_w_Exceptions;
   Q : C940017_B.Quad_w_Blocking;

   procedure Munge (A_Queue : in out C940017_A.Queue_Interface'Class;
                    An_Item : in Integer;
                    Code : in String) is
      Org_Count : Natural := A_Queue.Item_Count;
      Temp_Item : Integer;
   begin
      A_Queue.Enqueue (An_Item);
      if Org_Count + 1 /= A_Queue.Item_Count then
         Report.Failed ("Wrong queue count after enqueue - " & Code);
      end if;
      A_Queue.Dequeue (Temp_Item);
      if Org_Count = 0 then
         if Temp_Item /= An_Item then
            Report.Failed ("Wrong item from dequeue - " & Code);
         end if;
         if Org_Count /= A_Queue.Item_Count then
            Report.Failed ("Wrong queue count after munging (0) - " & Code);
         end if;
      elsif Org_Count = 1 then
         A_Queue.Dequeue (Temp_Item);
         if Temp_Item /= An_Item then
            Report.Failed ("Wrong item from dequeue (2) - " & Code);
         end if;
         if A_Queue.Item_Count /= 0 then
            Report.Failed ("Wrong queue count after munging (1) - " & Code);
         end if;
      else -- don't know what to expect.
         if Org_Count /= A_Queue.Item_Count then
            Report.Failed ("Wrong queue count after munging (2) - " & Code);
         end if;
      end if;
   end Munge;

begin

   Report.Test
     ("C940017",
      "Check that dispatching calls can be made for subprograms inherited " &
      "from a progenator for a protected type and implemented by protected " &
      "operations of the type");

   if S.Item_Count /= 0 then
      Report.Failed ("Wrong initial count (S)");
   end if;
   if Q.Item_Count /= 0 then
      Report.Failed ("Wrong initial count (Q)");
   end if;
   Q.Enqueue (4);

   TcTouch.Validate (Expected => "Cce",
                     Message => "Wrong initialization (1)");

   Munge (S, 12, Code => "(2)");

   TcTouch.Validate (Expected => "CECDC",
                     Message => "Wrong routines called (2)");

   Munge (Q, 92, Code => "(3)");

   TcTouch.Validate (Expected => "cecddc",
                     Message => "Wrong routines called (3)");

   if S.Item_Count /= 0 then
      Report.Failed ("Wrong final count (S)");
   end if;
   if Q.Item_Count /= 0 then
      Report.Failed ("Wrong final count (Q)");
   end if;
   TcTouch.Validate (Expected => "Cc",
                     Message => "Wrong initialization (4)");


   Report.Result;

end C940017;
