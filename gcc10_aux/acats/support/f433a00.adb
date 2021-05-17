
with Report;
with TcTouch;
package body F433A00 is

   protected body T_PO is
      entry Set (Value : in Integer) when True is
      begin
         Data := Value;
      end Set;
      procedure Get (Value : out Integer) is
      begin
         Value := Data;
      end Get;
   end T_PO;

   task body T_Task is
      Data : Integer := 0;
   begin
      accept Set (Value : in Integer) do
         Data := Value;
      end Set;
      accept Get (Value : out Integer) do
         Value := Data;
      end Get;
   end T_Task;

   Init_Count : Natural := 0;

   procedure Reset_Init is
   begin
      Init_Count := 0;
   end Reset_Init;

   function Init_Func (Value : in Integer := 4) return Integer is
   begin
      Init_Count := Init_Count + 1;
      return Report.Ident_Int(Value);
   end Init_Func;

   procedure Check_Init_Count (Expected : in Natural;
                               Message  : in String) is
   begin
       if Expected /= Init_Count then
          Report.Failed ("Init count wrong, expected" & Natural'Image(Expected) &
             ", but observed" & Natural'Image(Init_Count) & " for " & Message);
       end if;
   end Check_Init_Count;

   procedure Check (Item : in out My_Rec; Value : in Integer;
                    Message : in String) is
      Val : Integer;
   begin
      --  Check the protected object component
      Item.P.Set (Value => Value);
      Item.P.Get (Val);
      if Value /= Val then
         Report.Failed ("Wrong value for PO: " & Message);
      end if;

      --  Check the task component
      Item.T.Set (Value => Value);
      Item.T.Get (Val);
      if Value /= Val then
         Report.Failed ("Wrong value for Task: " & Message);
      end if;

      --  Check the limited record component
      if Item.Info.A /= Value then
         Report.Failed ("Wrong value for LimRec: " & Message);
      end if;

   end Check;

   procedure Initialize (Obj : in out Ctrl_Rec) is
   begin
      TCTouch.Touch( 'i' ); ----------------------------------------- i
   end Initialize;

end F433A00;


